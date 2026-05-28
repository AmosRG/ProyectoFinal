#pragma once

using namespace System;

namespace ProyectoProgra {

	public ref class TanqueSistema
	{
	public:
		int idTanque;
		String^ nombreTanque;
		double capacidadTanque;
		double nivelActual;
		double nivelMinimo;
		bool estadoTanque;
		int idCombustible;
		String^ nombreCombustible;

		TanqueSistema() {
			idTanque = 0;
			nombreTanque = "";
			capacidadTanque = 0;
			nivelActual = 0;
			nivelMinimo = 0;
			estadoTanque = true;
			idCombustible = 0;
			nombreCombustible = "";
		}
	};
}