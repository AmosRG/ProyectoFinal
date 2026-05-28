#pragma once

#include "ModeloReporte.h"
#include "ControladorReportes.h"

namespace ProyectoProgra {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Reportes : public System::Windows::Forms::Form
	{
	public:
		Reportes(void)
		{
			InitializeComponent();

			controlador = gcnew ControladorReportes();

			cargarTiposReporte();
		}

	protected:
		~Reportes()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		ControladorReportes^ controlador;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblTipoReporte;
	private: System::Windows::Forms::Label^ lblFechaInicio;
	private: System::Windows::Forms::Label^ lblFechaFin;
	private: System::Windows::Forms::Label^ lblResumen;

	private: System::Windows::Forms::ComboBox^ cmbTipoReporte;
	private: System::Windows::Forms::DateTimePicker^ dtpFechaInicio;
	private: System::Windows::Forms::DateTimePicker^ dtpFechaFin;

	private: System::Windows::Forms::Button^ btnGenerar;
	private: System::Windows::Forms::Button^ btnActualizar;
	private: System::Windows::Forms::Button^ btnCerrar;

	private: System::Windows::Forms::DataGridView^ dgvReportes;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblTipoReporte = (gcnew System::Windows::Forms::Label());
			this->lblFechaInicio = (gcnew System::Windows::Forms::Label());
			this->lblFechaFin = (gcnew System::Windows::Forms::Label());
			this->lblResumen = (gcnew System::Windows::Forms::Label());

			this->cmbTipoReporte = (gcnew System::Windows::Forms::ComboBox());
			this->dtpFechaInicio = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpFechaFin = (gcnew System::Windows::Forms::DateTimePicker());

			this->btnGenerar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());

