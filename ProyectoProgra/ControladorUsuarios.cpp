#include "ControladorUsuarios.h"

using namespace ProyectoProgra;

ControladorUsuarios::ControladorUsuarios() {
	db = gcnew dbConexion();
}

DataTable^ ControladorUsuarios::listarUsuarios() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT "
			"u.id_usuario AS ID, "
			"u.nombre AS Nombre, "
			"u.correo AS Correo, "
			"u.nombre_usuario AS Usuario, "
			"CASE WHEN u.estado_usuario = 1 THEN 'Activo' ELSE 'Inactivo' END AS Estado, "
			"r.id_rol AS IdRol, "
			"r.nombre_rol AS Rol "
			"FROM tbl_usuario u "
			"INNER JOIN tbl_rol r ON u.id_rol = r.id_rol "
			"ORDER BY u.id_usuario DESC";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al listar usuarios: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

DataTable^ ControladorUsuarios::listarRoles() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql =
			"SELECT id_rol, nombre_rol "
			"FROM tbl_rol "
			"ORDER BY nombre_rol ASC";

		tabla = db->ejecutaConsultaTabla(sql);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al cargar roles: " + ex->Message);
	}
	finally {
		db->cerrarConexion();
	}

	return tabla;
}

bool ControladorUsuarios::registrarUsuario(
	UsuarioSistema^ usuario,
	String^ confirmarPassword,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (usuario == nullptr) {
			mensaje = "No hay datos de usuario.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(usuario->nombre)) {
			mensaje = "Debe ingresar el nombre completo.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(usuario->correo)) {
			mensaje = "Debe ingresar el correo.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(usuario->nombreUsuario)) {
			mensaje = "Debe ingresar el nombre de usuario.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(usuario->contrasenaUsuario)) {
			mensaje = "Debe ingresar la contrase\u00F1a.";
			return false;
		}

		if (usuario->contrasenaUsuario != confirmarPassword) {
			mensaje = "Las contrase\u00F1as no coinciden.";
			return false;
		}

		if (usuario->idRol <= 0) {
			mensaje = "Debe seleccionar un rol.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) "
			"FROM tbl_usuario "
			"WHERE correo = @correo "
			"OR nombre_usuario = @nombreUsuario";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@correo", usuario->correo);
		cmdExiste->Parameters->AddWithValue("@nombreUsuario", usuario->nombreUsuario);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "El correo o nombre de usuario ya existe.";
			return false;
		}

		String^ sqlInsert =
			"INSERT INTO tbl_usuario "
			"(nombre, correo, nombre_usuario, contrasena_usuario, estado_usuario, id_rol) "
			"VALUES "
			"(@nombre, @correo, @nombreUsuario, @password, @estado, @idRol)";

		MySqlCommand^ cmdInsert = gcnew MySqlCommand(sqlInsert, conexion);
		cmdInsert->Parameters->AddWithValue("@nombre", usuario->nombre);
		cmdInsert->Parameters->AddWithValue("@correo", usuario->correo);
		cmdInsert->Parameters->AddWithValue("@nombreUsuario", usuario->nombreUsuario);
		cmdInsert->Parameters->AddWithValue("@password", usuario->contrasenaUsuario);
		cmdInsert->Parameters->AddWithValue("@estado", usuario->estadoUsuario ? 1 : 0);
		cmdInsert->Parameters->AddWithValue("@idRol", usuario->idRol);

		int filas = cmdInsert->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = "Usuario registrado correctamente.";
			return true;
		}

		mensaje = "No se pudo registrar el usuario.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al registrar usuario: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}

