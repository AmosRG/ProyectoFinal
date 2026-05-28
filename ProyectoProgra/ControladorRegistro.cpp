#include "ControladorRegistro.h"

using namespace ProyectoProgra;

ControladorRegistroUsuario::ControladorRegistroUsuario() {
	db = gcnew dbConexion();
}

DataTable^ ControladorRegistroUsuario::listarRoles() {
	DataTable^ tabla = gcnew DataTable();

	try {
		String^ sql = "SELECT id_rol, nombre_rol FROM tbl_rol ORDER BY nombre_rol ASC";
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

bool ControladorRegistroUsuario::registrarUsuario(
	String^ nombre,
	String^ correo,
	String^ nombreUsuario,
	String^ password,
	String^ confirmarPassword,
	int idRol,
	String^% mensaje
) {
	MySqlConnection^ conexion = nullptr;

	try {
		if (String::IsNullOrWhiteSpace(nombre)) {
			mensaje = "Debe ingresar el nombre completo.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(correo)) {
			mensaje = "Debe ingresar el correo.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(nombreUsuario)) {
			mensaje = "Debe ingresar el nombre de usuario.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(password)) {
			mensaje = "Debe ingresar la contraseña.";
			return false;
		}

		if (String::IsNullOrWhiteSpace(confirmarPassword)) {
			mensaje = "Debe confirmar la contraseña.";
			return false;
		}

		if (password != confirmarPassword) {
			mensaje = "Las contraseñas no coinciden.";
			return false;
		}

		if (idRol <= 0) {
			mensaje = "Debe seleccionar un rol.";
			return false;
		}

		conexion = db->getConexion();

		if (conexion == nullptr) {
			mensaje = "No se pudo conectar a la base de datos.";
			return false;
		}

		String^ sqlExiste =
			"SELECT COUNT(*) FROM tbl_usuario "
			"WHERE correo = @correo OR nombre_usuario = @nombreUsuario";

		MySqlCommand^ cmdExiste = gcnew MySqlCommand(sqlExiste, conexion);
		cmdExiste->Parameters->AddWithValue("@correo", correo);
		cmdExiste->Parameters->AddWithValue("@nombreUsuario", nombreUsuario);

		int existe = Convert::ToInt32(cmdExiste->ExecuteScalar());

		if (existe > 0) {
			mensaje = "El correo o nombre de usuario ya existe.";
			return false;
		}

		String^ sqlInsert =
			"INSERT INTO tbl_usuario "
			"(nombre, correo, nombre_usuario, contrasena_usuario, estado_usuario, id_rol) "
			"VALUES "
			"(@nombre, @correo, @nombreUsuario, @password, 1, @idRol)";

		MySqlCommand^ cmdInsert = gcnew MySqlCommand(sqlInsert, conexion);
		cmdInsert->Parameters->AddWithValue("@nombre", nombre);
		cmdInsert->Parameters->AddWithValue("@correo", correo);
		cmdInsert->Parameters->AddWithValue("@nombreUsuario", nombreUsuario);
		cmdInsert->Parameters->AddWithValue("@password", password);
		cmdInsert->Parameters->AddWithValue("@idRol", idRol);

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
