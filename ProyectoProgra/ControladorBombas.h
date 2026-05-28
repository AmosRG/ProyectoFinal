#pragma once

#include "dbConexion.h"
#include "ModeloBomba.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorBombas
	{
	private:
		dbConexion^ db;

	public:
		ControladorBombas();

		DataTable^ listarBombas();

		DataTable^ listarTanquesActivos();

		bool registrarBomba(
			BombaSistema^ bomba,
			String^% mensaje
		);

		bool actualizarBomba(
			BombaSistema^ bomba,
			String^% mensaje
		);

		bool cambiarEstadoBomba(
			int idBomba,
			bool nuevoEstado,
			String^% mensaje
		);
	};
}