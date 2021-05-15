#pragma once
#include "Alumno.h"
#include "Profesor.h"

namespace SistemaEleccionesEstudiantilModel {

	using namespace System::Collections::Generic;

	public ref class MesaVotacion {
		public:
			int codigo;
			int nroMesa;
			int nroAula;
			List<Alumno^>^ objListaElectores;
			List<Profesor^>^ objListaMiembrosMesa;
		public:
			//MesaVotacion();
			MesaVotacion(int codigo, int nroMesa, int nroAula, List<Alumno^>^ objListaElectores, List<Profesor^>^ objListaMiembrosMesa);
	};
}