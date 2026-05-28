#pragma once

#include "ControladorLogin.h"
#include "Registro.h"
#include "MenuPrincipal.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			controlador = gcnew ControladorLogin();
		}

	protected:
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Label^ titulo;
	private: System::Windows::Forms::Label^ subtitulo;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Label^ lblUsuario;
	private: System::Windows::Forms::Label^ lblContrasena;
	private: System::Windows::Forms::Button^ btnIngresar;
	private: System::Windows::Forms::Button^ btnRegistra;

	private:
		ControladorLogin^ controlador;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->titulo = (gcnew System::Windows::Forms::Label());
			this->subtitulo = (gcnew System::Windows::Forms::Label());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblUsuario = (gcnew System::Windows::Forms::Label());
			this->lblContrasena = (gcnew System::Windows::Forms::Label());
			this->btnIngresar = (gcnew System::Windows::Forms::Button());
			this->btnRegistra = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// titulo
			// 
			this->titulo->AutoSize = true;
			this->titulo->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titulo->Location = System::Drawing::Point(76, 45);
			this->titulo->Name = L"titulo";
			this->titulo->Size = System::Drawing::Size(363, 27);
			this->titulo->TabIndex = 0;
			this->titulo->Text = L"CONTROL DE COMBUSTIBLE";
			this->titulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// subtitulo
			// 
			this->subtitulo->AutoSize = true;
			this->subtitulo->Font = (gcnew System::Drawing::Font(L"Arial", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->subtitulo->Location = System::Drawing::Point(193, 88);
			this->subtitulo->Name = L"subtitulo";
			this->subtitulo->Size = System::Drawing::Size(124, 19);
			this->subtitulo->TabIndex = 1;
			this->subtitulo->Text = L"Inicio de sesi\u00F3n";
			// 
			// txtUsuario
			// 
			this->txtUsuario->Location = System::Drawing::Point(121, 155);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(295, 22);
			this->txtUsuario->TabIndex = 3;
			this->txtUsuario->TextChanged += gcnew System::EventHandler(this, &Login::txtUsuario_TextChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(121, 230);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(295, 22);
			this->txtPassword->TabIndex = 5;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// lblUsuario
			// 
			this->lblUsuario->AutoSize = true;
			this->lblUsuario->Font = (gcnew System::Drawing::Font(L"Arial", 9.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsuario->Location = System::Drawing::Point(118, 131);
			this->lblUsuario->Name = L"lblUsuario";
			this->lblUsuario->Size = System::Drawing::Size(65, 19);
			this->lblUsuario->TabIndex = 2;
			this->lblUsuario->Text = L"Usuario";
			// 
			// lblContrasena
			// 
			this->lblContrasena->AutoSize = true;
			this->lblContrasena->Font = (gcnew System::Drawing::Font(L"Arial", 9.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblContrasena->Location = System::Drawing::Point(118, 205);
			this->lblContrasena->Name = L"lblContrasena";
			this->lblContrasena->Size = System::Drawing::Size(116, 24);
			this->lblContrasena->TabIndex = 4;
			this->lblContrasena->Text = L"Contrase\u00F1a";
			this->lblContrasena->Click += gcnew System::EventHandler(this, &Login::lblContrasena_Click);
			// 
			// btnIngresar
			// 
			this->btnIngresar->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnIngresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIngresar->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnIngresar->Location = System::Drawing::Point(80, 290);
			this->btnIngresar->Name = L"btnIngresar";
			this->btnIngresar->Size = System::Drawing::Size(170, 42);
			this->btnIngresar->TabIndex = 6;
			this->btnIngresar->Text = L"INGRESAR";
			this->btnIngresar->UseVisualStyleBackColor = false;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &Login::btnIngresar_Click);
			// 
			// btnRegistra
			// 
			this->btnRegistra->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnRegistra->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegistra->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegistra->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnRegistra->Location = System::Drawing::Point(275, 290);
			this->btnRegistra->Name = L"btnRegistra";
			this->btnRegistra->Size = System::Drawing::Size(170, 42);
			this->btnRegistra->TabIndex = 7;
			this->btnRegistra->Text = L"REGISTRAR";
			this->btnRegistra->UseVisualStyleBackColor = false;
			this->btnRegistra->Click += gcnew System::EventHandler(this, &Login::btnRegistra_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(551, 397);
			this->Controls->Add(this->btnRegistra);
			this->Controls->Add(this->btnIngresar);
			this->Controls->Add(this->lblContrasena);
			this->Controls->Add(this->lblUsuario);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtUsuario);
			this->Controls->Add(this->subtitulo);
			this->Controls->Add(this->titulo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login - Control de Combustible";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnRegistra_Click(System::Object^ sender, System::EventArgs^ e) {
		Registro^ formulario = gcnew Registro();
		formulario->ShowDialog();
	}

	private: System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {

		if (String::IsNullOrWhiteSpace(txtUsuario->Text)) {
			MessageBox::Show("Debe ingresar el usuario.");
			txtUsuario->Focus();
			return;
		}

		if (String::IsNullOrWhiteSpace(txtPassword->Text)) {
			MessageBox::Show("Debe ingresar la contraseña.");
			txtPassword->Focus();
			return;
		}

		Usuario^ usuarioEncontrado = controlador->validarLogin(
			txtUsuario->Text,
			txtPassword->Text
		);

		if (usuarioEncontrado != nullptr) {
			MessageBox::Show("Bienvenido: " + usuarioEncontrado->nombre +
				"\nRol: " + usuarioEncontrado->nombreRol);

			this->Hide();

			MenuPrincipal^ menu = gcnew MenuPrincipal(usuarioEncontrado);
			menu->ShowDialog();

			txtPassword->Clear();
			txtUsuario->Clear();

			this->Show();
		}
		else {
			MessageBox::Show("Usuario o contraseña incorrectos, o el usuario está inactivo.");
			txtPassword->Clear();
			txtPassword->Focus();
		}
	}
	private: System::Void lblContrasena_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void txtUsuario_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
