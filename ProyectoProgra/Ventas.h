#pragma once

#include "ModeloUsuario.h"
#include "ModeloVenta.h"
#include "ControladorVenta.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Ventas : public System::Windows::Forms::Form
	{
	public:
		Ventas(Usuario^ usuarioLogueado)
		{
			InitializeComponent();

			controlador = gcnew ControladorVenta();
			usuarioActual = usuarioLogueado;

			idClienteSeleccionado = 0;
			ultimoTotal = 0;

			if (usuarioActual != nullptr) {
				lblOperador->Text = "Operador: " + usuarioActual->nombre;
				lblRol->Text = "Rol: " + usuarioActual->nombreRol;
			}

			cargarBombas();
			cargarVentas();
		}

	protected:
		~Ventas()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Usuario^ usuarioActual;
		ControladorVenta^ controlador;

		int idClienteSeleccionado;
		double ultimoTotal;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblOperador;
	private: System::Windows::Forms::Label^ lblRol;
	private: System::Windows::Forms::Label^ lblNit;
	private: System::Windows::Forms::TextBox^ txtNit;
	private: System::Windows::Forms::Button^ btnBuscar;

	private: System::Windows::Forms::Label^ lblClienteTitulo;
	private: System::Windows::Forms::Label^ lblCliente;

	private: System::Windows::Forms::Label^ lblBomba;
	private: System::Windows::Forms::ComboBox^ cmbBomba;

	private: System::Windows::Forms::Label^ lblCantidad;
	private: System::Windows::Forms::TextBox^ txtCantidad;

	private: System::Windows::Forms::Button^ btnObtener;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnActualizar;

	private: System::Windows::Forms::Label^ lblCombustible;
	private: System::Windows::Forms::Label^ lblPrecio;
	private: System::Windows::Forms::Label^ lblNivel;
	private: System::Windows::Forms::Label^ lblSubtotal;
	private: System::Windows::Forms::Label^ lblDescuento;
	private: System::Windows::Forms::Label^ lblTotal;

	private: System::Windows::Forms::DataGridView^ dgvVentas;
	private: System::Windows::Forms::Button^ btnVisualizarVenta;
	private: System::Windows::Forms::Button^ btnCerrar;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblOperador = (gcnew System::Windows::Forms::Label());
			this->lblRol = (gcnew System::Windows::Forms::Label());
			this->lblNit = (gcnew System::Windows::Forms::Label());
			this->txtNit = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->lblClienteTitulo = (gcnew System::Windows::Forms::Label());
			this->lblCliente = (gcnew System::Windows::Forms::Label());
			this->lblBomba = (gcnew System::Windows::Forms::Label());
			this->cmbBomba = (gcnew System::Windows::Forms::ComboBox());
			this->lblCantidad = (gcnew System::Windows::Forms::Label());
			this->txtCantidad = (gcnew System::Windows::Forms::TextBox());
			this->btnObtener = (gcnew System::Windows::Forms::Button());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->lblCombustible = (gcnew System::Windows::Forms::Label());
			this->lblPrecio = (gcnew System::Windows::Forms::Label());
			this->lblNivel = (gcnew System::Windows::Forms::Label());
			this->lblSubtotal = (gcnew System::Windows::Forms::Label());
			this->lblDescuento = (gcnew System::Windows::Forms::Label());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->dgvVentas = (gcnew System::Windows::Forms::DataGridView());
			this->btnVisualizarVenta = (gcnew System::Windows::Forms::Button());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvVentas))->BeginInit();
			this->SuspendLayout();

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(860, 620);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"FrmVentas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Despacho de Combustible";

			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20, System::Drawing::FontStyle::Bold));
			this->lblTitulo->Location = System::Drawing::Point(25, 20);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(600, 40);
			this->lblTitulo->Text = L"Despacho de Combustible";

			this->lblOperador->Location = System::Drawing::Point(30, 65);
			this->lblOperador->Size = System::Drawing::Size(350, 20);
			this->lblOperador->Text = L"Operador:";

			this->lblRol->Location = System::Drawing::Point(30, 88);
			this->lblRol->Size = System::Drawing::Size(350, 20);
			this->lblRol->Text = L"Rol:";

			this->btnCerrar->BackColor = System::Drawing::Color::White;
			this->btnCerrar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCerrar->ForeColor = System::Drawing::Color::Firebrick;
			this->btnCerrar->Location = System::Drawing::Point(760, 25);
			this->btnCerrar->Size = System::Drawing::Size(70, 32);
			this->btnCerrar->Text = L"SALIR";
			this->btnCerrar->UseVisualStyleBackColor = false;
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Ventas::btnCerrar_Click);

			this->lblNit->Location = System::Drawing::Point(30, 125);
			this->lblNit->Size = System::Drawing::Size(100, 20);
			this->lblNit->Text = L"NIT:";

			this->txtNit->Location = System::Drawing::Point(30, 150);
			this->txtNit->Size = System::Drawing::Size(190, 22);

			this->btnBuscar->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnBuscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(230, 145);
			this->btnBuscar->Size = System::Drawing::Size(90, 32);
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &Ventas::btnBuscar_Click);

			this->lblClienteTitulo->Location = System::Drawing::Point(350, 125);
			this->lblClienteTitulo->Size = System::Drawing::Size(150, 20);
			this->lblClienteTitulo->Text = L"Cliente:";

			this->lblCliente->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblCliente->Location = System::Drawing::Point(350, 150);
			this->lblCliente->Size = System::Drawing::Size(480, 24);
			this->lblCliente->Text = L"Consumidor final";

			this->lblBomba->Location = System::Drawing::Point(30, 195);
			this->lblBomba->Size = System::Drawing::Size(120, 20);
			this->lblBomba->Text = L"Bomba:";

			this->cmbBomba->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBomba->Location = System::Drawing::Point(30, 220);
			this->cmbBomba->Size = System::Drawing::Size(290, 24);

			this->lblCantidad->Location = System::Drawing::Point(350, 195);
			this->lblCantidad->Size = System::Drawing::Size(150, 20);
			this->lblCantidad->Text = L"Cantidad galones:";

			this->txtCantidad->Location = System::Drawing::Point(350, 220);
			this->txtCantidad->Size = System::Drawing::Size(160, 22);

			this->btnObtener->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnObtener->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnObtener->ForeColor = System::Drawing::Color::White;
			this->btnObtener->Location = System::Drawing::Point(530, 214);
			this->btnObtener->Size = System::Drawing::Size(90, 34);
			this->btnObtener->Text = L"Obtener";
			this->btnObtener->UseVisualStyleBackColor = false;
			this->btnObtener->Click += gcnew System::EventHandler(this, &Ventas::btnObtener_Click);

			this->btnAgregar->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnAgregar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAgregar->ForeColor = System::Drawing::Color::White;
			this->btnAgregar->Location = System::Drawing::Point(635, 214);
			this->btnAgregar->Size = System::Drawing::Size(90, 34);
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = false;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &Ventas::btnAgregar_Click);

			this->btnActualizar->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnActualizar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActualizar->ForeColor = System::Drawing::Color::White;
			this->btnActualizar->Location = System::Drawing::Point(740, 214);
			this->btnActualizar->Size = System::Drawing::Size(90, 34);
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->UseVisualStyleBackColor = false;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Ventas::btnActualizar_Click);

			this->lblCombustible->Location = System::Drawing::Point(30, 270);
			this->lblCombustible->Size = System::Drawing::Size(290, 24);
			this->lblCombustible->Text = L"Combustible:";

			this->lblPrecio->Location = System::Drawing::Point(30, 300);
			this->lblPrecio->Size = System::Drawing::Size(290, 24);
			this->lblPrecio->Text = L"Precio galon: Q 0.00";

			this->lblNivel->Location = System::Drawing::Point(30, 330);
			this->lblNivel->Size = System::Drawing::Size(290, 24);
			this->lblNivel->Text = L"Nivel disponible: 0";

			this->lblSubtotal->Location = System::Drawing::Point(350, 270);
			this->lblSubtotal->Size = System::Drawing::Size(260, 24);
			this->lblSubtotal->Text = L"Subtotal: Q 0.00";

			this->lblDescuento->Location = System::Drawing::Point(350, 300);
			this->lblDescuento->Size = System::Drawing::Size(260, 24);
			this->lblDescuento->Text = L"Descuento: Q 0.00";

			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Bold));
			this->lblTotal->Location = System::Drawing::Point(350, 330);
			this->lblTotal->Size = System::Drawing::Size(260, 28);
			this->lblTotal->Text = L"TOTAL: Q 0.00";

			this->dgvVentas->AllowUserToAddRows = false;
			this->dgvVentas->AllowUserToDeleteRows = false;
			this->dgvVentas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvVentas->BackgroundColor = System::Drawing::Color::White;
			this->dgvVentas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvVentas->Location = System::Drawing::Point(30, 375);
			this->dgvVentas->ReadOnly = true;
			this->dgvVentas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvVentas->Size = System::Drawing::Size(800, 160);

			this->btnVisualizarVenta->BackColor = System::Drawing::Color::FromArgb(15, 23, 42);
			this->btnVisualizarVenta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVisualizarVenta->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->btnVisualizarVenta->ForeColor = System::Drawing::Color::White;
			this->btnVisualizarVenta->Location = System::Drawing::Point(30, 550);
			this->btnVisualizarVenta->Size = System::Drawing::Size(800, 40);
			this->btnVisualizarVenta->Text = L"VISUALIZAR VENTA";
			this->btnVisualizarVenta->UseVisualStyleBackColor = false;
			this->btnVisualizarVenta->Click += gcnew System::EventHandler(this, &Ventas::btnVisualizarVenta_Click);

			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblOperador);
			this->Controls->Add(this->lblRol);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->lblNit);
			this->Controls->Add(this->txtNit);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->lblClienteTitulo);
			this->Controls->Add(this->lblCliente);
			this->Controls->Add(this->lblBomba);
			this->Controls->Add(this->cmbBomba);
			this->Controls->Add(this->lblCantidad);
			this->Controls->Add(this->txtCantidad);
			this->Controls->Add(this->btnObtener);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->lblCombustible);
			this->Controls->Add(this->lblPrecio);
			this->Controls->Add(this->lblNivel);
			this->Controls->Add(this->lblSubtotal);
			this->Controls->Add(this->lblDescuento);
			this->Controls->Add(this->lblTotal);
			this->Controls->Add(this->dgvVentas);
			this->Controls->Add(this->btnVisualizarVenta);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvVentas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion
	private: void cargarBombas() {
		DataTable^ bombas = controlador->listarBombasActivas();

		if (bombas != nullptr && bombas->Rows->Count > 0) {
			cmbBomba->DataSource = bombas;
			cmbBomba->DisplayMember = "descripcion_bomba";
			cmbBomba->ValueMember = "id_bomba";
			cmbBomba->SelectedIndex = 0;
		}
		else {
			MessageBox::Show("No hay bombas activas disponibles.");
		}
	}

	private: void cargarVentas() {
		dgvVentas->DataSource = controlador->listarVentasRecientes();
	}

	private: double obtenerCantidad() {
		double cantidad = 0;

		if (!Double::TryParse(txtCantidad->Text, cantidad)) {
			return 0;
		}

		return cantidad;
	}

	private: int obtenerIdBomba() {
		if (cmbBomba->SelectedValue == nullptr) {
			return 0;
		}

		return Convert::ToInt32(cmbBomba->SelectedValue);
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ mensaje = "";

		ClienteVenta^ cliente = controlador->buscarClientePorNit(txtNit->Text, mensaje);

		if (cliente != nullptr) {
			idClienteSeleccionado = cliente->idCliente;
			lblCliente->Text = cliente->nombreCliente + " | NIT: " + cliente->nit;
		}

		MessageBox::Show(mensaje);
	}

	private: System::Void btnObtener_Click(System::Object^ sender, System::EventArgs^ e) {
		int idBomba = obtenerIdBomba();
		double cantidad = obtenerCantidad();

		String^ mensaje = "";

		VentaCalculo^ calculo = controlador->calcularVenta(idBomba, cantidad, mensaje);

		if (calculo != nullptr) {
			lblCombustible->Text = "Combustible: " + calculo->nombreCombustible;
			lblPrecio->Text = "Precio galon: Q " + calculo->precioUnitario.ToString("N2");
			lblNivel->Text = "Nivel disponible: " + calculo->nivelActual.ToString("N2");
			lblSubtotal->Text = "Subtotal: Q " + calculo->subtotal.ToString("N2");
			lblDescuento->Text = "Descuento: Q " + calculo->descuento.ToString("N2");
			lblTotal->Text = "TOTAL: Q " + calculo->total.ToString("N2");

			ultimoTotal = calculo->total;
		}

		MessageBox::Show(mensaje);
	}

	private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (usuarioActual == nullptr) {
			MessageBox::Show("No existe usuario logueado.");
			return;
		}

		int idBomba = obtenerIdBomba();
		double cantidad = obtenerCantidad();

		String^ mensaje = "";

		bool registrado = controlador->registrarVenta(
			idBomba,
			cantidad,
			usuarioActual->idUsuario,
			idClienteSeleccionado,
			mensaje
		);

		MessageBox::Show(mensaje);

		if (registrado) {
			txtCantidad->Clear();
			txtNit->Clear();
			idClienteSeleccionado = 0;
			ultimoTotal = 0;

			lblCliente->Text = "Consumidor final";
			lblCombustible->Text = "Combustible:";
			lblPrecio->Text = "Precio galon: Q 0.00";
			lblNivel->Text = "Nivel disponible: 0";
			lblSubtotal->Text = "Subtotal: Q 0.00";
			lblDescuento->Text = "Descuento: Q 0.00";
			lblTotal->Text = "TOTAL: Q 0.00";

			cargarBombas();
			cargarVentas();
		}
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		cargarBombas();
		cargarVentas();
		MessageBox::Show("Informacion actualizada.");
	}

	private: System::Void btnVisualizarVenta_Click(System::Object^ sender, System::EventArgs^ e) {
		cargarVentas();
		MessageBox::Show("Ventas recientes actualizadas.");
	}

	private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}