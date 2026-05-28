#include "ControladorTanques.h"

using namespace ProyectoProgra;

ControladorTanques::ControladorTanques() {
	db = gcnew dbConexion();
}

DataTable^ ControladorTanques::listarTanques() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT "
			"t.id_tanque AS ID, "
			"t.nombre_tanque AS Tanque, "
			"t.capacidad_tanque AS Capacidad, "
			"t.nivel_actual AS NivelActual, "
			"t.nivel_minimo AS NivelMinimo, "
			"CASE WHEN t.estado_tanque = 1 THEN 'Activo' ELSE 'Inactivo' END AS Estado, "
			"c.id_combustible AS IdCombustible, "
			"c.nombre_combustible AS Combustible "
			"FROM tbl_tanque t "
			"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
			"ORDER BY t.id_tanque DESC";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al listar tanques: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

DataTable^ ControladorTanques::listarCombustiblesActivos() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT "
			"id_combustible, "
			"CONCAT(nombre_combustible, ' - ', tipo_combustible) AS descripcion_combustible "
			"FROM tbl_combustible "
			"WHERE estado_combustible = 1 "
			"ORDER BY nombre_combustible ASC";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al cargar combustibles: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

bool ControladorTanques::registrarTanque(
	TanqueSistema^ tanque,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (tanque == nullptr) {
			mensaje = "No hay datos del tanque.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(tanque->nombreTanque)) {
			mensaje = "Debe ingresar el nombre del tanque.";
			return false;
		}

		if (tanque->capacidadTanque <= 0) {
			mensaje = "La capacidad del tanque debe ser mayor a cero.";
			return false;
		}

		if (tanque->nivelActual < 0) {
			mensaje = "El nivel actual no puede ser negativo.";
			return false;
		}

		if (tanque->nivelMinimo < 0) {
			mensaje = "El nivel minimo no puede ser negativo.";
			return false;
		}

		if (tanque->nivelActual > tanque->capacidadTanque) {
			mensaje = "El nivel actual no puede ser mayor que la capacidad.";
			return false;
		}

		if (tanque->nivelMinimo > tanque->capacidadTanque) {
			mensaje = "El nivel minimo no puede ser mayor que la capacidad.";
			return false;
		}

		if (tanque->idCombustible <= 0) {
			mensaje = "Debe seleccionar un combustible.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) "
			"FROM tbl_tanque "
			"WHERE nombre_tanque = @nombreTanque";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@nombreTanque", tanque->nombreTanque);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "Ya existe un tanque con ese nombre.";
			return false;
		}

		String^ sqlInsert =
			"INSERT INTO tbl_tanque "
			"(nombre_tanque, capacidad_tanque, nivel_actual, nivel_minimo, estado_tanque, id_combustible) "
			"VALUES "
			"(@nombreTanque, @capacidad, @nivelActual, @nivelMinimo, @estado, @idCombustible)";

		MySqlCommand^ cmdInsert = gcnew MySqlCommand(sqlInsert, conexion);
		cmdInsert->Parameters->AddWithValue("@nombreTanque", tanque->nombreTanque);
		cmdInsert->Parameters->AddWithValue("@capacidad", tanque->capacidadTanque);
		cmdInsert->Parameters->AddWithValue("@nivelActual", tanque->nivelActual);
		cmdInsert->Parameters->AddWithValue("@nivelMinimo", tanque->nivelMinimo);
		cmdInsert->Parameters->AddWithValue("@estado", tanque->estadoTanque ? 1 : 0);
		cmdInsert->Parameters->AddWithValue("@idCombustible", tanque->idCombustible);

		int filas = cmdInsert->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = "Tanque registrado correctamente.";
			return true;
		}

		mensaje = "No se pudo registrar el tanque.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al registrar tanque: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}

bool ControladorTanques::actualizarTanque(
	TanqueSistema^ tanque,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (tanque == nullptr || tanque->idTanque <= 0) {
			mensaje = "Debe seleccionar un tanque.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(tanque->nombreTanque)) {
			mensaje = "Debe ingresar el nombre del tanque.";
			return false;
		}

		if (tanque->capacidadTanque <= 0) {
			mensaje = "La capacidad del tanque debe ser mayor a cero.";
			return false;
		}

		if (tanque->nivelActual < 0) {
			mensaje = "El nivel actual no puede ser negativo.";
			return false;
		}

		if (tanque->nivelMinimo < 0) {
			mensaje = "El nivel minimo no puede ser negativo.";
			return false;
		}

		if (tanque->nivelActual > tanque->capacidadTanque) {
			mensaje = "El nivel actual no puede ser mayor que la capacidad.";
			return false;
		}

		if (tanque->nivelMinimo > tanque->capacidadTanque) {
			mensaje = "El nivel minimo no puede ser mayor que la capacidad.";
			return false;
		}

		if (tanque->idCombustible <= 0) {
			mensaje = "Debe seleccionar un combustible.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) "
			"FROM tbl_tanque "
			"WHERE nombre_tanque = @nombreTanque "
			"AND id_tanque <> @idTanque";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@nombreTanque", tanque->nombreTanque);
		cmdExiste->Parameters->AddWithValue("@idTanque", tanque->idTanque);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "Ya existe otro tanque con ese nombre.";
			return false;
		}

		String^ sqlUpdate =
			"UPDATE tbl_tanque SET "
			"nombre_tanque = @nombreTanque, "
			"capacidad_tanque = @capacidad, "
			"nivel_actual = @nivelActual, "
			"nivel_minimo = @nivelMinimo, "
			"estado_tanque = @estado, "
			"id_combustible = @idCombustible "
			"WHERE id_tanque = @idTanque";

		MySqlCommand^ cmdUpdate = gcnew MySqlCommand(sqlUpdate, conexion);
		cmdUpdate->Parameters->AddWithValue("@nombreTanque", tanque->nombreTanque);
		cmdUpdate->Parameters->AddWithValue("@capacidad", tanque->capacidadTanque);
		cmdUpdate->Parameters->AddWithValue("@nivelActual", tanque->nivelActual);
		cmdUpdate->Parameters->AddWithValue("@nivelMinimo", tanque->nivelMinimo);
		cmdUpdate->Parameters->AddWithValue("@estado", tanque->estadoTanque ? 1 : 0);
		cmdUpdate->Parameters->AddWithValue("@idCombustible", tanque->idCombustible);
		cmdUpdate->Parameters->AddWithValue("@idTanque", tanque->idTanque);

		int filas = cmdUpdate->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = "Tanque actualizado correctamente.";
			return true;
		}

		mensaje = "No se pudo actualizar el tanque.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al actualizar tanque: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}

bool ControladorTanques::cambiarEstadoTanque(
	int idTanque,
	bool nuevoEstado,
	String^% mensaje
) {
	try {
		if (idTanque <= 0) {
			mensaje = "Debe seleccionar un tanque.";
			return false;
		}

		MySqlConnection^ conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sql =
			"UPDATE tbl_tanque "
			"SET estado_tanque = @estado "
			"WHERE id_tanque = @idTanque";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, conexion);
		cmd->Parameters->AddWithValue("@estado", nuevoEstado ? 1 : 0);
		cmd->Parameters->AddWithValue("@idTanque", idTanque);

		int filas = cmd->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = nuevoEstado ? "Tanque activado correctamente." : "Tanque desactivado correctamente.";
			return true;
		}

		mensaje = "No se pudo cambiar el estado del tanque.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al cambiar estado del tanque: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}