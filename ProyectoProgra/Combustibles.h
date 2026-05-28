#pragma once

#include "ModeloCombustible.h"
#include "ControladorCombustibles.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Combustibles : public System::Windows::Forms::Form
	{
	public:
		Combustibles(void)
		{
			InitializeComponent();

			controlador = gcnew ControladorCombustibles();
			idCombustibleSeleccionado = 0;

			cargarCombustibles();
		}

	protected:
		~Combustibles()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		ControladorCombustibles^ controlador;
		int idCombustibleSeleccionado;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::Label^ lblTipo;
	private: System::Windows::Forms::Label^ lblPrecio;

	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtTipo;
	private: System::Windows::Forms::TextBox^ txtPrecio;

	private: System::Windows::Forms::CheckBox^ chkActivo;

	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnActualizar;
	private: System::Windows::Forms::Button^ btnCambiarEstado;
	private: System::Windows::Forms::Button^ btnCerrar;

	private: System::Windows::Forms::DataGridView^ dgvCombustibles;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->lblTipo = (gcnew System::Windows::Forms::Label());
			this->lblPrecio = (gcnew System::Windows::Forms::Label());

			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtTipo = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());

			this->chkActivo = (gcnew System::Windows::Forms::CheckBox());

			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnCambiarEstado = (gcnew System::Windows::Forms::Button());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());

			this->dgvCombustibles = (gcnew System::Windows::Forms::DataGridView());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCombustibles))->BeginInit();
			this->SuspendLayout();

			// 
			// Combustibles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(900, 600);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Combustibles";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gesti\u00F3n de Combustibles";

			// 
			// lblTitulo
			// 
			this->lblTitulo->Font = (gcnew System::Drawing::Font(
				L"Arial Rounded MT Bold",
				18,
				System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)
			));
			this->lblTitulo->Location = System::Drawing::Point(30, 20);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(820, 40);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"GESTI\u00D3N DE COMBUSTIBLES";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// lblNombre
			// 
			this->lblNombre->Location = System::Drawing::Point(35, 90);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(180, 20);
			this->lblNombre->TabIndex = 1;
			this->lblNombre->Text = L"Nombre combustible";

			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(35, 115);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(280, 22);
			this->txtNombre->TabIndex = 2;

			// 
			// lblTipo
			// 
			this->lblTipo->Location = System::Drawing::Point(340, 90);
			this->lblTipo->Name = L"lblTipo";
			this->lblTipo->Size = System::Drawing::Size(160, 20);
			this->lblTipo->TabIndex = 3;
			this->lblTipo->Text = L"Tipo combustible";

			// 
			// txtTipo
			// 
			this->txtTipo->Location = System::Drawing::Point(340, 115);
			this->txtTipo->Name = L"txtTipo";
			this->txtTipo->Size = System::Drawing::Size(220, 22);
			this->txtTipo->TabIndex = 4;

			// 
			// lblPrecio
			// 
			this->lblPrecio->Location = System::Drawing::Point(590, 90);
			this->lblPrecio->Name = L"lblPrecio";
			this->lblPrecio->Size = System::Drawing::Size(160, 20);
			this->lblPrecio->TabIndex = 5;
			this->lblPrecio->Text = L"Precio por gal\u00F3n";

			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(590, 115);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(150, 22);
			this->txtPrecio->TabIndex = 6;

			// 
			// chkActivo
			// 
			this->chkActivo->Checked = true;
			this->chkActivo->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkActivo->Location = System::Drawing::Point(770, 115);
			this->chkActivo->Name = L"chkActivo";
			this->chkActivo->Size = System::Drawing::Size(100, 24);
			this->chkActivo->TabIndex = 7;
			this->chkActivo->Text = L"Activo";

			// 
			// btnNuevo
			// 
			configurarBoton(this->btnNuevo, L"NUEVO", 35, 170, 8);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Click += gcnew System::EventHandler(this, &Combustibles::btnNuevo_Click);

			// 
			// btnGuardar
			// 
			configurarBoton(this->btnGuardar, L"GUARDAR", 180, 170, 9);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Click += gcnew System::EventHandler(this, &Combustibles::btnGuardar_Click);

			// 
			// btnActualizar
			// 
			configurarBoton(this->btnActualizar, L"ACTUALIZAR", 325, 170, 10);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Combustibles::btnActualizar_Click);

			// 
			// btnCambiarEstado
			// 
			configurarBoton(this->btnCambiarEstado, L"ACTIVAR / DESACTIVAR", 490, 170, 11);
			this->btnCambiarEstado->Name = L"btnCambiarEstado";
			this->btnCambiarEstado->Size = System::Drawing::Size(180, 38);
			this->btnCambiarEstado->Click += gcnew System::EventHandler(this, &Combustibles::btnCambiarEstado_Click);

			// 
			// btnCerrar
			// 
			configurarBotonGris(this->btnCerrar, L"CERRAR", 700, 170, 12);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Combustibles::btnCerrar_Click);

			// 
			// dgvCombustibles
			// 
			this->dgvCombustibles->AllowUserToAddRows = false;
			this->dgvCombustibles->AllowUserToDeleteRows = false;
			this->dgvCombustibles->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvCombustibles->BackgroundColor = System::Drawing::Color::White;
			this->dgvCombustibles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCombustibles->Location = System::Drawing::Point(35, 235);
			this->dgvCombustibles->Name = L"dgvCombustibles";
			this->dgvCombustibles->ReadOnly = true;
			this->dgvCombustibles->RowHeadersWidth = 51;
			this->dgvCombustibles->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCombustibles->Size = System::Drawing::Size(830, 310);
			this->dgvCombustibles->TabIndex = 13;
			this->dgvCombustibles->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Combustibles::dgvCombustibles_CellClick);

			// 
			// Agregar controles
			// 
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblTipo);
			this->Controls->Add(this->txtTipo);
			this->Controls->Add(this->lblPrecio);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->chkActivo);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnCambiarEstado);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->dgvCombustibles);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCombustibles))->EndInit();

			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

	private: void configurarBoton(Button^ boton, String^ texto, int x, int y, int tabIndex) {
		boton->BackColor = System::Drawing::Color::DodgerBlue;
		boton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		boton->ForeColor = System::Drawing::Color::White;
		boton->Location = System::Drawing::Point(x, y);
		boton->Size = System::Drawing::Size(130, 38);
		boton->TabIndex = tabIndex;
		boton->Text = texto;
		boton->UseVisualStyleBackColor = false;
	}

	private: void configurarBotonGris(Button^ boton, String^ texto, int x, int y, int tabIndex) {
		configurarBoton(boton, texto, x, y, tabIndex);
		boton->BackColor = System::Drawing::Color::Gray;
	}

	private: void cargarCombustibles() {
		dgvCombustibles->DataSource = controlador->listarCombustibles();
	}

	private: void limpiarFormulario() {
		idCombustibleSeleccionado = 0;

		txtNombre->Clear();
		txtTipo->Clear();
		txtPrecio->Clear();
		chkActivo->Checked = true;

		txtNombre->Focus();
	}

	private: double convertirDecimal(String^ valor) {
		double numero = 0;

		if (!Double::TryParse(valor, numero)) {
			return -1;
		}

		return numero;
	}

	private: CombustibleSistema^ obtenerDatosFormulario() {
		CombustibleSistema^ combustible = gcnew CombustibleSistema();

		combustible->idCombustible = idCombustibleSeleccionado;
		combustible->nombreCombustible = txtNombre->Text;
		combustible->tipoCombustible = txtTipo->Text;
		combustible->precioGalon = convertirDecimal(txtPrecio->Text);
		combustible->estadoCombustible = chkActivo->Checked;

		return combustible;
	}

	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarFormulario();
	}

	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		CombustibleSistema^ combustible = obtenerDatosFormulario();

		bool registrado = controlador->registrarCombustible(
			combustible,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (registrado) {
			limpiarFormulario();
			cargarCombustibles();
		}
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		CombustibleSistema^ combustible = obtenerDatosFormulario();

		bool actualizado = controlador->actualizarCombustible(
			combustible,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (actualizado) {
			limpiarFormulario();
			cargarCombustibles();
		}
	}

	private: System::Void btnCambiarEstado_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idCombustibleSeleccionado <= 0) {
			MessageBox::Show("Debe seleccionar un combustible.");
			return;
		}

		String^ mensaje = "";
		bool nuevoEstado = !chkActivo->Checked;

		bool cambiado = controlador->cambiarEstadoCombustible(
			idCombustibleSeleccionado,
			nuevoEstado,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (cambiado) {
			limpiarFormulario();
			cargarCombustibles();
		}
	}

	private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void dgvCombustibles_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) {
			return;
		}

		DataGridViewRow^ fila = dgvCombustibles->Rows[e->RowIndex];

		idCombustibleSeleccionado = Convert::ToInt32(fila->Cells["ID"]->Value);

		txtNombre->Text = Convert::ToString(fila->Cells["Nombre"]->Value);
		txtTipo->Text = Convert::ToString(fila->Cells["Tipo"]->Value);
		txtPrecio->Text = Convert::ToString(fila->Cells["PrecioGalon"]->Value);

		String^ estado = Convert::ToString(fila->Cells["Estado"]->Value);
		chkActivo->Checked = estado == "Activo";
	}
	};
}