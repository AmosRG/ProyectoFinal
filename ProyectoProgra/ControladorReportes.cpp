#include "ControladorReportes.h"

using namespace ProyectoProgra;

ControladorReportes::ControladorReportes() {
	db = gcnew dbConexion();
}

DataTable^ ControladorReportes::ejecutarDataTable(MySqlCommand^ comando) {
	DataTable^ tabla = gcnew DataTable();

	try {
		MySqlConnection^ conexion = db->getConexion();

		if (conexion == nullptr) {
			MessageBox::Show("No se pudo conectar a la base de datos.");
			return tabla;
		}

		comando->Connection = conexion;

		MySqlDataAdapter^ adaptador = gcnew MySqlDataAdapter(comando);
		adaptador->Fill(tabla);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al generar reporte: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

DataTable^ ControladorReportes::generarReporte(
	String^ tipoReporte,
	DateTime fechaInicio,
	DateTime fechaFin
) {
	if (String::IsNullOrWhiteSpace(tipoReporte)) {
		return gcnew DataTable();
	}

	String^ tipo = tipoReporte->ToUpper();

	if (tipo->Contains("VENTAS RESUMEN")) {
		return reporteVentasResumen(fechaInicio, fechaFin);
	}
	else if (tipo->Contains("VENTAS DETALLE")) {
		return reporteVentasDetalle(fechaInicio, fechaFin);
	}
	else if (tipo->Contains("INVENTARIO ACTUAL")) {
		return reporteInventarioActual();
	}
	else if (tipo->Contains("MOVIMIENTOS")) {
		return reporteMovimientosInventario(fechaInicio, fechaFin);
	}
	else if (tipo->Contains("TANQUES BAJO")) {
		return reporteTanquesBajoMinimo();
	}

	return gcnew DataTable();
}

DataTable^ ControladorReportes::reporteVentasResumen(
	DateTime fechaInicio,
	DateTime fechaFin
) {
	String^ sql =
		"SELECT "
		"DATE(v.fecha_venta) AS Fecha, "
		"COUNT(DISTINCT v.id_venta) AS CantidadVentas, "
		"SUM(d.cantidad_galones) AS TotalGalones, "
		"SUM(d.subtotal) AS Subtotal, "
		"SUM(d.descuento) AS Descuento, "
		"SUM(v.total_venta) AS TotalVenta "
		"FROM tbl_venta v "
		"INNER JOIN tbl_detalle_venta d ON v.id_venta = d.id_venta "
		"WHERE v.fecha_venta >= @fechaInicio "
		"AND v.fecha_venta < @fechaFin "
		"GROUP BY DATE(v.fecha_venta) "
		"ORDER BY DATE(v.fecha_venta) DESC";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);
	cmd->Parameters->AddWithValue("@fechaInicio", fechaInicio.Date);
	cmd->Parameters->AddWithValue("@fechaFin", fechaFin.Date.AddDays(1));

	return ejecutarDataTable(cmd);
}

DataTable^ ControladorReportes::reporteVentasDetalle(
	DateTime fechaInicio,
	DateTime fechaFin
) {
	String^ sql =
		"SELECT "
		"v.id_venta AS NoVenta, "
		"v.fecha_venta AS Fecha, "
		"CONCAT('Bomba ', b.numero_bomba) AS Bomba, "
		"c.nombre_combustible AS Combustible, "
		"d.cantidad_galones AS Galones, "
		"d.precio_unitario AS PrecioUnitario, "
		"d.subtotal AS Subtotal, "
		"d.descuento AS Descuento, "
		"d.total_detalle AS TotalDetalle, "
		"ue.nombre AS Empleado, "
		"COALESCE(uc.nombre, 'Consumidor final') AS Cliente "
		"FROM tbl_venta v "
		"INNER JOIN tbl_detalle_venta d ON v.id_venta = d.id_venta "
		"INNER JOIN tbl_bomba b ON v.id_bomba = b.id_bomba "
		"INNER JOIN tbl_combustible c ON d.id_combustible = c.id_combustible "
		"INNER JOIN tbl_empleado e ON v.id_empleado = e.id_empleado "
		"INNER JOIN tbl_usuario ue ON e.id_usuario = ue.id_usuario "
		"LEFT JOIN tbl_cliente cl ON v.id_cliente = cl.id_cliente "
		"LEFT JOIN tbl_usuario uc ON cl.id_usuario = uc.id_usuario "
		"WHERE v.fecha_venta >= @fechaInicio "
		"AND v.fecha_venta < @fechaFin "
		"ORDER BY v.fecha_venta DESC";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);
	cmd->Parameters->AddWithValue("@fechaInicio", fechaInicio.Date);
	cmd->Parameters->AddWithValue("@fechaFin", fechaFin.Date.AddDays(1));

	return ejecutarDataTable(cmd);
}

