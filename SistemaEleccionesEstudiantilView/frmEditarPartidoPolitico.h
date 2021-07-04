#pragma once
#include "frmBuscarAlumnos.h"

namespace SistemaEleccionesEstudiantilView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaEleccionesEstudiantilController;
	using namespace SistemaEleccionesEstudiantilModel;

	/// <summary>
	/// Summary for frmEditarPartidoPolitico
	/// </summary>
	public ref class frmEditarPartidoPolitico : public System::Windows::Forms::Form
	{
	public:
		frmEditarPartidoPolitico(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		frmEditarPartidoPolitico(int codigoPartidoEditar)
		{
			InitializeComponent();
			this->codigoPartidoEditar = codigoPartidoEditar;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmEditarPartidoPolitico()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button3;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: int codigoPartidoEditar;
	private: List<Alumno^>^ listaMiembros;

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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(616, 360);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(77, 36);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Eliminar Alumnos";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmEditarPartidoPolitico::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(308, 480);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Grabar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmEditarPartidoPolitico::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(616, 318);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 36);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Agregar Alumnos";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmEditarPartidoPolitico::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Location = System::Drawing::Point(28, 259);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(556, 215);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Miembros Partido";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(6, 28);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(544, 181);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Código";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre Completo";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Grado";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Sección";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Nivel";
			this->Column5->Name = L"Column5";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(28, 36);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(556, 196);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del Partido Político";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmEditarPartidoPolitico::groupBox1_Enter);
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(205, 137);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(242, 20);
			this->textBox4->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(205, 106);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(242, 20);
			this->textBox3->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(205, 73);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(242, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(141, 142);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Fecha :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(135, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Símbolo :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(139, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nombre :";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(205, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(242, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(142, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código :";
			// 
			// frmEditarPartidoPolitico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(718, 521);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmEditarPartidoPolitico";
			this->Text = L"frmEditarPartidoPolitico";
			this->Load += gcnew System::EventHandler(this, &frmEditarPartidoPolitico::frmEditarPartidoPolitico_Load);
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEditarPartidoPolitico_Load(System::Object^ sender, System::EventArgs^ e) {
		PartidoPoliticoController^ objGestorPartido = gcnew PartidoPoliticoController();
		PartidoPolitico^ objPartido = objGestorPartido->buscarPartidoPoliticoxCodigo(this->codigoPartidoEditar);
		this->textBox1->Text = Convert::ToString(objPartido->codigo);
		this->textBox2->Text = objPartido->nombre;
		this->textBox3->Text = objPartido->simbolo;
		this->textBox4->Text = objPartido->fechaFundacion;
		this->listaMiembros = objPartido->listaAlumnos;
		mostrarGrilla(this->listaMiembros);
	}

	private: void mostrarGrilla(List<Alumno^>^ listaAlumnos) {
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < listaAlumnos->Count; i++) {
			Alumno^ objAlumno = listaAlumnos[i];
			array<String^>^ fila = gcnew array<String^>(5);
			fila[0] = Convert::ToString(objAlumno->dni);
			fila[1] = objAlumno->nombre + " " + objAlumno->apellidoPaterno + " " + objAlumno->apellidoMaterno;
			fila[2] = Convert::ToString(objAlumno->grado);
			fila[3] = objAlumno->seccion;
			fila[4] = objAlumno->nivel;
			this->dataGridView1->Rows->Add(fila);
		}
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	frmBuscarAlumnos^ ventanaBuscarAlumnos = gcnew frmBuscarAlumnos(this->listaMiembros);
	ventanaBuscarAlumnos->ShowDialog();

	/*Aquí ya la búsqueda de alumnos terminó y ya agregué a un alumno a mi lista*/
	/*Entonces toca mostrar a los alumnos de la lista en la grilla*/
	mostrarGrilla(this->listaMiembros);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int posicionFilaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
	String^ codigoAlumnoSeleccionado = this->dataGridView1->Rows[posicionFilaSeleccionada]->Cells[0]->Value->ToString();
	for (int i = 0; this->listaMiembros->Count; i++) {
		Alumno^ objAlumno = this->listaMiembros[i];
		if (objAlumno->dni == codigoAlumnoSeleccionado) {
			this->listaMiembros->RemoveAt(i);
			break;
		}
	}
	mostrarGrilla(this->listaMiembros);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	PartidoPoliticoController^ objGestorPartido = gcnew PartidoPoliticoController();
	objGestorPartido->EditarPartidoPolitico(this->codigoPartidoEditar, this->listaMiembros);
	MessageBox::Show("El partido político ha sido editar con éxito");
	this->Close();
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
};
}
