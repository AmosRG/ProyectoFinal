#pragma once

#include "dbConexion.h"
#include "ModeloTanque.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorTanques
	{
	private:
		dbConexion^ db;

	public:
		ControladorTanques();

		DataTable^ listarTanques();
		DataTable^ listarCombustiblesActivos();

		bool registrarTanque(
			TanqueSistema^ tanque,
			String^% mensaje
		);

		bool actualizarTanque(
			TanqueSistema^ tanque,
			String^% mensaje
		);

		bool cambiarEstadoTanque(
			int idTanque,
			bool nuevoEstado,
			String^% mensaje
		);
	};
}