#pragma once

#include "dbConexion.h"
#include "ModeloReporte.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorReportes
	{
	private:
		dbConexion^ db;

		DataTable^ ejecutarDataTable(MySqlCommand^ comando);

	public:
		ControladorReportes();

		DataTable^ generarReporte(
			String^ tipoReporte,
			DateTime fechaInicio,
			DateTime fechaFin
		);

		DataTable^ reporteVentasResumen(
			DateTime fechaInicio,
			DateTime fechaFin
		);

		DataTable^ reporteVentasDetalle(
			DateTime fechaInicio,
			DateTime fechaFin
		);

		DataTable^ reporteInventarioActual();

		DataTable^ reporteMovimientosInventario(
			DateTime fechaInicio,
			DateTime fechaFin
		);

		DataTable^ reporteTanquesBajoMinimo();

		String^ obtenerResumenReporte(
			String^ tipoReporte,
			DataTable^ tabla
		);
	};
}