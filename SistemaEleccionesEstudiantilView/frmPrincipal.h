#pragma once

#include "frmMantPartidosPoliticos.h"
#include "frmMantListaElectoral.h"
#include "frmNuevoVoto.h"
#include "frmRegistrarResultados.h"

namespace SistemaEleccionesEstudiantilView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		frmPrincipal(String^ dni, String^ tipo)
		{
			InitializeComponent();
			this->tipo = tipo;
			this->dni = dni;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ partidosPolíticosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ listaElectoralToolStripMenuItem;



	private: String^ tipo;
	private: String^ dni;
	private: System::Windows::Forms::ToolStripMenuItem^ votaciónToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ registrarVotosToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ registrarResultadosToolStripMenuItem1;




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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenimientosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->partidosPolíticosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaElectoralToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->votaciónToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registrarVotosToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registrarResultadosToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripMenuItem1,
					this->mantenimientosToolStripMenuItem, this->votaciónToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(749, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(22, 20);
			this->toolStripMenuItem1->Text = L" ";
			// 
			// mantenimientosToolStripMenuItem
			// 
			this->mantenimientosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->partidosPolíticosToolStripMenuItem,
					this->listaElectoralToolStripMenuItem
			});
			this->mantenimientosToolStripMenuItem->Name = L"mantenimientosToolStripMenuItem";
			this->mantenimientosToolStripMenuItem->Size = System::Drawing::Size(106, 20);
			this->mantenimientosToolStripMenuItem->Text = L"Mantenimientos";
			// 
			// partidosPolíticosToolStripMenuItem
			// 
			this->partidosPolíticosToolStripMenuItem->Name = L"partidosPolíticosToolStripMenuItem";
			this->partidosPolíticosToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->partidosPolíticosToolStripMenuItem->Text = L"Partidos Políticos";
			this->partidosPolíticosToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::partidosPolíticosToolStripMenuItem_Click);
			// 
			// listaElectoralToolStripMenuItem
			// 
			this->listaElectoralToolStripMenuItem->Name = L"listaElectoralToolStripMenuItem";
			this->listaElectoralToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->listaElectoralToolStripMenuItem->Text = L"Listas Electorales";
			this->listaElectoralToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::listaElectoralToolStripMenuItem_Click);
			// 
			// votaciónToolStripMenuItem1
			// 
			this->votaciónToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->registrarVotosToolStripMenuItem1,
					this->registrarResultadosToolStripMenuItem1
			});
			this->votaciónToolStripMenuItem1->Name = L"votaciónToolStripMenuItem1";
			this->votaciónToolStripMenuItem1->Size = System::Drawing::Size(65, 20);
			this->votaciónToolStripMenuItem1->Text = L"Votación";
			// 
			// registrarVotosToolStripMenuItem1
			// 
			this->registrarVotosToolStripMenuItem1->Name = L"registrarVotosToolStripMenuItem1";
			this->registrarVotosToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->registrarVotosToolStripMenuItem1->Text = L"Registrar Votos";
			this->registrarVotosToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmPrincipal::registrarVotosToolStripMenuItem1_Click);
			// 
			// registrarResultadosToolStripMenuItem1
			// 
			this->registrarResultadosToolStripMenuItem1->Name = L"registrarResultadosToolStripMenuItem1";
			this->registrarResultadosToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->registrarResultadosToolStripMenuItem1->Text = L"Registrar Resultados";
			this->registrarResultadosToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmPrincipal::registrarResultadosToolStripMenuItem1_Click);
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(749, 594);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"frmPrincipal";
			this->Text = L" Sistema de Elecciones - Mi Colegio";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmPrincipal::frmPrincipal_FormClosing);
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void partidosPolíticosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		/*El constructor es el que le da vida, pues de no hacerlo sería como declarar 'int a;' */
		frmMantPartidosPoliticos^ ventanaMantPartidosPoliticos = gcnew frmMantPartidosPoliticos();

		ventanaMantPartidosPoliticos->MdiParent = this; //this: permite representar a la misma clase
		ventanaMantPartidosPoliticos->Show();
	}
	private: System::Void frmPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listaElectoralToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantListaElectoral^ ventanaMantListaElectoral = gcnew frmMantListaElectoral();

		ventanaMantListaElectoral->MdiParent = this;
		ventanaMantListaElectoral->Show();
	}
private: System::Void frmPrincipal_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	Application::Exit();
}
private: System::Void registrarVotosToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tipo == "Alumno") {
		frmNuevoVoto^ ventanaNuevoVoto = gcnew frmNuevoVoto(this->dni);
		ventanaNuevoVoto->MdiParent = this;
		ventanaNuevoVoto->Show();
	}
	else {
		MessageBox::Show("Esta opción solo está habilitada para Alumnos");
	}
}
private: System::Void registrarResultadosToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tipo == "Profesor") {
		frmRegistrarResultados^ ventanaRegistrarResultados = gcnew frmRegistrarResultados();
		ventanaRegistrarResultados->MdiParent = this;
		ventanaRegistrarResultados->Show();
	}
	else {
		MessageBox::Show("Esta opción solo está habilitada para Profesores");
	}
}
};
}