			this->dgvReportes = (gcnew System::Windows::Forms::DataGridView());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReportes))->BeginInit();
			this->SuspendLayout();

			// 
			// Reportes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(950, 640);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Reportes";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reportes";

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
			this->lblTitulo->Location = System::Drawing::Point(35, 20);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(870, 40);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"REPORTES DEL SISTEMA";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// lblTipoReporte
			// 
			this->lblTipoReporte->Location = System::Drawing::Point(35, 85);
			this->lblTipoReporte->Name = L"lblTipoReporte";
			this->lblTipoReporte->Size = System::Drawing::Size(150, 20);
			this->lblTipoReporte->TabIndex = 1;
			this->lblTipoReporte->Text = L"Tipo de reporte";

			// 
			// cmbTipoReporte
			// 
			this->cmbTipoReporte->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTipoReporte->Location = System::Drawing::Point(35, 110);
			this->cmbTipoReporte->Name = L"cmbTipoReporte";
			this->cmbTipoReporte->Size = System::Drawing::Size(280, 24);
			this->cmbTipoReporte->TabIndex = 2;

			// 
			// lblFechaInicio
			// 
			this->lblFechaInicio->Location = System::Drawing::Point(340, 85);
			this->lblFechaInicio->Name = L"lblFechaInicio";
			this->lblFechaInicio->Size = System::Drawing::Size(150, 20);
			this->lblFechaInicio->TabIndex = 3;
			this->lblFechaInicio->Text = L"Fecha inicio";

			// 
			// dtpFechaInicio
			// 
			this->dtpFechaInicio->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaInicio->Location = System::Drawing::Point(340, 110);
			this->dtpFechaInicio->Name = L"dtpFechaInicio";
			this->dtpFechaInicio->Size = System::Drawing::Size(150, 22);
			this->dtpFechaInicio->TabIndex = 4;

			// 
			// lblFechaFin
			// 
			this->lblFechaFin->Location = System::Drawing::Point(515, 85);
			this->lblFechaFin->Name = L"lblFechaFin";
			this->lblFechaFin->Size = System::Drawing::Size(150, 20);
			this->lblFechaFin->TabIndex = 5;
			this->lblFechaFin->Text = L"Fecha fin";

			// 
			// dtpFechaFin
			// 
			this->dtpFechaFin->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaFin->Location = System::Drawing::Point(515, 110);
			this->dtpFechaFin->Name = L"dtpFechaFin";
			this->dtpFechaFin->Size = System::Drawing::Size(150, 22);
			this->dtpFechaFin->TabIndex = 6;

			// 
			// Botones
			// 
			configurarBoton(this->btnGenerar, L"GENERAR", 690, 100, 7);
			this->btnGenerar->Name = L"btnGenerar";
			this->btnGenerar->Click += gcnew System::EventHandler(this, &Reportes::btnGenerar_Click);

			configurarBoton(this->btnActualizar, L"ACTUALIZAR", 35, 155, 8);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Reportes::btnActualizar_Click);

			configurarBotonGris(this->btnCerrar, L"CERRAR", 180, 155, 9);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Reportes::btnCerrar_Click);

			// 
			// lblResumen
			// 
			this->lblResumen->Font = (gcnew System::Drawing::Font(
				L"Arial",
				10,
				System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)
			));
			this->lblResumen->Location = System::Drawing::Point(340, 160);
			this->lblResumen->Name = L"lblResumen";
			this->lblResumen->Size = System::Drawing::Size(570, 25);
			this->lblResumen->TabIndex = 10;
			this->lblResumen->Text = L"Registros encontrados: 0";

			// 
			// dgvReportes
			// 
			this->dgvReportes->AllowUserToAddRows = false;
			this->dgvReportes->AllowUserToDeleteRows = false;
			this->dgvReportes->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvReportes->BackgroundColor = System::Drawing::Color::White;
			this->dgvReportes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvReportes->Location = System::Drawing::Point(35, 205);
			this->dgvReportes->Name = L"dgvReportes";
			this->dgvReportes->ReadOnly = true;
			this->dgvReportes->RowHeadersWidth = 51;
			this->dgvReportes->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvReportes->Size = System::Drawing::Size(875, 390);
			this->dgvReportes->TabIndex = 11;

			// 
			// Agregar controles
			// 
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblTipoReporte);
			this->Controls->Add(this->cmbTipoReporte);
			this->Controls->Add(this->lblFechaInicio);
			this->Controls->Add(this->dtpFechaInicio);
			this->Controls->Add(this->lblFechaFin);
			this->Controls->Add(this->dtpFechaFin);
			this->Controls->Add(this->btnGenerar);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->lblResumen);
			this->Controls->Add(this->dgvReportes);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReportes))->EndInit();

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

	private: void cargarTiposReporte() {
		cmbTipoReporte->Items->Clear();

		cmbTipoReporte->Items->Add("Ventas resumen");
		cmbTipoReporte->Items->Add("Ventas detalle");
		cmbTipoReporte->Items->Add("Inventario actual");
		cmbTipoReporte->Items->Add("Movimientos de inventario");
		cmbTipoReporte->Items->Add("Tanques bajo minimo");

		cmbTipoReporte->SelectedIndex = 0;
	}

	private: void generarReporte() {
		if (cmbTipoReporte->SelectedItem == nullptr) {
			MessageBox::Show("Debe seleccionar un tipo de reporte.");
			return;
		}

		if (dtpFechaInicio->Value.Date > dtpFechaFin->Value.Date) {
			MessageBox::Show("La fecha inicio no puede ser mayor que la fecha fin.");
			return;
		}

		String^ tipoReporte = Convert::ToString(cmbTipoReporte->SelectedItem);

		DataTable^ tabla = controlador->generarReporte(
			tipoReporte,
			dtpFechaInicio->Value,
			dtpFechaFin->Value
		);

		dgvReportes->DataSource = tabla;

		lblResumen->Text = controlador->obtenerResumenReporte(
			tipoReporte,
			tabla
		);
	}

	private: System::Void btnGenerar_Click(System::Object^ sender, System::EventArgs^ e) {
		generarReporte();
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
		generarReporte();
	}

	private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}