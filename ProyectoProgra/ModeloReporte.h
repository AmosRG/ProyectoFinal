#pragma once

using namespace System;

namespace ProyectoProgra {

	public ref class FiltroReporte
	{
	public:
		String^ tipoReporte;
		DateTime fechaInicio;
		DateTime fechaFin;

		FiltroReporte() {
			tipoReporte = "";
			fechaInicio = DateTime::Now;
			fechaFin = DateTime::Now;
		}
	};
}