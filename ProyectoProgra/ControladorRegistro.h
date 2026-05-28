#pragma once

#include "dbConexion.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorRegistroUsuario
	{
	private:
		dbConexion^ db;

	public:
		ControladorRegistroUsuario();

		DataTable^ listarRoles();

		bool registrarUsuario(
			String^ nombre,
			String^ correo,
			String^ nombreUsuario,
			String^ password,
			String^ confirmarPassword,
			int idRol,
			String^% mensaje
		);
	};
}
