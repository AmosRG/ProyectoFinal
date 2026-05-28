#pragma once

#include "dbConexion.h"
#include "ModeloUsuario.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorLogin
	{
	private:
		dbConexion^ db;

	public:
		ControladorLogin();

		Usuario^ validarLogin(String^ usuario, String^ password);
	};
}
