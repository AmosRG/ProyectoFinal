#pragma once

using namespace System;

namespace ProyectoProgra {

	public ref class MovimientoInventarioSistema
	{
	public:
		int idMovimiento;
		String^ tipoMovimiento;
		double cantidad;
		String^ descripcionMovimiento;
		int idTanque;
		int idUsuario;

		String^ nombreTanque;
		String^ nombreUsuario;

		MovimientoInventarioSistema() {
			idMovimiento = 0;
			tipoMovimiento = "";
			cantidad = 0;
			descripcionMovimiento = "";
			idTanque = 0;
			idUsuario = 0;
			nombreTanque = "";
			nombreUsuario = "";
		}
	};
}