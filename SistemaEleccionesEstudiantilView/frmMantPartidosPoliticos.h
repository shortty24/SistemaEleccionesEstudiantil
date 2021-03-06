	#pragma once
#include "frmNuevoPartidoPolitico.h"
#include "frmEditarPartidoPolitico.h"

namespace SistemaEleccionesEstudiantilView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaEleccionesEstudiantilController;
	using namespace SistemaEleccionesEstudiantilModel;

	/// <summary>
	/// Summary for frmMantPartidosPoliticos
	/// </summary>
	public ref class frmMantPartidosPoliticos : public System::Windows::Forms::Form
	{
	public:
		frmMantPartidosPoliticos(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMantPartidosPoliticos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(488, 129);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de B?squeda";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(348, 44);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantPartidosPoliticos::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(108, 47);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(217, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 162);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(488, 231);
			this->dataGridView1->TabIndex = 3;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"C?digo";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"S?mbolo";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Fecha de Fundaci?n";
			this->Column4->Name = L"Column4";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(49, 416);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Nuevo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantPartidosPoliticos::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(204, 416);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantPartidosPoliticos::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(360, 416);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantPartidosPoliticos::button4_Click);
			// 
			// frmMantPartidosPoliticos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(519, 499);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantPartidosPoliticos";
			this->Text = L"frmMantPartidosPoliticos";
			this->Load += gcnew System::EventHandler(this, &frmMantPartidosPoliticos::frmMantPartidosPoliticos_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantPartidosPoliticos_Load(System::Object^ sender, System::EventArgs^ e) {
		PartidoPoliticoController^ gestorPartidoPolitico = gcnew PartidoPoliticoController();
		gestorPartidoPolitico->CargarPartidosDesdeArchivo();
		List<PartidoPolitico^>^ objListaPartidos = gestorPartidoPolitico->obtenerListaPartidos();
		mostrarGrilla(objListaPartidos);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		int posicionFilaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int codigoPartidoEliminar = Convert::ToInt32(this->dataGridView1->Rows[posicionFilaSeleccionada]->Cells[0]->Value->ToString());
		PartidoPoliticoController^ objGestorPartido = gcnew PartidoPoliticoController();
		objGestorPartido->eliminarPartidoPolitico(codigoPartidoEliminar);
		objGestorPartido->CargarPartidosDesdeArchivo();
		List<PartidoPolitico^>^ listaPartidos = objGestorPartido->obtenerListaPartidos();
		mostrarGrilla(listaPartidos);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		frmNuevoPartidoPolitico^ ventanaNuevoPartido = gcnew frmNuevoPartidoPolitico();
		ventanaNuevoPartido->ShowDialog();
		PartidoPoliticoController^ gestorPartidoPolitico = gcnew PartidoPoliticoController();
		gestorPartidoPolitico->CargarPartidosDesdeArchivo();
		List<PartidoPolitico^>^ objListaPartidos = gestorPartidoPolitico->obtenerListaPartidos();
		mostrarGrilla(objListaPartidos);
	}
	private: void mostrarGrilla(List<PartidoPolitico^>^ ListaPartidos) {
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < ListaPartidos->Count; i++) {
			PartidoPolitico^ objPartido = ListaPartidos[i];
			array<String^>^ fila = gcnew array<String^>(4);
			fila[0] = Convert::ToString(objPartido->codigo);
			fila[1] = objPartido->nombre;
			fila[2] = objPartido->simbolo;
			fila[3] = objPartido->fechaFundacion;
			this->dataGridView1->Rows->Add(fila);
		}
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ nombreBuscar = this->textBox1->Text;
	List<PartidoPolitico^>^ listaPartidos;
	PartidoPoliticoController^ objGestorPartido = gcnew PartidoPoliticoController();
	if (nombreBuscar == "") {
		objGestorPartido->CargarPartidosDesdeArchivo();
		listaPartidos = objGestorPartido->obtenerListaPartidos();
	}
	else {
		listaPartidos = objGestorPartido->buscarPartidos(nombreBuscar);
	}
	mostrarGrilla(listaPartidos);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int posicionFilaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
	int codigoPartidoEditar = Convert::ToInt32(this->dataGridView1->Rows[posicionFilaSeleccionada]->Cells[0]->Value->ToString());
	frmEditarPartidoPolitico^ ventanaEditarPartido = gcnew frmEditarPartidoPolitico(codigoPartidoEditar);
	ventanaEditarPartido->ShowDialog(); 
	PartidoPoliticoController^ gestorPartidoPolitico = gcnew PartidoPoliticoController();
	gestorPartidoPolitico->CargarPartidosDesdeArchivo();
	List<PartidoPolitico^>^ objListaPartidos = gestorPartidoPolitico->obtenerListaPartidos();
	mostrarGrilla(objListaPartidos);
}
};
}
