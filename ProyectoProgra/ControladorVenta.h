#pragma once

#include "dbConexion.h"
#include "ModeloVenta.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class ControladorVenta
	{
	private:
		dbConexion^ db;

		double calcularDescuentoInterno(String^ tipoDescuento, double valorDescuento, double subtotal);

	public:
		ControladorVenta();

		DataTable^ listarBombasActivas();

		DataTable^ listarVentasRecientes();

		ClienteVenta^ buscarClientePorNit(String^ nit, String^% mensaje);

		VentaCalculo^ calcularVenta(int idBomba, double cantidadGalones, String^% mensaje);

		bool registrarVenta(
			int idBomba,
			double cantidadGalones,
			int idUsuario,
			int idCliente,
			String^% mensaje
		);
	};
}