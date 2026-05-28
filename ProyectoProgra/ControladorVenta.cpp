#include "ControladorVenta.h"

using namespace ProyectoProgra;

ControladorVenta::ControladorVenta() {
	db = gcnew dbConexion();
}

double ControladorVenta::calcularDescuentoInterno(String^ tipoDescuento, double valorDescuento, double subtotal) {

	if (String::IsNullOrWhiteSpace(tipoDescuento) || valorDescuento <= 0) {
		return 0;
	}

	String^ tipo = tipoDescuento->ToUpper();

	double descuento = 0;

	if (tipo->Contains("POR") || tipo->Contains("%")) {
		descuento = subtotal * (valorDescuento / 100.0);
	}
	else {
		descuento = valorDescuento;
	}

	if (descuento > subtotal) {
		descuento = subtotal;
	}

	return descuento;
}

DataTable^ ControladorVenta::listarBombasActivas() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT b.id_bomba, "
			"CONCAT('Bomba ', b.numero_bomba, ' - ', c.nombre_combustible, ' - Nivel: ', t.nivel_actual) AS descripcion_bomba "
			"FROM tbl_bomba b "
			"INNER JOIN tbl_tanque t ON b.id_tanque = t.id_tanque "
			"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
			"WHERE b.estado_bomba = 1 "
			"AND t.estado_tanque = 1 "
			"AND c.estado_combustible = 1 "
			"ORDER BY b.numero_bomba ASC";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al cargar bombas: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

DataTable^ ControladorVenta::listarVentasRecientes() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT v.id_venta AS ID, "
			"v.fecha_venta AS Fecha, "
			"CONCAT('Bomba ', b.numero_bomba) AS Bomba, "
			"ue.nombre AS Empleado, "
			"COALESCE(uc.nombre, 'Consumidor final') AS Cliente, "
			"v.total_venta AS Total "
			"FROM tbl_venta v "
			"INNER JOIN tbl_bomba b ON v.id_bomba = b.id_bomba "
			"INNER JOIN tbl_empleado e ON v.id_empleado = e.id_empleado "
			"INNER JOIN tbl_usuario ue ON e.id_usuario = ue.id_usuario "
			"LEFT JOIN tbl_cliente cl ON v.id_cliente = cl.id_cliente "
			"LEFT JOIN tbl_usuario uc ON cl.id_usuario = uc.id_usuario "
			"ORDER BY v.fecha_venta DESC "
			"LIMIT 30";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al cargar ventas recientes: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

ClienteVenta^ ControladorVenta::buscarClientePorNit(String^ nit, String^% mensaje) {

	MySqlDataReader^ reader = nullptr;

	try {
		if (String::IsNullOrWhiteSpace(nit)) {
			ClienteVenta^ consumidorFinal = gcnew ClienteVenta();
			mensaje = "Venta registrada como consumidor final.";
			return consumidorFinal;
		}

		MySqlConnection^ conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return nullptr;
		}

		String^ sql =
			"SELECT c.id_cliente, c.nit, u.nombre "
			"FROM tbl_cliente c "
			"INNER JOIN tbl_usuario u ON c.id_usuario = u.id_usuario "
			"WHERE c.nit = @nit "
			"LIMIT 1";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, conexion);
		cmd->Parameters->AddWithValue("@nit", nit);

		reader = cmd->ExecuteReader();

		if (reader->Read()) {
			ClienteVenta^ cliente = gcnew ClienteVenta();

			cliente->idCliente = reader->GetInt32(reader->GetOrdinal("id_cliente"));
			cliente->nit = reader->GetString(reader->GetOrdinal("nit"));
			cliente->nombreCliente = reader->GetString(reader->GetOrdinal("nombre"));

			reader->Close();
			db->cerrarConexion();

			mensaje = "Cliente encontrado.";
			return cliente;
		}

		reader->Close();
		db->cerrarConexion();

		ClienteVenta^ clienteFinal = gcnew ClienteVenta();
		mensaje = "No se encontro cliente con ese NIT. Se usara consumidor final.";
		return clienteFinal;
	}
	catch (Exception^ ex) {

		if (reader != nullptr && !reader->IsClosed) {
			reader->Close();
		}

		db->cerrarConexion();

		mensaje = "Error al buscar cliente: " + ex->Message;
		return nullptr;
	}
}

