#include "ControladorBombas.h"

using namespace ProyectoProgra;

ControladorBombas::ControladorBombas() {
	db = gcnew dbConexion();
}

DataTable^ ControladorBombas::listarBombas() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT "
			"b.id_bomba AS ID, "
			"b.numero_bomba AS NumeroBomba, "
			"CASE WHEN b.estado_bomba = 1 THEN 'Activo' ELSE 'Inactivo' END AS Estado, "
			"t.id_tanque AS IdTanque, "
			"t.nombre_tanque AS Tanque, "
			"c.nombre_combustible AS Combustible "
			"FROM tbl_bomba b "
			"INNER JOIN tbl_tanque t ON b.id_tanque = t.id_tanque "
			"INNER JOIN tbl_combustible c ON t.id_combustible = c.id_combustible "
			"ORDER BY b.numero_bomba ASC";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al listar bombas: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

DataTable^ ControladorBombas::listarTanquesActivos() {
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

bool ControladorBombas::registrarBomba(
	BombaSistema^ bomba,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (bomba == nullptr) {
			mensaje = "No hay datos de la bomba.";
			return false;
		}

		if (bomba->numeroBomba <= 0) {
			mensaje = "Debe ingresar un numero de bomba valido.";
			return false;
		}

		if (bomba->idTanque <= 0) {
			mensaje = "Debe seleccionar un tanque.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) "
			"FROM tbl_bomba "
			"WHERE numero_bomba = @numeroBomba";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@numeroBomba", bomba->numeroBomba);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "Ya existe una bomba con ese numero.";
			return false;
		}

		String^ sqlInsert =
			"INSERT INTO tbl_bomba "
			"(numero_bomba, estado_bomba, id_tanque) "
			"VALUES "
			"(@numeroBomba, @estado, @idTanque)";

		MySqlCommand^ cmdInsert = gcnew MySqlCommand(sqlInsert, conexion);
		cmdInsert->Parameters->AddWithValue("@numeroBomba", bomba->numeroBomba);
		cmdInsert->Parameters->AddWithValue("@estado", bomba->estadoBomba ? 1 : 0);
		cmdInsert->Parameters->AddWithValue("@idTanque", bomba->idTanque);

		int filas = cmdInsert->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = "Bomba registrada correctamente.";
			return true;
		}

		mensaje = "No se pudo registrar la bomba.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al registrar bomba: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}

bool ControladorBombas::actualizarBomba(
	BombaSistema^ bomba,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (bomba == nullptr || bomba->idBomba <= 0) {
			mensaje = "Debe seleccionar una bomba.";
			return false;
		}

		if (bomba->numeroBomba <= 0) {
			mensaje = "Debe ingresar un numero de bomba valido.";
			return false;
		}

		if (bomba->idTanque <= 0) {
			mensaje = "Debe seleccionar un tanque.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) "
			"FROM tbl_bomba "
			"WHERE numero_bomba = @numeroBomba "
			"AND id_bomba <> @idBomba";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@numeroBomba", bomba->numeroBomba);
		cmdExiste->Parameters->AddWithValue("@idBomba", bomba->idBomba);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "Ya existe otra bomba con ese numero.";
			return false;
		}

		String^ sqlUpdate =
			"UPDATE tbl_bomba SET "
			"numero_bomba = @numeroBomba, "
			"estado_bomba = @estado, "
			"id_tanque = @idTanque "
			"WHERE id_bomba = @idBomba";

		MySqlCommand^ cmdUpdate = gcnew MySqlCommand(sqlUpdate, conexion);
		cmdUpdate->Parameters->AddWithValue("@numeroBomba", bomba->numeroBomba);
		cmdUpdate->Parameters->AddWithValue("@estado", bomba->estadoBomba ? 1 : 0);
		cmdUpdate->Parameters->AddWithValue("@idTanque", bomba->idTanque);
		cmdUpdate->Parameters->AddWithValue("@idBomba", bomba->idBomba);

		int filas = cmdUpdate->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = "Bomba actualizada correctamente.";
			return true;
		}

		mensaje = "No se pudo actualizar la bomba.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al actualizar bomba: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}

bool ControladorBombas::cambiarEstadoBomba(
	int idBomba,
	bool nuevoEstado,
	String^% mensaje
) {
	try {
		if (idBomba <= 0) {
			mensaje = "Debe seleccionar una bomba.";
			return false;
		}

		MySqlConnection^ conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sql =
			"UPDATE tbl_bomba "
			"SET estado_bomba = @estado "
			"WHERE id_bomba = @idBomba";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, conexion);
		cmd->Parameters->AddWithValue("@estado", nuevoEstado ? 1 : 0);
		cmd->Parameters->AddWithValue("@idBomba", idBomba);

		int filas = cmd->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = nuevoEstado ? "Bomba activada correctamente." : "Bomba desactivada correctamente.";
			return true;
		}

		mensaje = "No se pudo cambiar el estado de la bomba.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al cambiar estado de la bomba: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}