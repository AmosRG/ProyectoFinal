#pragma once

#include "dbConexion.h"
#include "ModeloInventario.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorInventario
	{
	private:
		dbConexion^ db;

	public:
		ControladorInventario();

		DataTable^ listarTanquesActivos();

		DataTable^ listarMovimientos();

		double obtenerNivelActualTanque(int idTanque);

		bool registrarMovimiento(
			MovimientoInventarioSistema^ movimiento,
			String^% mensaje
		);
	};
}