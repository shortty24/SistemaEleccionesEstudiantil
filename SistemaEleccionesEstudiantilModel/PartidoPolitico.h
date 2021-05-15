#pragma once
#include "Alumno.h"

namespace SistemaEleccionesEstudiantilModel {

	using namespace System::Collections::Generic;
	using namespace System;

	public ref class PartidoPolitico {
		/*Atributos*/
		public:
			int codigo;
			String^ nombre;
			String^ simbolo;
			String^ fechaFundacion;
			List<Alumno^>^ listaAlumnos;

			/*Métodos o Funciones*/
		public:
			//PartidoPolitico(); //Todas las clases deben tener un método constructor que se llame igual que la clase
			PartidoPolitico(int codigo, String^ nombre, String^ simbolo, String^ fechaFundacion);
	};
}