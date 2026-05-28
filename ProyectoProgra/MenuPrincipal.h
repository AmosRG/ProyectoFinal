#pragma once

#include "ControladorMenu.h"
#include "Usuarios.h"
#include "Tanques.h"
#include "Inventario.h"
#include "Reportes.h"
#include "Combustibles.h"
#include "Ventas.h"
#include "Bombas.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(Usuario^ usuarioLogueado)
		{
			InitializeComponent();

			usuarioActual = usuarioLogueado;

			lblBienvenido->Text = "Bienvenido: " + usuarioActual->nombre;
			lblRol->Text = "Rol: " + usuarioActual->nombreRol;

			aplicarPermisos();
		}

	protected:
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Usuario^ usuarioActual;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblBienvenido;
	private: System::Windows::Forms::Label^ lblRol;

	private: System::Windows::Forms::Button^ btnUsuarios;
	private: System::Windows::Forms::Button^ btnCombustibles;
	private: System::Windows::Forms::Button^ btnTanques;
	private: System::Windows::Forms::Button^ btnBombas;
	private: System::Windows::Forms::Button^ btnInventario;
	private: System::Windows::Forms::Button^ btnVentas;
	private: System::Windows::Forms::Button^ btnReportes;
	private: System::Windows::Forms::Button^ btnCerrarSesion;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblBienvenido = (gcnew System::Windows::Forms::Label());
			this->lblRol = (gcnew System::Windows::Forms::Label());
			this->btnUsuarios = (gcnew System::Windows::Forms::Button());
			this->btnCombustibles = (gcnew System::Windows::Forms::Button());
			this->btnTanques = (gcnew System::Windows::Forms::Button());
			this->btnBombas = (gcnew System::Windows::Forms::Button());
			this->btnInventario = (gcnew System::Windows::Forms::Button());
			this->btnVentas = (gcnew System::Windows::Forms::Button());
			this->btnReportes = (gcnew System::Windows::Forms::Button());
			this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->lblTitulo->Location = System::Drawing::Point(40, 30);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(640, 40);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"SISTEMA CONTROL DE COMBUSTIBLE";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblTitulo->Click += gcnew System::EventHandler(this, &MenuPrincipal::lblTitulo_Click);
			// 
			// lblBienvenido
			// 
			this->lblBienvenido->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBienvenido->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->lblBienvenido->Location = System::Drawing::Point(40, 80);
			this->lblBienvenido->Name = L"lblBienvenido";
			this->lblBienvenido->Size = System::Drawing::Size(640, 25);
			this->lblBienvenido->TabIndex = 1;
			this->lblBienvenido->Text = L"Bienvenido:";
			this->lblBienvenido->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblBienvenido->Click += gcnew System::EventHandler(this, &MenuPrincipal::lblBienvenido_Click);
			// 
			// lblRol
			// 
			this->lblRol->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRol->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblRol->Location = System::Drawing::Point(40, 110);
			this->lblRol->Name = L"lblRol";
			this->lblRol->Size = System::Drawing::Size(640, 25);
			this->lblRol->TabIndex = 2;
			this->lblRol->Text = L"Rol:";
			this->lblRol->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnUsuarios
			// 
			this->btnUsuarios->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnUsuarios->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUsuarios->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUsuarios->ForeColor = System::Drawing::Color::White;
			this->btnUsuarios->Location = System::Drawing::Point(95, 170);
			this->btnUsuarios->Name = L"btnUsuarios";
			this->btnUsuarios->Size = System::Drawing::Size(220, 50);
			this->btnUsuarios->TabIndex = 3;
			this->btnUsuarios->Text = L"USUARIOS";
			this->btnUsuarios->UseVisualStyleBackColor = false;
			this->btnUsuarios->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnUsuarios_Click);
			// 
			// btnCombustibles
			// 
			this->btnCombustibles->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnCombustibles->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCombustibles->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCombustibles->ForeColor = System::Drawing::Color::White;
			this->btnCombustibles->Location = System::Drawing::Point(400, 170);
			this->btnCombustibles->Name = L"btnCombustibles";
			this->btnCombustibles->Size = System::Drawing::Size(220, 50);
			this->btnCombustibles->TabIndex = 4;
			this->btnCombustibles->Text = L"COMBUSTIBLES";
			this->btnCombustibles->UseVisualStyleBackColor = false;
			this->btnCombustibles->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnCombustibles_Click);
			// 
			// btnTanques
			// 
			this->btnTanques->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnTanques->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTanques->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTanques->ForeColor = System::Drawing::Color::White;
			this->btnTanques->Location = System::Drawing::Point(95, 245);
			this->btnTanques->Name = L"btnTanques";
			this->btnTanques->Size = System::Drawing::Size(220, 50);
			this->btnTanques->TabIndex = 5;
			this->btnTanques->Text = L"TANQUES";
			this->btnTanques->UseVisualStyleBackColor = false;
			this->btnTanques->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnTanques_Click);
			// 
			// btnBombas
			// 
			this->btnBombas->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnBombas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBombas->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBombas->ForeColor = System::Drawing::Color::White;
			this->btnBombas->Location = System::Drawing::Point(400, 245);
			this->btnBombas->Name = L"btnBombas";
			this->btnBombas->Size = System::Drawing::Size(220, 50);
			this->btnBombas->TabIndex = 6;
			this->btnBombas->Text = L"BOMBAS";
			this->btnBombas->UseVisualStyleBackColor = false;
			this->btnBombas->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnBombas_Click);
			// 
			// btnInventario
			// 
			this->btnInventario->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnInventario->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnInventario->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInventario->ForeColor = System::Drawing::Color::White;
			this->btnInventario->Location = System::Drawing::Point(95, 320);
			this->btnInventario->Name = L"btnInventario";
			this->btnInventario->Size = System::Drawing::Size(220, 50);
			this->btnInventario->TabIndex = 7;
			this->btnInventario->Text = L"INVENTARIO";
			this->btnInventario->UseVisualStyleBackColor = false;
			this->btnInventario->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnInventario_Click);
			// 
			// btnVentas
			// 
			this->btnVentas->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnVentas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVentas->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVentas->ForeColor = System::Drawing::Color::White;
			this->btnVentas->Location = System::Drawing::Point(400, 320);
			this->btnVentas->Name = L"btnVentas";
			this->btnVentas->Size = System::Drawing::Size(220, 50);
			this->btnVentas->TabIndex = 8;
			this->btnVentas->Text = L"VENTAS";
			this->btnVentas->UseVisualStyleBackColor = false;
			this->btnVentas->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnVentas_Click);
			// 
			// btnReportes
			// 
			this->btnReportes->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnReportes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReportes->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReportes->ForeColor = System::Drawing::Color::White;
			this->btnReportes->Location = System::Drawing::Point(95, 395);
			this->btnReportes->Name = L"btnReportes";
			this->btnReportes->Size = System::Drawing::Size(220, 50);
			this->btnReportes->TabIndex = 9;
			this->btnReportes->Text = L"REPORTES";
			this->btnReportes->UseVisualStyleBackColor = false;
			this->btnReportes->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnReportes_Click);
			// 
			// btnCerrarSesion
			// 
			this->btnCerrarSesion->BackColor = System::Drawing::Color::Gray;
			this->btnCerrarSesion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->btnCerrarSesion->Location = System::Drawing::Point(400, 395);
			this->btnCerrarSesion->Name = L"btnCerrarSesion";
			this->btnCerrarSesion->Size = System::Drawing::Size(220, 50);
			this->btnCerrarSesion->TabIndex = 10;
			this->btnCerrarSesion->Text = L"CERRAR SESION";
			this->btnCerrarSesion->UseVisualStyleBackColor = false;
			this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnCerrarSesion_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(720, 500);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblBienvenido);
			this->Controls->Add(this->lblRol);
			this->Controls->Add(this->btnUsuarios);
			this->Controls->Add(this->btnCombustibles);
			this->Controls->Add(this->btnTanques);
			this->Controls->Add(this->btnBombas);
			this->Controls->Add(this->btnInventario);
			this->Controls->Add(this->btnVentas);
			this->Controls->Add(this->btnReportes);
			this->Controls->Add(this->btnCerrarSesion);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Men� Principal - Control de Combustible";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->ResumeLayout(false);

		}

