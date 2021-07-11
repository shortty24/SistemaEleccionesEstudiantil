#pragma once

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
	/// Summary for frmRegistrarResultados
	/// </summary>
	public ref class frmRegistrarResultados : public System::Windows::Forms::Form
	{
	public:
		frmRegistrarResultados(void)
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
		~frmRegistrarResultados()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: Eleccion^ objEleccionActiva;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Button^ button2;

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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(94, 42);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(498, 144);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos Elección";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(333, 59);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Calcular";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmRegistrarResultados::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(143, 75);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(158, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(158, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(38, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Fecha Votación :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(94, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Año :";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(94, 216);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(498, 194);
			this->dataGridView1->TabIndex = 1;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Partido Político";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Candidato";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Nro Votos";
			this->Column3->Name = L"Column3";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(303, 447);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Grabar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmRegistrarResultados::button2_Click);
			// 
			// frmRegistrarResultados
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(722, 494);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmRegistrarResultados";
			this->Text = L"frmRegistrarResultados";
			this->Load += gcnew System::EventHandler(this, &frmRegistrarResultados::frmRegistrarResultados_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmRegistrarResultados_Load(System::Object^ sender, System::EventArgs^ e) {
		EleccionController^ objGestorEleccion = gcnew EleccionController();
		this->objEleccionActiva = objGestorEleccion->buscarEleccionActiva();
		this->textBox1->Text = Convert::ToString(this->objEleccionActiva->anho);
		this->textBox2->Text = this->objEleccionActiva->fechaVotacion; 
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		VotoController^ objVotoController = gcnew VotoController();
		for (int i = 0; i < this->objEleccionActiva->objListaElectoral->Count; i++) {
			ListaElectoral^ objListaElectoral = this->objEleccionActiva->objListaElectoral[i];
			int nroVotos = objVotoController->ContarVotos(this->objEleccionActiva->fechaVotacion, objListaElectoral->codigo);
			Resultado^ objResultado = gcnew Resultado(objListaElectoral, nroVotos);
			this->objEleccionActiva->listaResultados->Add(objResultado);
		}
		MostrarGrilla();
	}

	private: void MostrarGrilla() {
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < this->objEleccionActiva->listaResultados->Count; i++) {
			Resultado^ objResultado = this->objEleccionActiva->listaResultados[i];
			array<String^>^ fila = gcnew array<String^>(3);
			fila[0] = objResultado->objListaElectoral->objPartidoPolitico->nombre;

			for (int i = 0; i < objResultado->objListaElectoral->objListaAlumnos->Count; i++) {
				Alumno^ objAlumno = objResultado->objListaElectoral->objListaAlumnos[i];
				if (objAlumno->grado == 5 && objAlumno->nivel == "Secundaria") {
					String^ candidatoLista = objAlumno->nombre + " " + objAlumno->apellidoPaterno;
					fila[1] = candidatoLista;
					break;
				}
			}

			fila[2] = Convert::ToString(objResultado->nroVotos);
			this->dataGridView1->Rows->Add(fila);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		ResultadoController^ objGestorResultado = gcnew ResultadoController();
		for (int i = 0; i < this->objEleccionActiva->listaResultados->Count; i++) {
			Resultado^ objResultado = this->objEleccionActiva->listaResultados[i];
			objGestorResultado->RegistrarResultado(objResultado);
		}
		MessageBox::Show("Los resultados fueron registrados exitosamente");
		this->Close();
	}

};
}
