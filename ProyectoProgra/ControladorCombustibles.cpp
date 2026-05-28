#include "ControladorCombustibles.h"

using namespace ProyectoProgra;

ControladorCombustibles::ControladorCombustibles() {
	db = gcnew dbConexion();
}

DataTable^ ControladorCombustibles::listarCombustibles() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT "
			"id_combustible AS ID, "
			"nombre_combustible AS Nombre, "
			"tipo_combustible AS Tipo, "
			"precio_galon AS PrecioGalon, "
			"CASE WHEN estado_combustible = 1 THEN 'Activo' ELSE 'Inactivo' END AS Estado "
			"FROM tbl_combustible "
			"ORDER BY id_combustible DESC";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al listar combustibles: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

bool ControladorCombustibles::registrarCombustible(
	CombustibleSistema^ combustible,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (combustible == nullptr) {
			mensaje = "No hay datos del combustible.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(combustible->nombreCombustible)) {
			mensaje = "Debe ingresar el nombre del combustible.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(combustible->tipoCombustible)) {
			mensaje = "Debe ingresar el tipo de combustible.";
			return false;
		}

		if (combustible->precioGalon <= 0) {
			mensaje = "El precio por galon debe ser mayor a cero.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) "
			"FROM tbl_combustible "
			"WHERE nombre_combustible = @nombreCombustible "
			"AND tipo_combustible = @tipoCombustible";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@nombreCombustible", combustible->nombreCombustible);
		cmdExiste->Parameters->AddWithValue("@tipoCombustible", combustible->tipoCombustible);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "Ya existe un combustible con ese nombre y tipo.";
			return false;
		}

		String^ sqlInsert =
			"INSERT INTO tbl_combustible "
			"(nombre_combustible, tipo_combustible, precio_galon, estado_combustible) "
			"VALUES "
			"(@nombreCombustible, @tipoCombustible, @precioGalon, @estado)";

		MySqlCommand^ cmdInsert = gcnew MySqlCommand(sqlInsert, conexion);
		cmdInsert->Parameters->AddWithValue("@nombreCombustible", combustible->nombreCombustible);
		cmdInsert->Parameters->AddWithValue("@tipoCombustible", combustible->tipoCombustible);
		cmdInsert->Parameters->AddWithValue("@precioGalon", combustible->precioGalon);
		cmdInsert->Parameters->AddWithValue("@estado", combustible->estadoCombustible ? 1 : 0);

		int filas = cmdInsert->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = "Combustible registrado correctamente.";
			return true;
		}

		mensaje = "No se pudo registrar el combustible.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al registrar combustible: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}

bool ControladorCombustibles::actualizarCombustible(
	CombustibleSistema^ combustible,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (combustible == nullptr || combustible->idCombustible <= 0) {
			mensaje = "Debe seleccionar un combustible.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(combustible->nombreCombustible)) {
			mensaje = "Debe ingresar el nombre del combustible.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(combustible->tipoCombustible)) {
			mensaje = "Debe ingresar el tipo de combustible.";
			return false;
		}

		if (combustible->precioGalon <= 0) {
			mensaje = "El precio por galon debe ser mayor a cero.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) "
			"FROM tbl_combustible "
			"WHERE nombre_combustible = @nombreCombustible "
			"AND tipo_combustible = @tipoCombustible "
			"AND id_combustible <> @idCombustible";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@nombreCombustible", combustible->nombreCombustible);
		cmdExiste->Parameters->AddWithValue("@tipoCombustible", combustible->tipoCombustible);
		cmdExiste->Parameters->AddWithValue("@idCombustible", combustible->idCombustible);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "Ya existe otro combustible con ese nombre y tipo.";
			return false;
		}

		String^ sqlUpdate =
			"UPDATE tbl_combustible SET "
			"nombre_combustible = @nombreCombustible, "
			"tipo_combustible = @tipoCombustible, "
			"precio_galon = @precioGalon, "
			"estado_combustible = @estado "
			"WHERE id_combustible = @idCombustible";

		MySqlCommand^ cmdUpdate = gcnew MySqlCommand(sqlUpdate, conexion);
		cmdUpdate->Parameters->AddWithValue("@nombreCombustible", combustible->nombreCombustible);
		cmdUpdate->Parameters->AddWithValue("@tipoCombustible", combustible->tipoCombustible);
		cmdUpdate->Parameters->AddWithValue("@precioGalon", combustible->precioGalon);
		cmdUpdate->Parameters->AddWithValue("@estado", combustible->estadoCombustible ? 1 : 0);
		cmdUpdate->Parameters->AddWithValue("@idCombustible", combustible->idCombustible);

		int filas = cmdUpdate->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = "Combustible actualizado correctamente.";
			return true;
		}

		mensaje = "No se pudo actualizar el combustible.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al actualizar combustible: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}

bool ControladorCombustibles::cambiarEstadoCombustible(
	int idCombustible,
	bool nuevoEstado,
	String^% mensaje
) {
	try {
		if (idCombustible <= 0) {
			mensaje = "Debe seleccionar un combustible.";
			return false;
		}

		MySqlConnection^ conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sql =
			"UPDATE tbl_combustible "
			"SET estado_combustible = @estado "
			"WHERE id_combustible = @idCombustible";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, conexion);
		cmd->Parameters->AddWithValue("@estado", nuevoEstado ? 1 : 0);
		cmd->Parameters->AddWithValue("@idCombustible", idCombustible);

		int filas = cmd->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = nuevoEstado ? "Combustible activado correctamente." : "Combustible desactivado correctamente.";
			return true;
		}

		mensaje = "No se pudo cambiar el estado del combustible.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al cambiar estado del combustible: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}