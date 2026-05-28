#pragma once
#include <iostream>

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace ProyectoProgra {

	public ref class dbConexion
	{
	private:
		MySqlConnection^ cnn;
		String^ servidor = "localhost";
		String^ basededatos = "ControlCombustible";
		String^ usuario = "root";
		String^ clave = "admin";
		String^ strConexion;

	public:
		dbConexion() {
			cnn = nullptr;
			strConexion = "Database=" + basededatos +
				"; Data Source=" + servidor +
				"; User Id=" + usuario +
				"; Password=" + clave + ";";
		}

		MySqlConnection^ getConexion() {
			try {
				if (cnn == nullptr || cnn->State != ConnectionState::Open) {
					cnn = gcnew MySqlConnection(strConexion);
					cnn->Open();
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error de conexión: " + ex->Message);
				cnn = nullptr;
			}

			return cnn;
		}

		void cerrarConexion() {
			if (cnn != nullptr && cnn->State == ConnectionState::Open) {
				cnn->Close();
			}
		}

		bool conexionActiva() {
			return getConexion() != nullptr;
		}

		MySqlDataReader^ ejecutaConsulta(String^ strComando) {
			if (String::IsNullOrWhiteSpace(strComando)) {
				return nullptr;
			}

			MySqlConnection^ conexion = getConexion();

			if (conexion != nullptr) {
				MySqlCommand^ sqlCmd = gcnew MySqlCommand(strComando, conexion);
				return sqlCmd->ExecuteReader();
			}

			return nullptr;
		}

		DataTable^ ejecutaConsultaTabla(String^ strComando) {
			DataTable^ dt = gcnew DataTable();

			try {
				if (String::IsNullOrWhiteSpace(strComando)) {
					return dt;
				}

				MySqlConnection^ conexion = getConexion();

				if (conexion != nullptr) {
					MySqlDataAdapter^ da = gcnew MySqlDataAdapter(strComando, conexion);
					da->Fill(dt);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al ejecutar consulta: " + ex->Message);
			}

			return dt;
		}

		int ejecutaIUD(MySqlCommand^ comando) {
			int filasAfectadas = 0;

			try {
				MySqlConnection^ conexion = getConexion();

				if (conexion != nullptr) {
					comando->Connection = conexion;
					filasAfectadas = comando->ExecuteNonQuery();
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al ejecutar operación: " + ex->Message);
			}

			return filasAfectadas;
		}
	};
}