#pragma endregion

	private: void aplicarPermisos() {

		if (usuarioActual == nullptr) {
			return;
		}

		// Permisos b�sicos por rol.
		// Puedes cambiar estos nombres seg�n los roles exactos de tu tabla tbl_rol.

		if (usuarioActual->nombreRol == "Administrador") {
			btnUsuarios->Enabled = true;
			btnCombustibles->Enabled = true;
			btnTanques->Enabled = true;
			btnBombas->Enabled = true;
			btnInventario->Enabled = true;
			btnVentas->Enabled = true;
			btnReportes->Enabled = true;
		}
		else if (usuarioActual->nombreRol == "Empleado") {
			btnUsuarios->Enabled = false;
			btnCombustibles->Enabled = true;
			btnTanques->Enabled = true;
			btnBombas->Enabled = true;
			btnInventario->Enabled = true;
			btnVentas->Enabled = true;
			btnReportes->Enabled = true;
		}
		else if (usuarioActual->nombreRol == "Cliente") {
			btnUsuarios->Enabled = false;
			btnCombustibles->Enabled = false;
			btnTanques->Enabled = false;
			btnBombas->Enabled = false;
			btnInventario->Enabled = false;
			btnVentas->Enabled = true;
			btnReportes->Enabled = false;
		}
	}

	private: System::Void btnUsuarios_Click(System::Object^ sender, System::EventArgs^ e) {
		Usuarios^ formulario = gcnew Usuarios();
		formulario->ShowDialog();
	}

	private: System::Void btnCombustibles_Click(System::Object^ sender, System::EventArgs^ e) {
		Combustibles^ formulario = gcnew Combustibles();
		formulario->ShowDialog();
	}

	private: System::Void btnTanques_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmTanques^ formulario = gcnew FrmTanques();
		formulario->ShowDialog();
	}

	private: System::Void btnBombas_Click(System::Object^ sender, System::EventArgs^ e) {
		Bombas^ formulario = gcnew Bombas();
		formulario->ShowDialog();
	}

	private: System::Void btnInventario_Click(System::Object^ sender, System::EventArgs^ e) {
		Inventario^ formulario = gcnew Inventario(usuarioActual);
		formulario->ShowDialog();
	}

	private: System::Void btnVentas_Click(System::Object^ sender, System::EventArgs^ e) {
		Ventas^ formulario = gcnew Ventas(usuarioActual);
		formulario->ShowDialog();
	}

	private: System::Void btnReportes_Click(System::Object^ sender, System::EventArgs^ e) {
		Reportes^ formulario = gcnew Reportes();
		formulario->ShowDialog();
	}

	private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblTitulo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void lblBienvenido_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}