VentaCalculo^ ControladorVenta::calcularVenta(int idBomba, double cantidadGalones, String^% mensaje) {

	MySqlDataReader^ reader = nullptr;

	try {
		if (idBomba <= 0) {
			mensaje = "Debe seleccionar una bomba.";
			return nullptr;
		}

		if (cantidadGalones <= 0) {
			mensaje = "La cantidad de galones debe ser mayor a cero.";
			return nullptr;
		}

		MySqlConnection^ conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return nullptr;
		}

		String^ sqlDatos =
			"SELECT b.id_bomba, b.numero_bomba, "
			"t.id_tanque, t.nivel_actual, "
			"c.id_combustible, c.nombre_combustible, c.precio_galon "
			"FROM tbl_bomba b "
			"INNER JOIN tbl_tanque t ON b.id_tanque = t.id_tanque "
			"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
			"WHERE b.id_bomba = @idBomba "
			"AND b.estado_bomba = 1 "
			"AND t.estado_tanque = 1 "
			"AND c.estado_combustible = 1 "
			"LIMIT 1";

		MySqlCommand^ cmdDatos = gcnew MySqlCommand(sqlDatos, conexion);
		cmdDatos->Parameters->AddWithValue("@idBomba", idBomba);

		reader = cmdDatos->ExecuteReader();

		if (!reader->Read()) {
			reader->Close();
			db->cerrarConexion();

			mensaje = "La bomba seleccionada no esta disponible.";
			return nullptr;
		}

		VentaCalculo^ calculo = gcnew VentaCalculo();

		calculo->idBomba = reader->GetInt32(reader->GetOrdinal("id_bomba"));
		calculo->numeroBomba = reader->GetInt32(reader->GetOrdinal("numero_bomba"));
		calculo->idTanque = reader->GetInt32(reader->GetOrdinal("id_tanque"));
		calculo->nivelActual = Convert::ToDouble(reader["nivel_actual"]);
		calculo->idCombustible = reader->GetInt32(reader->GetOrdinal("id_combustible"));
		calculo->nombreCombustible = reader->GetString(reader->GetOrdinal("nombre_combustible"));
		calculo->precioUnitario = Convert::ToDouble(reader["precio_galon"]);
		calculo->cantidadGalones = cantidadGalones;

		reader->Close();

		if (cantidadGalones > calculo->nivelActual) {
			db->cerrarConexion();
			mensaje = "No hay suficiente combustible en el tanque.";
			return nullptr;
		}

		calculo->subtotal = calculo->cantidadGalones * calculo->precioUnitario;

		String^ sqlOferta =
			"SELECT id_oferta, nombre_oferta, tipo_descuento, valor_descuento "
			"FROM tbl_oferta "
			"WHERE id_combustible = @idCombustible "
			"AND estado_oferta = 1 "
			"AND NOW() BETWEEN fecha_inicio AND fecha_fin "
			"ORDER BY valor_descuento DESC "
			"LIMIT 1";

		MySqlCommand^ cmdOferta = gcnew MySqlCommand(sqlOferta, conexion);
		cmdOferta->Parameters->AddWithValue("@idCombustible", calculo->idCombustible);

		reader = cmdOferta->ExecuteReader();

		if (reader->Read()) {
			calculo->idOferta = reader->GetInt32(reader->GetOrdinal("id_oferta"));
			calculo->nombreOferta = reader->GetString(reader->GetOrdinal("nombre_oferta"));

			String^ tipoDescuento = reader->GetString(reader->GetOrdinal("tipo_descuento"));
			double valorDescuento = Convert::ToDouble(reader["valor_descuento"]);

			calculo->descuento = calcularDescuentoInterno(tipoDescuento, valorDescuento, calculo->subtotal);
		}

		reader->Close();
		db->cerrarConexion();

		calculo->total = calculo->subtotal - calculo->descuento;

		if (calculo->total < 0) {
			calculo->total = 0;
		}

		mensaje = "Calculo generado correctamente.";
		return calculo;
	}
	catch (Exception^ ex) {

		if (reader != nullptr && !reader->IsClosed) {
			reader->Close();
		}

		db->cerrarConexion();

		mensaje = "Error al calcular venta: " + ex->Message;
		return nullptr;
	}
}

