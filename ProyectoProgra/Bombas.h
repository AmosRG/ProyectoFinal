#pragma once

#include "ModeloBomba.h"
#include "ControladorBombas.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Bombas : public System::Windows::Forms::Form
	{
	public:
		Bombas(void)
		{
			InitializeComponent();

			controlador = gcnew ControladorBombas();
			idBombaSeleccionada = 0;

			cargarTanques();
			cargarBombas();
		}

	protected:
		~Bombas()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		ControladorBombas^ controlador;
		int idBombaSeleccionada;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblNumeroBomba;
	private: System::Windows::Forms::Label^ lblTanque;

	private: System::Windows::Forms::TextBox^ txtNumeroBomba;
	private: System::Windows::Forms::ComboBox^ cmbTanque;
	private: System::Windows::Forms::CheckBox^ chkActivo;

	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnActualizar;
	private: System::Windows::Forms::Button^ btnCambiarEstado;
	private: System::Windows::Forms::Button^ btnCerrar;

	private: System::Windows::Forms::DataGridView^ dgvBombas;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblNumeroBomba = (gcnew System::Windows::Forms::Label());
			this->lblTanque = (gcnew System::Windows::Forms::Label());

			this->txtNumeroBomba = (gcnew System::Windows::Forms::TextBox());
			this->cmbTanque = (gcnew System::Windows::Forms::ComboBox());
			this->chkActivo = (gcnew System::Windows::Forms::CheckBox());

			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnCambiarEstado = (gcnew System::Windows::Forms::Button());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());

			this->dgvBombas = (gcnew System::Windows::Forms::DataGridView());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBombas))->BeginInit();
			this->SuspendLayout();

			// 
			// Bombas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(900, 580);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Bombas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gesti\u00F3n de Bombas";

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
			this->lblTitulo->Text = L"GESTI\u00D3N DE BOMBAS";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// lblNumeroBomba
			// 
			this->lblNumeroBomba->Location = System::Drawing::Point(35, 90);
			this->lblNumeroBomba->Name = L"lblNumeroBomba";
			this->lblNumeroBomba->Size = System::Drawing::Size(160, 20);
			this->lblNumeroBomba->TabIndex = 1;
			this->lblNumeroBomba->Text = L"N\u00FAmero de bomba";

			// 
			// txtNumeroBomba
			// 
			this->txtNumeroBomba->Location = System::Drawing::Point(35, 115);
			this->txtNumeroBomba->Name = L"txtNumeroBomba";
			this->txtNumeroBomba->Size = System::Drawing::Size(180, 22);
			this->txtNumeroBomba->TabIndex = 2;

			// 
			// lblTanque
			// 
			this->lblTanque->Location = System::Drawing::Point(250, 90);
			this->lblTanque->Name = L"lblTanque";
			this->lblTanque->Size = System::Drawing::Size(150, 20);
			this->lblTanque->TabIndex = 3;
			this->lblTanque->Text = L"Tanque asignado";

			// 
			// cmbTanque
			// 
			this->cmbTanque->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTanque->Location = System::Drawing::Point(250, 115);
			this->cmbTanque->Name = L"cmbTanque";
			this->cmbTanque->Size = System::Drawing::Size(400, 24);
			this->cmbTanque->TabIndex = 4;

			// 
			// chkActivo
			// 
			this->chkActivo->Checked = true;
			this->chkActivo->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkActivo->Location = System::Drawing::Point(685, 115);
			this->chkActivo->Name = L"chkActivo";
			this->chkActivo->Size = System::Drawing::Size(100, 24);
			this->chkActivo->TabIndex = 5;
			this->chkActivo->Text = L"Activo";

			// 
			// btnNuevo
			// 
			configurarBoton(this->btnNuevo, L"NUEVO", 35, 170, 6);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Click += gcnew System::EventHandler(this, &Bombas::btnNuevo_Click);

			// 
			// btnGuardar
			// 
			configurarBoton(this->btnGuardar, L"GUARDAR", 180, 170, 7);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Click += gcnew System::EventHandler(this, &Bombas::btnGuardar_Click);

			// 
			// btnActualizar
			// 
			configurarBoton(this->btnActualizar, L"ACTUALIZAR", 325, 170, 8);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Bombas::btnActualizar_Click);

			// 
			// btnCambiarEstado
			// 
			configurarBoton(this->btnCambiarEstado, L"ACTIVAR / DESACTIVAR", 490, 170, 9);
			this->btnCambiarEstado->Name = L"btnCambiarEstado";
			this->btnCambiarEstado->Size = System::Drawing::Size(180, 38);
			this->btnCambiarEstado->Click += gcnew System::EventHandler(this, &Bombas::btnCambiarEstado_Click);

			// 
			// btnCerrar
			// 
			configurarBotonGris(this->btnCerrar, L"CERRAR", 700, 170, 10);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Bombas::btnCerrar_Click);

			// 
			// dgvBombas
			// 
			this->dgvBombas->AllowUserToAddRows = false;
			this->dgvBombas->AllowUserToDeleteRows = false;
			this->dgvBombas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvBombas->BackgroundColor = System::Drawing::Color::White;
			this->dgvBombas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBombas->Location = System::Drawing::Point(35, 235);
			this->dgvBombas->Name = L"dgvBombas";
			this->dgvBombas->ReadOnly = true;
			this->dgvBombas->RowHeadersWidth = 51;
			this->dgvBombas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvBombas->Size = System::Drawing::Size(830, 285);
			this->dgvBombas->TabIndex = 11;
			this->dgvBombas->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Bombas::dgvBombas_CellClick);

			// 
			// Agregar controles
			// 
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblNumeroBomba);
			this->Controls->Add(this->txtNumeroBomba);
			this->Controls->Add(this->lblTanque);
			this->Controls->Add(this->cmbTanque);
			this->Controls->Add(this->chkActivo);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnCambiarEstado);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->dgvBombas);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBombas))->EndInit();

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

	private: void cargarTanques() {
		DataTable^ tanques = controlador->listarTanquesActivos();

		if (tanques != nullptr && tanques->Rows->Count > 0) {
			cmbTanque->DataSource = tanques;
			cmbTanque->DisplayMember = "descripcion_tanque";
			cmbTanque->ValueMember = "id_tanque";
			cmbTanque->SelectedIndex = 0;
		}
		else {
			MessageBox::Show("No existen tanques activos.");
		}
	}

	private: void cargarBombas() {
		dgvBombas->DataSource = controlador->listarBombas();

		if (dgvBombas->Columns->Contains("IdTanque")) {
			dgvBombas->Columns["IdTanque"]->Visible = false;
		}
	}

	private: void limpiarFormulario() {
		idBombaSeleccionada = 0;

		txtNumeroBomba->Clear();
		chkActivo->Checked = true;

		if (cmbTanque->Items->Count > 0) {
			cmbTanque->SelectedIndex = 0;
		}

		txtNumeroBomba->Focus();
	}

	private: int convertirEntero(String^ valor) {
		int numero = 0;

		if (!Int32::TryParse(valor, numero)) {
			return 0;
		}

		return numero;
	}

	private: int obtenerIdTanqueSeleccionado() {
		try {
			if (cmbTanque->SelectedValue == nullptr) {
				return 0;
			}

			return Convert::ToInt32(cmbTanque->SelectedValue);
		}
		catch (Exception^) {
			return 0;
		}
	}

	private: BombaSistema^ obtenerDatosFormulario() {
		BombaSistema^ bomba = gcnew BombaSistema();

		bomba->idBomba = idBombaSeleccionada;
		bomba->numeroBomba = convertirEntero(txtNumeroBomba->Text);
		bomba->estadoBomba = chkActivo->Checked;
		bomba->idTanque = obtenerIdTanqueSeleccionado();

		return bomba;
	}

	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarFormulario();
	}

	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		BombaSistema^ bomba = obtenerDatosFormulario();

		bool registrado = controlador->registrarBomba(
			bomba,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (registrado) {
			limpiarFormulario();
			cargarBombas();
		}
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		BombaSistema^ bomba = obtenerDatosFormulario();

		bool actualizado = controlador->actualizarBomba(
			bomba,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (actualizado) {
			limpiarFormulario();
			cargarBombas();
		}
	}

	private: System::Void btnCambiarEstado_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idBombaSeleccionada <= 0) {
			MessageBox::Show("Debe seleccionar una bomba.");
			return;
		}

		String^ mensaje = "";
		bool nuevoEstado = !chkActivo->Checked;

		bool cambiado = controlador->cambiarEstadoBomba(
			idBombaSeleccionada,
			nuevoEstado,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (cambiado) {
			limpiarFormulario();
			cargarBombas();
		}
	}

	private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void dgvBombas_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) {
			return;
		}

		DataGridViewRow^ fila = dgvBombas->Rows[e->RowIndex];

		idBombaSeleccionada = Convert::ToInt32(fila->Cells["ID"]->Value);

		txtNumeroBomba->Text = Convert::ToString(fila->Cells["NumeroBomba"]->Value);

		String^ estado = Convert::ToString(fila->Cells["Estado"]->Value);
		chkActivo->Checked = estado == "Activo";

		if (fila->Cells["IdTanque"]->Value != nullptr) {
			cmbTanque->SelectedValue = Convert::ToInt32(fila->Cells["IdTanque"]->Value);
		}
	}
	};
}