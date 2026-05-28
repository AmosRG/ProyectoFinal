#pragma once

using namespace System;

namespace ProyectoProgra {

	public ref class CombustibleSistema
	{
	public:
		int idCombustible;
		String^ nombreCombustible;
		String^ tipoCombustible;
		double precioGalon;
		bool estadoCombustible;

		CombustibleSistema() {
			idCombustible = 0;
			nombreCombustible = "";
			tipoCombustible = "";
			precioGalon = 0;
			estadoCombustible = true;
		}
	};
}