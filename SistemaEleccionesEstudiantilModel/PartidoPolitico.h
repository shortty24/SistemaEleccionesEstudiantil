#pragma once
#include "Alumno.h"

namespace SistemaEleccionesEstudiantilModel {

	using namespace System::Collections::Generic;
	using namespace System;

	public ref class PartidoPolitico {
		/*Atributos*/
	private:
		int codigo;
		String^ objNombre;
		char simbolo;
		String^ objFechaFundacion;
		List<Alumno^>^ objListaAlumnos;

		/*Métodos o Funciones*/
	public:
		//PartidoPolitico(); //Todas las clases deben tener un método constructor que se llame igual que la clase
		PartidoPolitico(int codigo, String^ objNombre, char simbolo, String^ objFechaFundacion, List<Alumno^>^ objListaAlumnos);
	};
}