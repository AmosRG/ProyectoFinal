#pragma once

#include "ControladorRegistro.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Registro : public System::Windows::Forms::Form
	{
	public:
		Registro(void)
		{
			InitializeComponent();

			controlador = gcnew ControladorRegistroUsuario();
			cargarRoles();
		}

	protected:
		~Registro()
		{
			if (components)
			{
				delete components;
			}
		}

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

	private: System::Windows::Forms::ComboBox^ cmRol;

	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnCancelar;

	private:
		ControladorRegistroUsuario^ controlador;
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

			this->cmRol = (gcnew System::Windows::Forms::ComboBox());

			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());

			this->SuspendLayout();

			this->lblTitulo->AutoSize = false;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(
				L"Arial Rounded MT Bold",
				14,
				System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)
			));
			this->lblTitulo->Location = System::Drawing::Point(60, 35);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(380, 35);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"REGISTRO DE USUARIO";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			this->lblNombre->AutoSize = true;
			this->lblNombre->Location = System::Drawing::Point(65, 95);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(117, 16);
			this->lblNombre->TabIndex = 1;
			this->lblNombre->Text = L"Nombre completo";

			this->txtNombre->Location = System::Drawing::Point(65, 120);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(350, 22);
			this->txtNombre->TabIndex = 2;

			this->lblCorreo->AutoSize = true;
			this->lblCorreo->Location = System::Drawing::Point(65, 160);
			this->lblCorreo->Name = L"lblCorreo";
			this->lblCorreo->Size = System::Drawing::Size(48, 16);
			this->lblCorreo->TabIndex = 3;
			this->lblCorreo->Text = L"Correo";

			this->txtCorreo->Location = System::Drawing::Point(65, 185);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(350, 22);
			this->txtCorreo->TabIndex = 4;

			this->lblUsuario->AutoSize = true;
			this->lblUsuario->Location = System::Drawing::Point(65, 225);
			this->lblUsuario->Name = L"lblUsuario";
			this->lblUsuario->Size = System::Drawing::Size(125, 16);
			this->lblUsuario->TabIndex = 5;
			this->lblUsuario->Text = L"Nombre de usuario";

			this->txtUsuario->Location = System::Drawing::Point(65, 250);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(350, 22);
			this->txtUsuario->TabIndex = 6;

			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(65, 290);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(76, 16);
			this->lblPassword->TabIndex = 7;
			this->lblPassword->Text = L"Contrase\u00F1a";

			this->txtPassword->Location = System::Drawing::Point(65, 315);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(350, 22);
			this->txtPassword->TabIndex = 8;
			this->txtPassword->UseSystemPasswordChar = true;

			this->lblConfirmar->AutoSize = true;
			this->lblConfirmar->Location = System::Drawing::Point(65, 355);
			this->lblConfirmar->Name = L"lblConfirmar";
			this->lblConfirmar->Size = System::Drawing::Size(134, 16);
			this->lblConfirmar->TabIndex = 9;
			this->lblConfirmar->Text = L"Confirmar Contrase\u00F1a";

			this->txtConfirmar->Location = System::Drawing::Point(65, 380);
			this->txtConfirmar->Name = L"txtConfirmar";
			this->txtConfirmar->Size = System::Drawing::Size(350, 22);
			this->txtConfirmar->TabIndex = 10;
			this->txtConfirmar->UseSystemPasswordChar = true;

			this->lblRol->AutoSize = true;
			this->lblRol->Location = System::Drawing::Point(65, 420);
			this->lblRol->Name = L"lblRol";
			this->lblRol->Size = System::Drawing::Size(28, 16);
			this->lblRol->TabIndex = 11;
			this->lblRol->Text = L"Rol";

			this->cmRol->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmRol->FormattingEnabled = true;
			this->cmRol->Location = System::Drawing::Point(65, 445);
			this->cmRol->Name = L"cmRol";
			this->cmRol->Size = System::Drawing::Size(350, 24);
			this->cmRol->TabIndex = 12;

			this->btnGuardar->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnGuardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGuardar->ForeColor = System::Drawing::Color::White;
			this->btnGuardar->Location = System::Drawing::Point(65, 505);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(155, 40);
			this->btnGuardar->TabIndex = 13;
			this->btnGuardar->Text = L"GUARDAR";
			this->btnGuardar->UseVisualStyleBackColor = false;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &Registro::btnGuardar_Click);

			this->btnCancelar->BackColor = System::Drawing::Color::Gray;
			this->btnCancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(260, 505);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(155, 40);
			this->btnCancelar->TabIndex = 14;
			this->btnCancelar->Text = L"CANCELAR";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &Registro::btnCancelar_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(490, 590);
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
			this->Controls->Add(this->cmRol);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnCancelar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Registro";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Registro de Usuario";
			this->Load += gcnew System::EventHandler(this, &Registro::Registro_Load);

			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

	private: System::Void Registro_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: void cargarRoles() {
		try {
			DataTable^ tablaRoles = controlador->listarRoles();

			if (tablaRoles != nullptr && tablaRoles->Rows->Count > 0) {
				this->cmRol->DataSource = tablaRoles;
				this->cmRol->DisplayMember = "nombre_rol";
				this->cmRol->ValueMember = "id_rol";
				this->cmRol->SelectedIndex = 0;
			}
			else {
				MessageBox::Show("No existen roles registrados. Debe crear roles en tbl_rol.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cargar roles: " + ex->Message);
		}
	}

	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {

		if (cmRol->SelectedValue == nullptr) {
			MessageBox::Show("Debe seleccionar un rol.");
			return;
		}

		String^ mensaje = "";
		int idRol = Convert::ToInt32(cmRol->SelectedValue);

		bool registrado = controlador->registrarUsuario(
			txtNombre->Text,
			txtCorreo->Text,
			txtUsuario->Text,
			txtPassword->Text,
			txtConfirmar->Text,
			idRol,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (registrado) {
			txtNombre->Clear();
			txtCorreo->Clear();
			txtUsuario->Clear();
			txtPassword->Clear();
			txtConfirmar->Clear();

			if (cmRol->Items->Count > 0) {
				cmRol->SelectedIndex = 0;
			}

			txtNombre->Focus();
		}
	}

	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
