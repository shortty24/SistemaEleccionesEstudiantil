#pragma once
#include "PartidoPolitico.h"

using namespace System::Collections::Generic;
public ref class ListaElectoral {
	private:
		int codigo;
		int anhoEleccion;
		PartidoPolitico^ objPartidoPolitico;
		List<Alumno^>^ objListaAlumnos;

public:
	ListaElectoral();
	ListaElectoral(int codigo, int anhoEleccion, PartidoPolitico^ objPartidoPolitico, List<Alumno^>^ objListaAlumnos);

};