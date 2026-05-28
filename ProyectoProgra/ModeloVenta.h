#pragma once

using namespace System;

namespace ProyectoProgra {

	public ref class ClienteVenta
	{
	public:
		int idCliente;
		String^ nit;
		String^ nombreCliente;

		ClienteVenta() {
			idCliente = 0;
			nit = "";
			nombreCliente = "Consumidor final";
		}
	};

	public ref class VentaCalculo
	{
	public:
		int idBomba;
		int numeroBomba;
		int idTanque;
		int idCombustible;
		int idOferta;

		String^ nombreCombustible;
		String^ nombreOferta;

		double cantidadGalones;
		double precioUnitario;
		double nivelActual;
		double subtotal;
		double descuento;
		double total;

		VentaCalculo() {
			idBomba = 0;
			numeroBomba = 0;
			idTanque = 0;
			idCombustible = 0;
			idOferta = 0;

			nombreCombustible = "";
			nombreOferta = "Sin oferta";

			cantidadGalones = 0;
			precioUnitario = 0;
			nivelActual = 0;
			subtotal = 0;
			descuento = 0;
			total = 0;
		}
	};
}