#include "ControladorInventario.h"

using namespace ProyectoProgra;

ControladorInventario::ControladorInventario() {
	db = gcnew dbConexion();
}

DataTable^ ControladorInventario::listarTanquesActivos() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT "
			"t.id_tanque, "
			"CONCAT(t.nombre_tanque, ' - ', c.nombre_combustible, ' - Nivel: ', t.nivel_actual) AS descripcion_tanque "
			"FROM tbl_tanque t "
			"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
			"WHERE t.estado_tanque = 1 "
			"AND c.estado_combustible = 1 "
			"ORDER BY t.nombre_tanque ASC";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al cargar tanques: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

DataTable^ ControladorInventario::listarMovimientos() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT "
			"m.id_movimiento AS ID, "
			"m.fecha_movimiento AS Fecha, "
			"m.tipo_movimiento AS Tipo, "
			"m.cantidad AS Cantidad, "
			"m.descripcion_movimiento AS Descripcion, "
			"t.id_tanque AS IdTanque, "
			"t.nombre_tanque AS Tanque, "
			"c.nombre_combustible AS Combustible, "
			"u.nombre AS Usuario "
			"FROM tbl_movimiento_inventario m "
			"INNER JOIN tbl_tanque t ON m.id_tanque = t.id_tanque "
			"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
			"INNER JOIN tbl_usuario u ON m.id_usuario = u.id_usuario "
			"ORDER BY m.fecha_movimiento DESC "
			"LIMIT 100";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al listar movimientos: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

double ControladorInventario::obtenerNivelActualTanque(int idTanque) {
	MySqlDataReader^ reader = nullptr;

	try {
		if (idTanque <= 0) {
			return 0;
		}

		MySqlConnection^ conexion = db->getConexion();

		if (conexion == nullptr) {
			return 0;
		}

		String^ sql =
			"SELECT nivel_actual "
			"FROM tbl_tanque "
			"WHERE id_tanque = @idTanque "
			"LIMIT 1";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, conexion);
		cmd->Parameters->AddWithValue("@idTanque", idTanque);

		reader = cmd->ExecuteReader();

		if (reader->Read()) {
			double nivel = Convert::ToDouble(reader["nivel_actual"]);

			reader->Close();
			db->cerrarConexion();

			return nivel;
		}

		reader->Close();
		db->cerrarConexion();

		return 0;
	}
	catch (Exception^ ex) {
		if (reader != nullptr && !reader->IsClosed) {
			reader->Close();
		}

		db->cerrarConexion();

		MessageBox::Show("Error al obtener nivel del tanque: " + ex->Message);
		return 0;
	}
}

bool ControladorInventario::registrarMovimiento(
	MovimientoInventarioSistema^ movimiento,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;
	MySqlTransaction^ transaccion = nullptr;
	MySqlDataReader^ reader = nullptr;

	try {
		if (movimiento == nullptr) {
			mensaje = "No hay datos del movimiento.";
			return false;
		}

		if (movimiento->idTanque <= 0) {
			mensaje = "Debe seleccionar un tanque.";
			return false;
		}

		if (movimiento->idUsuario <= 0) {
			mensaje = "No existe usuario logueado.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(movimiento->tipoMovimiento)) {
			mensaje = "Debe seleccionar el tipo de movimiento.";
			return false;
		}

		if (movimiento->cantidad <= 0) {
			mensaje = "La cantidad debe ser mayor a cero.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		transaccion = conexion->BeginTransaction();

		String^ sqlTanque =
			"SELECT nivel_actual, capacidad_tanque "
			"FROM tbl_tanque "
			"WHERE id_tanque = @idTanque "
			"AND estado_tanque = 1 "
			"LIMIT 1 "
			"FOR UPDATE";

		MySqlCommand^ cmdTanque = gcnew MySqlCommand(sqlTanque, conexion, transaccion);
		cmdTanque->Parameters->AddWithValue("@idTanque", movimiento->idTanque);

		reader = cmdTanque->ExecuteReader();

		if (!reader->Read()) {
			reader->Close();
			transaccion->Rollback();

			mensaje = "El tanque seleccionado no existe o no esta activo.";
			return false;
		}

		double nivelActual = Convert::ToDouble(reader["nivel_actual"]);
		double capacidadTanque = Convert::ToDouble(reader["capacidad_tanque"]);

		reader->Close();

		String^ tipo = movimiento->tipoMovimiento->ToUpper();

		double nuevoNivel = nivelActual;

		if (tipo == "ENTRADA") {
			nuevoNivel = nivelActual + movimiento->cantidad;
		}
		else if (tipo == "SALIDA") {
			nuevoNivel = nivelActual - movimiento->cantidad;
		}
		else if (tipo == "AJUSTE") {
			nuevoNivel = movimiento->cantidad;
		}
		else {
			transaccion->Rollback();
			mensaje = "Tipo de movimiento no valido.";
			return false;
		}

		if (nuevoNivel < 0) {
			transaccion->Rollback();
			mensaje = "El movimiento dejar\u00EDa el tanque con nivel negativo.";
			return false;
		}

		if (nuevoNivel > capacidadTanque) {
			transaccion->Rollback();
			mensaje = "El movimiento supera la capacidad del tanque.";
			return false;
		}

		String^ sqlMovimiento =
			"INSERT INTO tbl_movimiento_inventario "
			"(tipo_movimiento, cantidad, descripcion_movimiento, id_tanque, id_usuario) "
			"VALUES "
			"(@tipo, @cantidad, @descripcion, @idTanque, @idUsuario)";

		MySqlCommand^ cmdMovimiento = gcnew MySqlCommand(sqlMovimiento, conexion, transaccion);
		cmdMovimiento->Parameters->AddWithValue("@tipo", tipo);
		cmdMovimiento->Parameters->AddWithValue("@cantidad", movimiento->cantidad);
		cmdMovimiento->Parameters->AddWithValue("@descripcion", movimiento->descripcionMovimiento);
		cmdMovimiento->Parameters->AddWithValue("@idTanque", movimiento->idTanque);
		cmdMovimiento->Parameters->AddWithValue("@idUsuario", movimiento->idUsuario);
		cmdMovimiento->ExecuteNonQuery();

		String^ sqlActualizarTanque =
			"UPDATE tbl_tanque "
			"SET nivel_actual = @nuevoNivel "
			"WHERE id_tanque = @idTanque";

		MySqlCommand^ cmdActualizar = gcnew MySqlCommand(sqlActualizarTanque, conexion, transaccion);
		cmdActualizar->Parameters->AddWithValue("@nuevoNivel", nuevoNivel);
		cmdActualizar->Parameters->AddWithValue("@idTanque", movimiento->idTanque);
		cmdActualizar->ExecuteNonQuery();

		transaccion->Commit();

		mensaje = "Movimiento registrado correctamente. Nuevo nivel: " + nuevoNivel.ToString("N2");
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

		mensaje = "Error al registrar movimiento: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}