bool ControladorUsuarios::actualizarUsuario(
	UsuarioSistema^ usuario,
	String^ confirmarPassword,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (usuario == nullptr || usuario->idUsuario <= 0) {
			mensaje = "Debe seleccionar un usuario.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(usuario->nombre)) {
			mensaje = "Debe ingresar el nombre completo.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(usuario->correo)) {
			mensaje = "Debe ingresar el correo.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(usuario->nombreUsuario)) {
			mensaje = "Debe ingresar el nombre de usuario.";
			return false;
		}

		if (usuario->idRol <= 0) {
			mensaje = "Debe seleccionar un rol.";
			return false;
		}

		if (!String::IsNullOrWhiteSpace(usuario->contrasenaUsuario)) {
			if (usuario->contrasenaUsuario != confirmarPassword) {
				mensaje = "Las contrase\u00F1as no coinciden.";
				return false;
			}
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) "
			"FROM tbl_usuario "
			"WHERE (correo = @correo OR nombre_usuario = @nombreUsuario) "
			"AND id_usuario <> @idUsuario";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@correo", usuario->correo);
		cmdExiste->Parameters->AddWithValue("@nombreUsuario", usuario->nombreUsuario);
		cmdExiste->Parameters->AddWithValue("@idUsuario", usuario->idUsuario);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "El correo o nombre de usuario ya pertenece a otro usuario.";
			return false;
		}

		String^ sqlUpdate = "";

		if (String::IsNullOrWhiteSpace(usuario->contrasenaUsuario)) {
			sqlUpdate =
				"UPDATE tbl_usuario SET "
				"nombre = @nombre, "
				"correo = @correo, "
				"nombre_usuario = @nombreUsuario, "
				"estado_usuario = @estado, "
				"id_rol = @idRol "
				"WHERE id_usuario = @idUsuario";
		}
		else {
			sqlUpdate =
				"UPDATE tbl_usuario SET "
				"nombre = @nombre, "
				"correo = @correo, "
				"nombre_usuario = @nombreUsuario, "
				"contrasena_usuario = @password, "
				"estado_usuario = @estado, "
				"id_rol = @idRol "
				"WHERE id_usuario = @idUsuario";
		}

		MySqlCommand^ cmdUpdate = gcnew MySqlCommand(sqlUpdate, conexion);
		cmdUpdate->Parameters->AddWithValue("@nombre", usuario->nombre);
		cmdUpdate->Parameters->AddWithValue("@correo", usuario->correo);
		cmdUpdate->Parameters->AddWithValue("@nombreUsuario", usuario->nombreUsuario);
		cmdUpdate->Parameters->AddWithValue("@estado", usuario->estadoUsuario ? 1 : 0);
		cmdUpdate->Parameters->AddWithValue("@idRol", usuario->idRol);
		cmdUpdate->Parameters->AddWithValue("@idUsuario", usuario->idUsuario);

		if (!String::IsNullOrWhiteSpace(usuario->contrasenaUsuario)) {
			cmdUpdate->Parameters->AddWithValue("@password", usuario->contrasenaUsuario);
		}

		int filas = cmdUpdate->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = "Usuario actualizado correctamente.";
			return true;
		}

		mensaje = "No se pudo actualizar el usuario.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al actualizar usuario: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}

bool ControladorUsuarios::cambiarEstadoUsuario(
	int idUsuario,
	bool nuevoEstado,
	String^% mensaje
) {
	try {
		if (idUsuario <= 0) {
			mensaje = "Debe seleccionar un usuario.";
			return false;
		}

		MySqlConnection^ conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sql =
			"UPDATE tbl_usuario "
			"SET estado_usuario = @estado "
			"WHERE id_usuario = @idUsuario";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, conexion);
		cmd->Parameters->AddWithValue("@estado", nuevoEstado ? 1 : 0);
		cmd->Parameters->AddWithValue("@idUsuario", idUsuario);

		int filas = cmd->ExecuteNonQuery();

		if (filas > 0) {
			mensaje = nuevoEstado ? "Usuario activado correctamente." : "Usuario desactivado correctamente.";
			return true;
		}

		mensaje = "No se pudo cambiar el estado del usuario.";
		return false;
	}
	catch (Exception^ ex) {
		mensaje = "Error al cambiar estado del usuario: " + ex->Message;
		return false;
	}
	finally {
		db->cerrarConexion();
	}
}