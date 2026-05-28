#pragma once

using namespace System;

namespace ProyectoProgra {

	public ref class Usuario
	{
	public:
		int idUsuario;
		String^ nombreUsuario;
		String^ nombre;
		String^ contrasenaUsuario;
		String^ nombreRol;

		Usuario() {
			idUsuario = 0;
			nombreUsuario = "";
			nombre = "";
			contrasenaUsuario = "";
			nombreRol = "";
		}

		Usuario(
			int idUsuario,
			String^ nombreUsuario,
			String^ nombre,
			String^ contrasenaUsuario,
			String^ nombreRol
		) {
			this->idUsuario = idUsuario;
			this->nombreUsuario = nombreUsuario;
			this->nombre = nombre;
			this->contrasenaUsuario = contrasenaUsuario;
			this->nombreRol = nombreRol;
		}
	};

	public ref class PermisoMenu
	{
	public:
		bool puedeUsuarios;
		bool puedeCombustibles;
		bool puedeTanques;
		bool puedeBombas;
		bool puedeInventario;
		bool puedeVentas;
		bool puedeReportes;

		PermisoMenu() {
			puedeUsuarios = false;
			puedeCombustibles = false;
			puedeTanques = false;
			puedeBombas = false;
			puedeInventario = false;
			puedeVentas = false;
			puedeReportes = false;
		}
	};
}