bool ControladorVenta::registrarVenta(
	int idBomba,
	double cantidadGalones,
	int idUsuario,
	int idCliente,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;
	MySqlTransaction^ transaccion = nullptr;
	MySqlDataReader^ reader = nullptr;

	try {
		if (idBomba <= 0) {
			mensaje = "Debe seleccionar una bomba.";
			return false;
		}

		if (cantidadGalones <= 0) {
			mensaje = "La cantidad de galones debe ser mayor a cero.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		transaccion = conexion->BeginTransaction();

		String^ sqlEmpleado =
			"SELECT id_empleado "
			"FROM tbl_empleado "
			"WHERE id_usuario = @idUsuario "
			"LIMIT 1";

		MySqlCommand^ cmdEmpleado = gcnew MySqlCommand(sqlEmpleado, conexion, transaccion);
		cmdEmpleado->Parameters->AddWithValue("@idUsuario", idUsuario);

		Object^ resultadoEmpleado = cmdEmpleado->ExecuteScalar();

		if (resultadoEmpleado == nullptr) {
			transaccion->Rollback();
			mensaje = "El usuario logueado no esta asociado a un empleado.";
			return false;
		}

		int idEmpleado = Convert::ToInt32(resultadoEmpleado);

		String^ sqlDatos =
			"SELECT b.id_bomba, b.numero_bomba, "
			"t.id_tanque, t.nivel_actual, "
			"c.id_combustible, c.nombre_combustible, c.precio_galon "
			"FROM tbl_bomba b "
			"INNER JOIN tbl_tanque t ON b.id_tanque = t.id_tanque "
			"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
			"WHERE b.id_bomba = @idBomba "
			"AND b.estado_bomba = 1 "
			"AND t.estado_tanque = 1 "
			"AND c.estado_combustible = 1 "
			"LIMIT 1 "
			"FOR UPDATE";

		MySqlCommand^ cmdDatos = gcnew MySqlCommand(sqlDatos, conexion, transaccion);
		cmdDatos->Parameters->AddWithValue("@idBomba", idBomba);

		reader = cmdDatos->ExecuteReader();

		if (!reader->Read()) {
			reader->Close();
			transaccion->Rollback();
			mensaje = "La bomba seleccionada no esta disponible.";
			return false;
		}

		int idTanque = reader->GetInt32(reader->GetOrdinal("id_tanque"));
		int idCombustible = reader->GetInt32(reader->GetOrdinal("id_combustible"));
		double nivelActual = Convert::ToDouble(reader["nivel_actual"]);
		double precioUnitario = Convert::ToDouble(reader["precio_galon"]);

		reader->Close();

		if (cantidadGalones > nivelActual) {
			transaccion->Rollback();
			mensaje = "No hay suficiente combustible en el tanque.";
			return false;
		}

		double subtotal = cantidadGalones * precioUnitario;
		double descuento = 0;
		double total = 0;
		int idOferta = 0;

		String^ sqlOferta =
			"SELECT id_oferta, tipo_descuento, valor_descuento "
			"FROM tbl_oferta "
			"WHERE id_combustible = @idCombustible "
			"AND estado_oferta = 1 "
			"AND NOW() BETWEEN fecha_inicio AND fecha_fin "
			"ORDER BY valor_descuento DESC "
			"LIMIT 1";

		MySqlCommand^ cmdOferta = gcnew MySqlCommand(sqlOferta, conexion, transaccion);
		cmdOferta->Parameters->AddWithValue("@idCombustible", idCombustible);

		reader = cmdOferta->ExecuteReader();

		if (reader->Read()) {
			idOferta = reader->GetInt32(reader->GetOrdinal("id_oferta"));

			String^ tipoDescuento = reader->GetString(reader->GetOrdinal("tipo_descuento"));
			double valorDescuento = Convert::ToDouble(reader["valor_descuento"]);

			descuento = calcularDescuentoInterno(tipoDescuento, valorDescuento, subtotal);
		}

		reader->Close();

		total = subtotal - descuento;

		if (total < 0) {
			total = 0;
		}

		String^ sqlVenta =
			"INSERT INTO tbl_venta "
			"(total_venta, id_bomba, id_empleado, id_cliente) "
			"VALUES "
			"(@totalVenta, @idBomba, @idEmpleado, @idCliente)";

		MySqlCommand^ cmdVenta = gcnew MySqlCommand(sqlVenta, conexion, transaccion);
		cmdVenta->Parameters->AddWithValue("@totalVenta", total);
		cmdVenta->Parameters->AddWithValue("@idBomba", idBomba);
		cmdVenta->Parameters->AddWithValue("@idEmpleado", idEmpleado);

		if (idCliente > 0) {
			cmdVenta->Parameters->AddWithValue("@idCliente", idCliente);
		}
		else {
			cmdVenta->Parameters->AddWithValue("@idCliente", DBNull::Value);
		}

		cmdVenta->ExecuteNonQuery();

		MySqlCommand^ cmdUltimaVenta = gcnew MySqlCommand("SELECT LAST_INSERT_ID()", conexion, transaccion);
		int idVenta = Convert::ToInt32(cmdUltimaVenta->ExecuteScalar());

		String^ sqlDetalle =
			"INSERT INTO tbl_detalle_venta "
			"(cantidad_galones, precio_unitario, subtotal, descuento, total_detalle, id_venta, id_combustible, id_oferta) "
			"VALUES "
			"(@cantidad, @precio, @subtotal, @descuento, @totalDetalle, @idVenta, @idCombustible, @idOferta)";

		MySqlCommand^ cmdDetalle = gcnew MySqlCommand(sqlDetalle, conexion, transaccion);
		cmdDetalle->Parameters->AddWithValue("@cantidad", cantidadGalones);
		cmdDetalle->Parameters->AddWithValue("@precio", precioUnitario);
		cmdDetalle->Parameters->AddWithValue("@subtotal", subtotal);
		cmdDetalle->Parameters->AddWithValue("@descuento", descuento);
		cmdDetalle->Parameters->AddWithValue("@totalDetalle", total);
		cmdDetalle->Parameters->AddWithValue("@idVenta", idVenta);
		cmdDetalle->Parameters->AddWithValue("@idCombustible", idCombustible);

		if (idOferta > 0) {
			cmdDetalle->Parameters->AddWithValue("@idOferta", idOferta);
		}
		else {
			cmdDetalle->Parameters->AddWithValue("@idOferta", DBNull::Value);
		}

		cmdDetalle->ExecuteNonQuery();

		String^ sqlActualizarTanque =
			"UPDATE tbl_tanque "
			"SET nivel_actual = nivel_actual - @cantidad "
			"WHERE id_tanque = @idTanque";

		MySqlCommand^ cmdActualizarTanque = gcnew MySqlCommand(sqlActualizarTanque, conexion, transaccion);
		cmdActualizarTanque->Parameters->AddWithValue("@cantidad", cantidadGalones);
		cmdActualizarTanque->Parameters->AddWithValue("@idTanque", idTanque);
		cmdActualizarTanque->ExecuteNonQuery();

		String^ sqlMovimiento =
			"INSERT INTO tbl_movimiento_inventario "
			"(tipo_movimiento, cantidad, descripcion_movimiento, id_tanque, id_usuario) "
			"VALUES "
			"('SALIDA', @cantidad, @descripcion, @idTanque, @idUsuario)";

		MySqlCommand^ cmdMovimiento = gcnew MySqlCommand(sqlMovimiento, conexion, transaccion);
		cmdMovimiento->Parameters->AddWithValue("@cantidad", cantidadGalones);
		cmdMovimiento->Parameters->AddWithValue("@descripcion", "Salida generada por venta No. " + Convert::ToString(idVenta));
		cmdMovimiento->Parameters->AddWithValue("@idTanque", idTanque);
		cmdMovimiento->Parameters->AddWithValue("@idUsuario", idUsuario);
		cmdMovimiento->ExecuteNonQuery();

		transaccion->Commit();

		mensaje = "Venta registrada correctamente. Total: Q " + total.ToString("N2");
		return true;
	}
	catch (Exception^ ex) {

		if (reader != nullptr && !reader->IsClosed) {
			reader->Close();
		}

		if (transaccion != nullptr) {
			try {
				transaccion->Rollback();
			}
			catch (Exception^) {
			}
		}

		mensaje = "Error al registrar venta: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}