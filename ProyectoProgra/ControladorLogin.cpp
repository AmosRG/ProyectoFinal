#include "ControladorLogin.h"

using namespace ProyectoProgra;

ControladorLogin::ControladorLogin() {
	db = gcnew dbConexion();
}

Usuario^ ControladorLogin::validarLogin(String^ usuario, String^ password) {

	MySqlDataReader^ reader = nullptr;

	try {
		if (db->conexionActiva()) {

			String^ sql =
				"SELECT u.id_usuario, u.nombre, u.nombre_usuario, "
				"u.contrasena_usuario, r.nombre_rol "
				"FROM tbl_usuario u "
				"INNER JOIN tbl_rol r ON u.id_rol = r.id_rol "
				"WHERE u.nombre_usuario = @usr "
				"AND u.contrasena_usuario = @pwd "
				"AND u.estado_usuario = 1 "
				"LIMIT 1";

			MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
			cmd->Parameters->AddWithValue("@usr", usuario);
			cmd->Parameters->AddWithValue("@pwd", password);

			reader = cmd->ExecuteReader();

			if (reader->Read()) {

				Usuario^ u = gcnew Usuario(
					reader->GetInt32(reader->GetOrdinal("id_usuario")),
					reader->GetString(reader->GetOrdinal("nombre_usuario")),
					reader->GetString(reader->GetOrdinal("nombre")),
					reader->GetString(reader->GetOrdinal("contrasena_usuario")),
					reader->GetString(reader->GetOrdinal("nombre_rol"))
				);

				reader->Close();
				db->cerrarConexion();

				return u;
			}

			reader->Close();
			db->cerrarConexion();
		}
	}
	catch (Exception^ ex) {
		if (reader != nullptr && !reader->IsClosed) {
			reader->Close();
		}

		db->cerrarConexion();

		MessageBox::Show("Error al validar login: " + ex->Message);
	}

	return nullptr;
}
