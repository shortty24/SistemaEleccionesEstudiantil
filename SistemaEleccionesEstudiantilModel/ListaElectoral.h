#pragma once
#include "PartidoPolitico.h"

namespace SistemaEleccionesEstudiantilModel {
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class ListaElectoral {
		public:
			int codigo;
			String^ anhoEleccion;
			PartidoPolitico^ objPartidoPolitico;
			List<Alumno^>^ objListaAlumnos;

		public:
			ListaElectoral();
			ListaElectoral(int codigo, String^ anhoEleccion, PartidoPolitico^ objPartidoPolitico);
			ListaElectoral(int codigo, String^ anhoEleccion, PartidoPolitico^ objPartidoPolitico, List<Alumno^>^ objListaAlumnos);
	};
}