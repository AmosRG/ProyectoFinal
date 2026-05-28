#pragma once

#include "ModeloUsuario.h"

using namespace System;

namespace ProyectoProgra {

	public ref class ControladorMenuPrincipal
	{
	public:
		ControladorMenuPrincipal() {
		}

		String^ obtenerBienvenida(Usuario^ usuario) {
			if (usuario == nullptr) {
				return "Bienvenido";
			}

			return "Bienvenido: " + usuario->nombre;
		}

		String^ obtenerRol(Usuario^ usuario) {
			if (usuario == nullptr) {
				return "Rol: Sin rol";
			}

			return "Rol: " + usuario->nombreRol;
		}

		PermisoMenu^ obtenerPermisos(Usuario^ usuario) {
			PermisoMenu^ permisos = gcnew PermisoMenu();

			if (usuario == nullptr) {
				return permisos;
			}

			if (usuario->nombreRol == "Administrador") {
				permisos->puedeUsuarios = true;
				permisos->puedeCombustibles = true;
				permisos->puedeTanques = true;
				permisos->puedeBombas = true;
				permisos->puedeInventario = true;
				permisos->puedeVentas = true;
				permisos->puedeReportes = true;
			}
			else if (usuario->nombreRol == "Empleado") {
				permisos->puedeUsuarios = false;
				permisos->puedeCombustibles = true;
				permisos->puedeTanques = true;
				permisos->puedeBombas = true;
				permisos->puedeInventario = true;
				permisos->puedeVentas = true;
				permisos->puedeReportes = true;
			}
			else if (usuario->nombreRol == "Cliente") {
				permisos->puedeUsuarios = false;
				permisos->puedeCombustibles = false;
				permisos->puedeTanques = false;
				permisos->puedeBombas = false;
				permisos->puedeInventario = false;
				permisos->puedeVentas = true;
				permisos->puedeReportes = false;
			}

			return permisos;
		}
	};
}
