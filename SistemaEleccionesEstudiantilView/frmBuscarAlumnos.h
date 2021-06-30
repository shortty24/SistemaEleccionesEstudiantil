#pragma once

namespace SistemaEleccionesEstudiantilView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaEleccionesEstudiantilModel;
	using namespace SistemaEleccionesEstudiantilController;

	/// <summary>
	/// Summary for frmBuscarAlumnos
	/// </summary>
	public ref class frmBuscarAlumnos : public System::Windows::Forms::Form
	{
	public:
		frmBuscarAlumnos(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		frmBuscarAlumnos(List<Alumno^>^ listaMiembros )
		{
			InitializeComponent();
			this->listaMiembros = listaMiembros;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmBuscarAlumnos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox3);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(31, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(778, 102);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(529, 37);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(141, 21);
			this->comboBox3->TabIndex = 9;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(285, 37);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(141, 21);
			this->comboBox2->TabIndex = 8;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &frmBuscarAlumnos::comboBox2_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Primaria", L"Secundaria" });
			this->comboBox1->Location = System::Drawing::Point(75, 35);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(141, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmBuscarAlumnos::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(697, 34);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmBuscarAlumnos::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(471, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Sección :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(234, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Grado : ";
			this->label2->Click += gcnew System::EventHandler(this, &frmBuscarAlumnos::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nivel :";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(148, 133);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(545, 234);
			this->dataGridView1->TabIndex = 1;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Codigo";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre Completo";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Nivel";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Grado";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Sección";
			this->Column5->Name = L"Column5";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(268, 385);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Seleccionar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmBuscarAlumnos::button2_Click);
			// 
			// frmBuscarAlumnos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(856, 495);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmBuscarAlumnos";
			this->Text = L"frmBuscarAlumnos";
			this->Load += gcnew System::EventHandler(this, &frmBuscarAlumnos::frmBuscarAlumnos_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->comboBox1->Text == "Primaria") {
			this->comboBox2->Items->Clear();
			for (int i = 1; i <= 6; i++) {
				this->comboBox2->Items->Add(i);
			}
		}
		else {
			this->comboBox2->Items->Clear();
			for (int i = 1; i <= 5; i++) {
				this->comboBox2->Items->Add(i);
			}
		}
	}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	this->comboBox3->Items->Clear();
	this->comboBox3->Items->Add("A");
	this->comboBox3->Items->Add("B");
	this->comboBox3->Items->Add("C");
	this->comboBox3->Items->Add("D");
	this->comboBox3->Items->Add("E");
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
 	/*Los comboBox manejan solo texto(String)*/
	String^ nivel = this->comboBox1->Text;
	int grado = Convert::ToInt32(this->comboBox2->Text);
	String^ seccion = this->comboBox3->Text;
	AlumnoController^ objGestorAlumno = gcnew AlumnoController();
	List<Alumno^>^ listaAlumnos = objGestorAlumno->buscarAlumnosxNivelxGradoxSeccion(nivel, grado, seccion);
	mostrarGrilla(listaAlumnos);
}

private: void mostrarGrilla(List<Alumno^>^ listaAlumnos) {
	this->dataGridView1->Rows->Clear();
	for (int i = 0; i < listaAlumnos->Count; i++) {
		Alumno^ objAlumno = listaAlumnos[i]; 
		array<String^>^ fila = gcnew array<String^>(5);
		fila[0] = Convert::ToString(objAlumno->codigo);
		fila[1] = objAlumno->nombre + " " + objAlumno->apellidoPaterno + " " + objAlumno->apellidoMaterno;
		fila[2] = objAlumno->nivel;
		fila[3] = Convert::ToString(objAlumno->grado);
		fila[4] = objAlumno->seccion;
		this->dataGridView1->Rows->Add(fila);
	}
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int posicionFilaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
	String^ codigoAlumnoSeleccionado = this->dataGridView1->Rows[posicionFilaSeleccionada]->Cells[0]->Value->ToString();
	AlumnoController^ objGestorAlumno = gcnew AlumnoController();
	int pertenecePartido = objGestorAlumno->verificarSiAlumnoPertenecePartidoPolitico(codigoAlumnoSeleccionado);
	if (!pertenecePartido) {
		/*Aquí voy a ver si no está repetido*/
		int esta_repetido = 0;
		for (int i = 0; i < this->listaMiembros->Count; i++) {
			Alumno^ objAlumno = this->listaMiembros[i];
			if (objAlumno->codigo == codigoAlumnoSeleccionado) {
				esta_repetido = 1;
				break;
			}
		}
		if (!esta_repetido) {
			Alumno^ objAlumno = objGestorAlumno->buscarAlumno(codigoAlumnoSeleccionado);
			this->listaMiembros->Add(objAlumno);
			this->Close();
		}
		else {
			MessageBox::Show("El alumno ya se encuentra dentro de la lista de miembros del partido");
		}
	}
	else {
		MessageBox::Show("El alumno ya pertenece a la lista de miembros de otro partido");
	}
}	
private: System::Void frmBuscarAlumnos_Load(System::Object^ sender, System::EventArgs^ e) {
	
}
};
}
