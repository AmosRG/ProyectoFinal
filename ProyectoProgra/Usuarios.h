#pragma once

#include "ModeloGestionUsuario.h"
#include "ControladorUsuarios.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Usuarios : public System::Windows::Forms::Form
	{
	public:
		Usuarios(void)
		{
			InitializeComponent();

			controlador = gcnew ControladorUsuarios();
			idUsuarioSeleccionado = 0;

			cargarRoles();
			cargarUsuarios();
		}

	protected:
		~Usuarios()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		ControladorUsuarios^ controlador;
		int idUsuarioSeleccionado;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::Label^ lblCorreo;
	private: System::Windows::Forms::Label^ lblUsuario;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::Label^ lblConfirmar;
	private: System::Windows::Forms::Label^ lblRol;

	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtCorreo;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtConfirmar;

	private: System::Windows::Forms::ComboBox^ cmbRol;
	private: System::Windows::Forms::CheckBox^ chkActivo;

	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnActualizar;
	private: System::Windows::Forms::Button^ btnCambiarEstado;
	private: System::Windows::Forms::Button^ btnCerrar;

	private: System::Windows::Forms::DataGridView^ dgvUsuarios;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->lblCorreo = (gcnew System::Windows::Forms::Label());
			this->lblUsuario = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblConfirmar = (gcnew System::Windows::Forms::Label());
			this->lblRol = (gcnew System::Windows::Forms::Label());

			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtConfirmar = (gcnew System::Windows::Forms::TextBox());

			this->cmbRol = (gcnew System::Windows::Forms::ComboBox());
			this->chkActivo = (gcnew System::Windows::Forms::CheckBox());

			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnCambiarEstado = (gcnew System::Windows::Forms::Button());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());

			this->dgvUsuarios = (gcnew System::Windows::Forms::DataGridView());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsuarios))->BeginInit();
			this->SuspendLayout();

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(900, 620);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"FrmUsuarios";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gesti\u00F3n de Usuarios";

			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Bold));
			this->lblTitulo->Location = System::Drawing::Point(30, 20);
			this->lblTitulo->Size = System::Drawing::Size(820, 40);
			this->lblTitulo->Text = L"GESTI\u00D3N DE USUARIOS";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			this->lblNombre->Location = System::Drawing::Point(35, 85);
			this->lblNombre->Size = System::Drawing::Size(160, 20);
			this->lblNombre->Text = L"Nombre completo";

			this->txtNombre->Location = System::Drawing::Point(35, 110);
			this->txtNombre->Size = System::Drawing::Size(330, 22);

			this->lblCorreo->Location = System::Drawing::Point(390, 85);
			this->lblCorreo->Size = System::Drawing::Size(160, 20);
			this->lblCorreo->Text = L"Correo";

			this->txtCorreo->Location = System::Drawing::Point(390, 110);
			this->txtCorreo->Size = System::Drawing::Size(330, 22);

			this->lblUsuario->Location = System::Drawing::Point(35, 145);
			this->lblUsuario->Size = System::Drawing::Size(160, 20);
			this->lblUsuario->Text = L"Usuario";

			this->txtUsuario->Location = System::Drawing::Point(35, 170);
			this->txtUsuario->Size = System::Drawing::Size(330, 22);

			this->lblPassword->Location = System::Drawing::Point(390, 145);
			this->lblPassword->Size = System::Drawing::Size(160, 20);
			this->lblPassword->Text = L"Contrase\u00F1a";

			this->txtPassword->Location = System::Drawing::Point(390, 170);
			this->txtPassword->Size = System::Drawing::Size(330, 22);
			this->txtPassword->UseSystemPasswordChar = true;

			this->lblConfirmar->Location = System::Drawing::Point(35, 205);
			this->lblConfirmar->Size = System::Drawing::Size(190, 20);
			this->lblConfirmar->Text = L"Confirmar contrase\u00F1a";

			this->txtConfirmar->Location = System::Drawing::Point(35, 230);
			this->txtConfirmar->Size = System::Drawing::Size(330, 22);
			this->txtConfirmar->UseSystemPasswordChar = true;

			this->lblRol->Location = System::Drawing::Point(390, 205);
			this->lblRol->Size = System::Drawing::Size(160, 20);
			this->lblRol->Text = L"Rol";

			this->cmbRol->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbRol->Location = System::Drawing::Point(390, 230);
			this->cmbRol->Size = System::Drawing::Size(220, 24);

			this->chkActivo->Location = System::Drawing::Point(635, 230);
			this->chkActivo->Size = System::Drawing::Size(100, 24);
			this->chkActivo->Text = L"Activo";
			this->chkActivo->Checked = true;

			configurarBoton(this->btnNuevo, L"NUEVO", 35, 280, 0);
			this->btnNuevo->Click += gcnew System::EventHandler(this, &Usuarios::btnNuevo_Click);

			configurarBoton(this->btnGuardar, L"GUARDAR", 180, 280, 1);
			this->btnGuardar->Click += gcnew System::EventHandler(this, &Usuarios::btnGuardar_Click);

			configurarBoton(this->btnActualizar, L"ACTUALIZAR", 325, 280, 2);
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Usuarios::btnActualizar_Click);

			configurarBoton(this->btnCambiarEstado, L"ACTIVAR / DESACTIVAR", 490, 280, 3);
			this->btnCambiarEstado->Size = System::Drawing::Size(180, 38);
			this->btnCambiarEstado->Click += gcnew System::EventHandler(this, &Usuarios::btnCambiarEstado_Click);

			configurarBotonGris(this->btnCerrar, L"CERRAR", 700, 280, 4);
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Usuarios::btnCerrar_Click);

			this->dgvUsuarios->AllowUserToAddRows = false;
			this->dgvUsuarios->AllowUserToDeleteRows = false;
			this->dgvUsuarios->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvUsuarios->BackgroundColor = System::Drawing::Color::White;
			this->dgvUsuarios->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvUsuarios->Location = System::Drawing::Point(35, 340);
			this->dgvUsuarios->ReadOnly = true;
			this->dgvUsuarios->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvUsuarios->Size = System::Drawing::Size(830, 240);
			this->dgvUsuarios->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Usuarios::dgvUsuarios_CellClick);

			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblCorreo);
			this->Controls->Add(this->txtCorreo);
			this->Controls->Add(this->lblUsuario);
			this->Controls->Add(this->txtUsuario);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblConfirmar);
			this->Controls->Add(this->txtConfirmar);
			this->Controls->Add(this->lblRol);
			this->Controls->Add(this->cmbRol);
			this->Controls->Add(this->chkActivo);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnCambiarEstado);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->dgvUsuarios);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsuarios))->EndInit();
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

	private: void cargarRoles() {
		DataTable^ roles = controlador->listarRoles();

		if (roles != nullptr && roles->Rows->Count > 0) {
			cmbRol->DataSource = roles;
			cmbRol->DisplayMember = "nombre_rol";
			cmbRol->ValueMember = "id_rol";
			cmbRol->SelectedIndex = 0;
		}
		else {
			MessageBox::Show("No existen roles registrados.");
		}
	}

	private: void cargarUsuarios() {
		dgvUsuarios->DataSource = controlador->listarUsuarios();

		if (dgvUsuarios->Columns->Contains("IdRol")) {
			dgvUsuarios->Columns["IdRol"]->Visible = false;
		}
	}

	private: void limpiarFormulario() {
		idUsuarioSeleccionado = 0;

		txtNombre->Clear();
		txtCorreo->Clear();
		txtUsuario->Clear();
		txtPassword->Clear();
		txtConfirmar->Clear();
		chkActivo->Checked = true;

		if (cmbRol->Items->Count > 0) {
			cmbRol->SelectedIndex = 0;
		}

		txtNombre->Focus();
	}

	private: UsuarioSistema^ obtenerDatosFormulario() {
		UsuarioSistema^ usuario = gcnew UsuarioSistema();

		usuario->idUsuario = idUsuarioSeleccionado;
		usuario->nombre = txtNombre->Text;
		usuario->correo = txtCorreo->Text;
		usuario->nombreUsuario = txtUsuario->Text;
		usuario->contrasenaUsuario = txtPassword->Text;
		usuario->estadoUsuario = chkActivo->Checked;

		if (cmbRol->SelectedValue != nullptr) {
			usuario->idRol = Convert::ToInt32(cmbRol->SelectedValue);
		}

		return usuario;
	}

	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarFormulario();
	}

	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		UsuarioSistema^ usuario = obtenerDatosFormulario();

		bool registrado = controlador->registrarUsuario(
			usuario,
			txtConfirmar->Text,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (registrado) {
			limpiarFormulario();
			cargarUsuarios();
		}
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		UsuarioSistema^ usuario = obtenerDatosFormulario();

		bool actualizado = controlador->actualizarUsuario(
			usuario,
			txtConfirmar->Text,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (actualizado) {
			limpiarFormulario();
			cargarUsuarios();
		}
	}

	private: System::Void btnCambiarEstado_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idUsuarioSeleccionado <= 0) {
			MessageBox::Show("Debe seleccionar un usuario.");
			return;
		}

		String^ mensaje = "";
		bool nuevoEstado = !chkActivo->Checked;

		bool cambiado = controlador->cambiarEstadoUsuario(
			idUsuarioSeleccionado,
			nuevoEstado,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (cambiado) {
			limpiarFormulario();
			cargarUsuarios();
		}
	}

	private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void dgvUsuarios_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) {
			return;
		}

		DataGridViewRow^ fila = dgvUsuarios->Rows[e->RowIndex];

		idUsuarioSeleccionado = Convert::ToInt32(fila->Cells["ID"]->Value);

		txtNombre->Text = Convert::ToString(fila->Cells["Nombre"]->Value);
		txtCorreo->Text = Convert::ToString(fila->Cells["Correo"]->Value);
		txtUsuario->Text = Convert::ToString(fila->Cells["Usuario"]->Value);

		txtPassword->Clear();
		txtConfirmar->Clear();

		String^ estado = Convert::ToString(fila->Cells["Estado"]->Value);
		chkActivo->Checked = estado == "Activo";

		if (fila->Cells["IdRol"]->Value != nullptr) {
			cmbRol->SelectedValue = Convert::ToInt32(fila->Cells["IdRol"]->Value);
		}
	}
};
}