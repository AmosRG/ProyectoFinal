#pragma once

using namespace System;

namespace ProyectoProgra {

	public ref class UsuarioSistema
	{
	public:
		int idUsuario;
		String^ nombre;
		String^ correo;
		String^ nombreUsuario;
		String^ contrasenaUsuario;
		bool estadoUsuario;
		int idRol;
		String^ nombreRol;

		UsuarioSistema() {
			idUsuario = 0;
			nombre = "";
			correo = "";
			nombreUsuario = "";
			contrasenaUsuario = "";
			estadoUsuario = true;
			idRol = 0;
			nombreRol = "";
		}
	};
}