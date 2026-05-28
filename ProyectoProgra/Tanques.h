#pragma once

#include "ModeloTanque.h"
#include "ControladorTanques.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Tanques : public System::Windows::Forms::Form
	{
	public:
		Tanques(void)
		{
			InitializeComponent();

			controlador = gcnew ControladorTanques();
			idTanqueSeleccionado = 0;

			cargarCombustibles();
			cargarTanques();
		}

	protected:
		~Tanques()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		ControladorTanques^ controlador;
		int idTanqueSeleccionado;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::Label^ lblCapacidad;
	private: System::Windows::Forms::Label^ lblNivelActual;
	private: System::Windows::Forms::Label^ lblNivelMinimo;
	private: System::Windows::Forms::Label^ lblCombustible;

	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtCapacidad;
	private: System::Windows::Forms::TextBox^ txtNivelActual;
	private: System::Windows::Forms::TextBox^ txtNivelMinimo;

	private: System::Windows::Forms::ComboBox^ cmbCombustible;
	private: System::Windows::Forms::CheckBox^ chkActivo;

	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnActualizar;
	private: System::Windows::Forms::Button^ btnCambiarEstado;
	private: System::Windows::Forms::Button^ btnCerrar;

	private: System::Windows::Forms::DataGridView^ dgvTanques;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->lblCapacidad = (gcnew System::Windows::Forms::Label());
			this->lblNivelActual = (gcnew System::Windows::Forms::Label());
			this->lblNivelMinimo = (gcnew System::Windows::Forms::Label());
			this->lblCombustible = (gcnew System::Windows::Forms::Label());

			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtCapacidad = (gcnew System::Windows::Forms::TextBox());
			this->txtNivelActual = (gcnew System::Windows::Forms::TextBox());
			this->txtNivelMinimo = (gcnew System::Windows::Forms::TextBox());

			this->cmbCombustible = (gcnew System::Windows::Forms::ComboBox());
			this->chkActivo = (gcnew System::Windows::Forms::CheckBox());

			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnCambiarEstado = (gcnew System::Windows::Forms::Button());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());

			this->dgvTanques = (gcnew System::Windows::Forms::DataGridView());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTanques))->BeginInit();
			this->SuspendLayout();

			// 
			// Tanques
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(900, 620);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Tanques";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gesti\u00F3n de Tanques";

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
			this->lblTitulo->Text = L"GESTI\u00D3N DE TANQUES";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// lblNombre
			// 
			this->lblNombre->Location = System::Drawing::Point(35, 85);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(160, 20);
			this->lblNombre->TabIndex = 1;
			this->lblNombre->Text = L"Nombre del tanque";

			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(35, 110);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(330, 22);
			this->txtNombre->TabIndex = 2;

			// 
			// lblCapacidad
			// 
			this->lblCapacidad->Location = System::Drawing::Point(390, 85);
			this->lblCapacidad->Name = L"lblCapacidad";
			this->lblCapacidad->Size = System::Drawing::Size(160, 20);
			this->lblCapacidad->TabIndex = 3;
			this->lblCapacidad->Text = L"Capacidad";

			// 
			// txtCapacidad
			// 
			this->txtCapacidad->Location = System::Drawing::Point(390, 110);
			this->txtCapacidad->Name = L"txtCapacidad";
			this->txtCapacidad->Size = System::Drawing::Size(180, 22);
			this->txtCapacidad->TabIndex = 4;

			// 
			// lblNivelActual
			// 
			this->lblNivelActual->Location = System::Drawing::Point(35, 145);
			this->lblNivelActual->Name = L"lblNivelActual";
			this->lblNivelActual->Size = System::Drawing::Size(160, 20);
			this->lblNivelActual->TabIndex = 5;
			this->lblNivelActual->Text = L"Nivel actual";

			// 
			// txtNivelActual
			// 
			this->txtNivelActual->Location = System::Drawing::Point(35, 170);
			this->txtNivelActual->Name = L"txtNivelActual";
			this->txtNivelActual->Size = System::Drawing::Size(180, 22);
			this->txtNivelActual->TabIndex = 6;

			// 
			// lblNivelMinimo
			// 
			this->lblNivelMinimo->Location = System::Drawing::Point(245, 145);
			this->lblNivelMinimo->Name = L"lblNivelMinimo";
			this->lblNivelMinimo->Size = System::Drawing::Size(160, 20);
			this->lblNivelMinimo->TabIndex = 7;
			this->lblNivelMinimo->Text = L"Nivel m\u00EDnimo";

			// 
			// txtNivelMinimo
			// 
			this->txtNivelMinimo->Location = System::Drawing::Point(245, 170);
			this->txtNivelMinimo->Name = L"txtNivelMinimo";
			this->txtNivelMinimo->Size = System::Drawing::Size(180, 22);
			this->txtNivelMinimo->TabIndex = 8;

			// 
			// lblCombustible
			// 
			this->lblCombustible->Location = System::Drawing::Point(455, 145);
			this->lblCombustible->Name = L"lblCombustible";
			this->lblCombustible->Size = System::Drawing::Size(160, 20);
			this->lblCombustible->TabIndex = 9;
			this->lblCombustible->Text = L"Combustible";

			// 
			// cmbCombustible
			// 
			this->cmbCombustible->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCombustible->Location = System::Drawing::Point(455, 170);
			this->cmbCombustible->Name = L"cmbCombustible";
			this->cmbCombustible->Size = System::Drawing::Size(280, 24);
			this->cmbCombustible->TabIndex = 10;

			// 
			// chkActivo
			// 
			this->chkActivo->Checked = true;
			this->chkActivo->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkActivo->Location = System::Drawing::Point(755, 170);
			this->chkActivo->Name = L"chkActivo";
			this->chkActivo->Size = System::Drawing::Size(100, 24);
			this->chkActivo->TabIndex = 11;
			this->chkActivo->Text = L"Activo";

			// 
			// btnNuevo
			// 
			configurarBoton(this->btnNuevo, L"NUEVO", 35, 230, 12);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Click += gcnew System::EventHandler(this, &Tanques::btnNuevo_Click);

			// 
			// btnGuardar
			// 
			configurarBoton(this->btnGuardar, L"GUARDAR", 180, 230, 13);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Click += gcnew System::EventHandler(this, &Tanques::btnGuardar_Click);

			// 
			// btnActualizar
			// 
			configurarBoton(this->btnActualizar, L"ACTUALIZAR", 325, 230, 14);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Tanques::btnActualizar_Click);

			// 
			// btnCambiarEstado
			// 
			configurarBoton(this->btnCambiarEstado, L"ACTIVAR / DESACTIVAR", 490, 230, 15);
			this->btnCambiarEstado->Name = L"btnCambiarEstado";
			this->btnCambiarEstado->Size = System::Drawing::Size(180, 38);
			this->btnCambiarEstado->Click += gcnew System::EventHandler(this, &Tanques::btnCambiarEstado_Click);

			// 
			// btnCerrar
			// 
			configurarBotonGris(this->btnCerrar, L"CERRAR", 700, 230, 16);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Tanques::btnCerrar_Click);

			// 
			// dgvTanques
			// 
			this->dgvTanques->AllowUserToAddRows = false;
			this->dgvTanques->AllowUserToDeleteRows = false;
			this->dgvTanques->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTanques->BackgroundColor = System::Drawing::Color::White;
			this->dgvTanques->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTanques->Location = System::Drawing::Point(35, 295);
			this->dgvTanques->Name = L"dgvTanques";
			this->dgvTanques->ReadOnly = true;
			this->dgvTanques->RowHeadersWidth = 51;
			this->dgvTanques->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvTanques->Size = System::Drawing::Size(830, 285);
			this->dgvTanques->TabIndex = 17;
			this->dgvTanques->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Tanques::dgvTanques_CellClick);

			// 
			// Agregar controles
			// 
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblCapacidad);
			this->Controls->Add(this->txtCapacidad);
			this->Controls->Add(this->lblNivelActual);
			this->Controls->Add(this->txtNivelActual);
			this->Controls->Add(this->lblNivelMinimo);
			this->Controls->Add(this->txtNivelMinimo);
			this->Controls->Add(this->lblCombustible);
			this->Controls->Add(this->cmbCombustible);
			this->Controls->Add(this->chkActivo);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnCambiarEstado);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->dgvTanques);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTanques))->EndInit();

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
		DataTable^ combustibles = controlador->listarCombustiblesActivos();

		if (combustibles != nullptr && combustibles->Rows->Count > 0) {
			cmbCombustible->DataSource = combustibles;
			cmbCombustible->DisplayMember = "descripcion_combustible";
			cmbCombustible->ValueMember = "id_combustible";
			cmbCombustible->SelectedIndex = 0;
		}
		else {
			MessageBox::Show("No existen combustibles activos.");
		}
	}

	private: void cargarTanques() {
		dgvTanques->DataSource = controlador->listarTanques();

		if (dgvTanques->Columns->Contains("IdCombustible")) {
			dgvTanques->Columns["IdCombustible"]->Visible = false;
		}
	}

	private: void limpiarFormulario() {
		idTanqueSeleccionado = 0;

		txtNombre->Clear();
		txtCapacidad->Clear();
		txtNivelActual->Clear();
		txtNivelMinimo->Clear();
		chkActivo->Checked = true;

		if (cmbCombustible->Items->Count > 0) {
			cmbCombustible->SelectedIndex = 0;
		}

		txtNombre->Focus();
	}

	private: double convertirDecimal(String^ valor) {
		double numero = 0;

		if (!Double::TryParse(valor, numero)) {
			return -1;
		}

		return numero;
	}

	private: int obtenerIdCombustibleSeleccionado() {
		try {
			if (cmbCombustible->SelectedValue == nullptr) {
				return 0;
			}

			return Convert::ToInt32(cmbCombustible->SelectedValue);
		}
		catch (Exception^) {
			return 0;
		}
	}

	private: TanqueSistema^ obtenerDatosFormulario() {
		TanqueSistema^ tanque = gcnew TanqueSistema();

		tanque->idTanque = idTanqueSeleccionado;
		tanque->nombreTanque = txtNombre->Text;
		tanque->capacidadTanque = convertirDecimal(txtCapacidad->Text);
		tanque->nivelActual = convertirDecimal(txtNivelActual->Text);
		tanque->nivelMinimo = convertirDecimal(txtNivelMinimo->Text);
		tanque->estadoTanque = chkActivo->Checked;
		tanque->idCombustible = obtenerIdCombustibleSeleccionado();

		return tanque;
	}

	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarFormulario();
	}

	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		TanqueSistema^ tanque = obtenerDatosFormulario();

		bool registrado = controlador->registrarTanque(
			tanque,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (registrado) {
			limpiarFormulario();
			cargarTanques();
		}
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		TanqueSistema^ tanque = obtenerDatosFormulario();

		bool actualizado = controlador->actualizarTanque(
			tanque,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (actualizado) {
			limpiarFormulario();
			cargarTanques();
		}
	}

	private: System::Void btnCambiarEstado_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idTanqueSeleccionado <= 0) {
			MessageBox::Show("Debe seleccionar un tanque.");
			return;
		}

		String^ mensaje = "";
		bool nuevoEstado = !chkActivo->Checked;

		bool cambiado = controlador->cambiarEstadoTanque(
			idTanqueSeleccionado,
			nuevoEstado,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (cambiado) {
			limpiarFormulario();
			cargarTanques();
		}
	}

	private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void dgvTanques_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) {
			return;
		}

		DataGridViewRow^ fila = dgvTanques->Rows[e->RowIndex];

		idTanqueSeleccionado = Convert::ToInt32(fila->Cells["ID"]->Value);

		txtNombre->Text = Convert::ToString(fila->Cells["Tanque"]->Value);
		txtCapacidad->Text = Convert::ToString(fila->Cells["Capacidad"]->Value);
		txtNivelActual->Text = Convert::ToString(fila->Cells["NivelActual"]->Value);
		txtNivelMinimo->Text = Convert::ToString(fila->Cells["NivelMinimo"]->Value);

		String^ estado = Convert::ToString(fila->Cells["Estado"]->Value);
		chkActivo->Checked = estado == "Activo";

		if (fila->Cells["IdCombustible"]->Value != nullptr) {
			cmbCombustible->SelectedValue = Convert::ToInt32(fila->Cells["IdCombustible"]->Value);
		}
	}
	};
}