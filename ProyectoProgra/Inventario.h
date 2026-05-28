#pragma once

#include "ModeloUsuario.h"
#include "ModeloInventario.h"
#include "ControladorInventario.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Inventario : public System::Windows::Forms::Form
	{
	public:
		Inventario(Usuario^ usuarioLogueado)
		{
			InitializeComponent();

			controlador = gcnew ControladorInventario();
			usuarioActual = usuarioLogueado;

			if (usuarioActual != nullptr) {
				lblUsuarioActual->Text = "Usuario: " + usuarioActual->nombre;
			}

			cargarTiposMovimiento();
			cargarTanques();
			cargarMovimientos();
		}

	protected:
		~Inventario()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Usuario^ usuarioActual;
		ControladorInventario^ controlador;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblUsuarioActual;
	private: System::Windows::Forms::Label^ lblTanque;
	private: System::Windows::Forms::Label^ lblTipoMovimiento;
	private: System::Windows::Forms::Label^ lblCantidad;
	private: System::Windows::Forms::Label^ lblDescripcion;
	private: System::Windows::Forms::Label^ lblNivelActual;

	private: System::Windows::Forms::ComboBox^ cmbTanque;
	private: System::Windows::Forms::ComboBox^ cmbTipoMovimiento;
	private: System::Windows::Forms::TextBox^ txtCantidad;
	private: System::Windows::Forms::TextBox^ txtDescripcion;

	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnRegistrar;
	private: System::Windows::Forms::Button^ btnActualizar;
	private: System::Windows::Forms::Button^ btnCerrar;

	private: System::Windows::Forms::DataGridView^ dgvMovimientos;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblUsuarioActual = (gcnew System::Windows::Forms::Label());
			this->lblTanque = (gcnew System::Windows::Forms::Label());
			this->lblTipoMovimiento = (gcnew System::Windows::Forms::Label());
			this->lblCantidad = (gcnew System::Windows::Forms::Label());
			this->lblDescripcion = (gcnew System::Windows::Forms::Label());
			this->lblNivelActual = (gcnew System::Windows::Forms::Label());

			this->cmbTanque = (gcnew System::Windows::Forms::ComboBox());
			this->cmbTipoMovimiento = (gcnew System::Windows::Forms::ComboBox());
			this->txtCantidad = (gcnew System::Windows::Forms::TextBox());
			this->txtDescripcion = (gcnew System::Windows::Forms::TextBox());

			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());

			this->dgvMovimientos = (gcnew System::Windows::Forms::DataGridView());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMovimientos))->BeginInit();
			this->SuspendLayout();

			// 
			// Inventario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(900, 620);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Inventario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gesti\u00F3n de Inventario";

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
			this->lblTitulo->Text = L"GESTI\u00D3N DE INVENTARIO";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// lblUsuarioActual
			// 
			this->lblUsuarioActual->Location = System::Drawing::Point(35, 65);
			this->lblUsuarioActual->Name = L"lblUsuarioActual";
			this->lblUsuarioActual->Size = System::Drawing::Size(500, 22);
			this->lblUsuarioActual->TabIndex = 1;
			this->lblUsuarioActual->Text = L"Usuario:";

			// 
			// lblTanque
			// 
			this->lblTanque->Location = System::Drawing::Point(35, 105);
			this->lblTanque->Name = L"lblTanque";
			this->lblTanque->Size = System::Drawing::Size(150, 20);
			this->lblTanque->TabIndex = 2;
			this->lblTanque->Text = L"Tanque";

			// 
			// cmbTanque
			// 
			this->cmbTanque->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTanque->Location = System::Drawing::Point(35, 130);
			this->cmbTanque->Name = L"cmbTanque";
			this->cmbTanque->Size = System::Drawing::Size(400, 24);
			this->cmbTanque->TabIndex = 3;
			this->cmbTanque->SelectedIndexChanged += gcnew System::EventHandler(this, &Inventario::cmbTanque_SelectedIndexChanged);

			// 
			// lblTipoMovimiento
			// 
			this->lblTipoMovimiento->Location = System::Drawing::Point(460, 105);
			this->lblTipoMovimiento->Name = L"lblTipoMovimiento";
			this->lblTipoMovimiento->Size = System::Drawing::Size(180, 20);
			this->lblTipoMovimiento->TabIndex = 4;
			this->lblTipoMovimiento->Text = L"Tipo de movimiento";

			// 
			// cmbTipoMovimiento
			// 
			this->cmbTipoMovimiento->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTipoMovimiento->Location = System::Drawing::Point(460, 130);
			this->cmbTipoMovimiento->Name = L"cmbTipoMovimiento";
			this->cmbTipoMovimiento->Size = System::Drawing::Size(200, 24);
			this->cmbTipoMovimiento->TabIndex = 5;

			// 
			// lblCantidad
			// 
			this->lblCantidad->Location = System::Drawing::Point(690, 105);
			this->lblCantidad->Name = L"lblCantidad";
			this->lblCantidad->Size = System::Drawing::Size(150, 20);
			this->lblCantidad->TabIndex = 6;
			this->lblCantidad->Text = L"Cantidad";

			// 
			// txtCantidad
			// 
			this->txtCantidad->Location = System::Drawing::Point(690, 130);
			this->txtCantidad->Name = L"txtCantidad";
			this->txtCantidad->Size = System::Drawing::Size(150, 22);
			this->txtCantidad->TabIndex = 7;

			// 
			// lblNivelActual
			// 
			this->lblNivelActual->Font = (gcnew System::Drawing::Font(
				L"Arial",
				10,
				System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)
			));
			this->lblNivelActual->Location = System::Drawing::Point(35, 165);
			this->lblNivelActual->Name = L"lblNivelActual";
			this->lblNivelActual->Size = System::Drawing::Size(400, 25);
			this->lblNivelActual->TabIndex = 8;
			this->lblNivelActual->Text = L"Nivel actual: 0.00";

			// 
			// lblDescripcion
			// 
			this->lblDescripcion->Location = System::Drawing::Point(35, 200);
			this->lblDescripcion->Name = L"lblDescripcion";
			this->lblDescripcion->Size = System::Drawing::Size(150, 20);
			this->lblDescripcion->TabIndex = 9;
			this->lblDescripcion->Text = L"Descripci\u00F3n";

			// 
			// txtDescripcion
			// 
			this->txtDescripcion->Location = System::Drawing::Point(35, 225);
			this->txtDescripcion->Name = L"txtDescripcion";
			this->txtDescripcion->Size = System::Drawing::Size(805, 22);
			this->txtDescripcion->TabIndex = 10;

			// 
			// Botones
			// 
			configurarBoton(this->btnNuevo, L"NUEVO", 35, 270, 11);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Click += gcnew System::EventHandler(this, &Inventario::btnNuevo_Click);

			configurarBoton(this->btnRegistrar, L"REGISTRAR", 180, 270, 12);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &Inventario::btnRegistrar_Click);

			configurarBoton(this->btnActualizar, L"ACTUALIZAR", 325, 270, 13);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Inventario::btnActualizar_Click);

			configurarBotonGris(this->btnCerrar, L"CERRAR", 470, 270, 14);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Inventario::btnCerrar_Click);

			// 
			// dgvMovimientos
			// 
			this->dgvMovimientos->AllowUserToAddRows = false;
			this->dgvMovimientos->AllowUserToDeleteRows = false;
			this->dgvMovimientos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvMovimientos->BackgroundColor = System::Drawing::Color::White;
			this->dgvMovimientos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvMovimientos->Location = System::Drawing::Point(35, 330);
			this->dgvMovimientos->Name = L"dgvMovimientos";
			this->dgvMovimientos->ReadOnly = true;
			this->dgvMovimientos->RowHeadersWidth = 51;
			this->dgvMovimientos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvMovimientos->Size = System::Drawing::Size(830, 250);
			this->dgvMovimientos->TabIndex = 15;

			// 
			// Agregar controles al formulario
			// 
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblUsuarioActual);
			this->Controls->Add(this->lblTanque);
			this->Controls->Add(this->cmbTanque);
			this->Controls->Add(this->lblTipoMovimiento);
			this->Controls->Add(this->cmbTipoMovimiento);
			this->Controls->Add(this->lblCantidad);
			this->Controls->Add(this->txtCantidad);
			this->Controls->Add(this->lblNivelActual);
			this->Controls->Add(this->lblDescripcion);
			this->Controls->Add(this->txtDescripcion);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->btnRegistrar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->dgvMovimientos);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMovimientos))->EndInit();

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

	private: void cargarTiposMovimiento() {
		cmbTipoMovimiento->Items->Clear();
		cmbTipoMovimiento->Items->Add("ENTRADA");
		cmbTipoMovimiento->Items->Add("SALIDA");
		cmbTipoMovimiento->Items->Add("AJUSTE");
		cmbTipoMovimiento->SelectedIndex = 0;
	}

	private: void cargarTanques() {
		DataTable^ tanques = controlador->listarTanquesActivos();

		if (tanques != nullptr && tanques->Rows->Count > 0) {
			cmbTanque->DataSource = tanques;
			cmbTanque->DisplayMember = "descripcion_tanque";
			cmbTanque->ValueMember = "id_tanque";
			cmbTanque->SelectedIndex = 0;

			actualizarNivelActual();
		}
		else {
			MessageBox::Show("No existen tanques activos.");
		}
	}

	private: void cargarMovimientos() {
		dgvMovimientos->DataSource = controlador->listarMovimientos();

		if (dgvMovimientos->Columns->Contains("IdTanque")) {
			dgvMovimientos->Columns["IdTanque"]->Visible = false;
		}
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

	private: double convertirDecimal(String^ valor) {
		double numero = 0;

		if (!Double::TryParse(valor, numero)) {
			return -1;
		}

		return numero;
	}

	private: void actualizarNivelActual() {
		if (controlador == nullptr) {
			return;
		}

		int idTanque = obtenerIdTanqueSeleccionado();

		if (idTanque <= 0) {
			lblNivelActual->Text = "Nivel actual: 0.00";
			return;
		}

		double nivel = controlador->obtenerNivelActualTanque(idTanque);
		lblNivelActual->Text = "Nivel actual: " + nivel.ToString("N2");
	}

	private: void limpiarFormulario() {
		txtCantidad->Clear();
		txtDescripcion->Clear();

		if (cmbTipoMovimiento->Items->Count > 0) {
			cmbTipoMovimiento->SelectedIndex = 0;
		}

		if (cmbTanque->Items->Count > 0) {
			cmbTanque->SelectedIndex = 0;
		}

		actualizarNivelActual();
		txtCantidad->Focus();
	}

	private: MovimientoInventarioSistema^ obtenerDatosFormulario() {
		MovimientoInventarioSistema^ movimiento = gcnew MovimientoInventarioSistema();

		movimiento->idTanque = obtenerIdTanqueSeleccionado();
		movimiento->tipoMovimiento = Convert::ToString(cmbTipoMovimiento->SelectedItem);
		movimiento->cantidad = convertirDecimal(txtCantidad->Text);
		movimiento->descripcionMovimiento = txtDescripcion->Text;

		if (usuarioActual != nullptr) {
			movimiento->idUsuario = usuarioActual->idUsuario;
		}

		return movimiento;
	}

	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarFormulario();
	}

	private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		MovimientoInventarioSistema^ movimiento = obtenerDatosFormulario();

		bool registrado = controlador->registrarMovimiento(
			movimiento,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (registrado) {
			limpiarFormulario();
			cargarTanques();
			cargarMovimientos();
		}
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		cargarTanques();
		cargarMovimientos();
		actualizarNivelActual();

		MessageBox::Show("Informaci\u00F3n actualizada.");
	}

	private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void cmbTanque_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		actualizarNivelActual();
	}
	};
}