DataTable^ ControladorReportes::reporteInventarioActual() {
	String^ sql =
		"SELECT "
		"t.id_tanque AS ID, "
		"t.nombre_tanque AS Tanque, "
		"c.nombre_combustible AS Combustible, "
		"t.capacidad_tanque AS Capacidad, "
		"t.nivel_actual AS NivelActual, "
		"t.nivel_minimo AS NivelMinimo, "
		"CASE "
		"WHEN t.nivel_actual <= t.nivel_minimo THEN 'BAJO MINIMO' "
		"WHEN t.nivel_actual >= t.capacidad_tanque THEN 'LLENO' "
		"ELSE 'NORMAL' "
		"END AS EstadoNivel, "
		"CASE WHEN t.estado_tanque = 1 THEN 'Activo' ELSE 'Inactivo' END AS EstadoTanque "
		"FROM tbl_tanque t "
		"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
		"ORDER BY t.nombre_tanque ASC";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);

	return ejecutarDataTable(cmd);
}

DataTable^ ControladorReportes::reporteMovimientosInventario(
	DateTime fechaInicio,
	DateTime fechaFin
) {
	String^ sql =
		"SELECT "
		"m.id_movimiento AS ID, "
		"m.fecha_movimiento AS Fecha, "
		"m.tipo_movimiento AS Tipo, "
		"m.cantidad AS Cantidad, "
		"m.descripcion_movimiento AS Descripcion, "
		"t.nombre_tanque AS Tanque, "
		"c.nombre_combustible AS Combustible, "
		"u.nombre AS Usuario "
		"FROM tbl_movimiento_inventario m "
		"INNER JOIN tbl_tanque t ON m.id_tanque = t.id_tanque "
		"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
		"INNER JOIN tbl_usuario u ON m.id_usuario = u.id_usuario "
		"WHERE m.fecha_movimiento >= @fechaInicio "
		"AND m.fecha_movimiento < @fechaFin "
		"ORDER BY m.fecha_movimiento DESC";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);
	cmd->Parameters->AddWithValue("@fechaInicio", fechaInicio.Date);
	cmd->Parameters->AddWithValue("@fechaFin", fechaFin.Date.AddDays(1));

	return ejecutarDataTable(cmd);
}

DataTable^ ControladorReportes::reporteTanquesBajoMinimo() {
	String^ sql =
		"SELECT "
		"t.id_tanque AS ID, "
		"t.nombre_tanque AS Tanque, "
		"c.nombre_combustible AS Combustible, "
		"t.capacidad_tanque AS Capacidad, "
		"t.nivel_actual AS NivelActual, "
		"t.nivel_minimo AS NivelMinimo, "
		"(t.nivel_minimo - t.nivel_actual) AS Diferencia, "
		"CASE WHEN t.estado_tanque = 1 THEN 'Activo' ELSE 'Inactivo' END AS EstadoTanque "
		"FROM tbl_tanque t "
		"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
		"WHERE t.nivel_actual <= t.nivel_minimo "
		"ORDER BY t.nivel_actual ASC";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql);

	return ejecutarDataTable(cmd);
}

String^ ControladorReportes::obtenerResumenReporte(
	String^ tipoReporte,
	DataTable^ tabla
) {
	if (tabla == nullptr) {
		return "Registros encontrados: 0";
	}

	int registros = tabla->Rows->Count;

	if (registros == 0) {
		return "Registros encontrados: 0";
	}

	String^ tipo = tipoReporte->ToUpper();

	if (tipo->Contains("VENTAS")) {
		double total = 0;
		double galones = 0;

		for each (DataRow ^ fila in tabla->Rows) {
			if (tabla->Columns->Contains("TotalVenta") && fila["TotalVenta"] != DBNull::Value) {
				total += Convert::ToDouble(fila["TotalVenta"]);
			}
			else if (tabla->Columns->Contains("TotalDetalle") && fila["TotalDetalle"] != DBNull::Value) {
				total += Convert::ToDouble(fila["TotalDetalle"]);
			}

			if (tabla->Columns->Contains("TotalGalones") && fila["TotalGalones"] != DBNull::Value) {
				galones += Convert::ToDouble(fila["TotalGalones"]);
			}
			else if (tabla->Columns->Contains("Galones") && fila["Galones"] != DBNull::Value) {
				galones += Convert::ToDouble(fila["Galones"]);
			}
		}

		return "Registros: " + registros +
			" | Galones: " + galones.ToString("N2") +
			" | Total: Q " + total.ToString("N2");
	}

	if (tipo->Contains("MOVIMIENTOS")) {
		double cantidad = 0;

		for each (DataRow ^ fila in tabla->Rows) {
			if (tabla->Columns->Contains("Cantidad") && fila["Cantidad"] != DBNull::Value) {
				cantidad += Convert::ToDouble(fila["Cantidad"]);
			}
		}

		return "Registros: " + registros +
			" | Cantidad total: " + cantidad.ToString("N2");
	}

	return "Registros encontrados: " + registros;
}