#pragma once

#include "dbConexion.h"
#include "ModeloGestionUsuario.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorUsuarios
	{
	private:
		dbConexion^ db;

	public:
		ControladorUsuarios();

		DataTable^ listarUsuarios();
		DataTable^ listarRoles();

		bool registrarUsuario(
			UsuarioSistema^ usuario,
			String^ confirmarPassword,
			String^% mensaje
		);

		bool actualizarUsuario(
			UsuarioSistema^ usuario,
			String^ confirmarPassword,
			String^% mensaje
		);

		bool cambiarEstadoUsuario(
			int idUsuario,
			bool nuevoEstado,
			String^% mensaje
		);
	};
}