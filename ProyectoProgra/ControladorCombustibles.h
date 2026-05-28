#pragma once

#include "dbConexion.h"
#include "ModeloCombustible.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorCombustibles
	{
	private:
		dbConexion^ db;

	public:
		ControladorCombustibles();

		DataTable^ listarCombustibles();

		bool registrarCombustible(
			CombustibleSistema^ combustible,
			String^% mensaje
		);

		bool actualizarCombustible(
			CombustibleSistema^ combustible,
			String^% mensaje
		);

		bool cambiarEstadoCombustible(
			int idCombustible,
			bool nuevoEstado,
			String^% mensaje
		);
	};
}