#pragma once
#include "Persona.h"

namespace SistemaEleccionesEstudiantilModel {

	public ref class Profesor :public Persona {
		public:
			String^ codigo;
			String^ perfil;

		public:
			//Profesor();

			Profesor(String^ codigo, String^ perfi);
	};
}