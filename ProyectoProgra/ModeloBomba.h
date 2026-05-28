#pragma once

using namespace System;

namespace ProyectoProgra {

	public ref class BombaSistema
	{
	public:
		int idBomba;
		int numeroBomba;
		bool estadoBomba;
		int idTanque;

		String^ nombreTanque;
		String^ nombreCombustible;

		BombaSistema() {
			idBomba = 0;
			numeroBomba = 0;
			estadoBomba = true;
			idTanque = 0;
			nombreTanque = "";
			nombreCombustible = "";
		}
	};
}