#pragma once
#include "Persona.h"

namespace SistemaEleccionesEstudiantilModel {

	public ref class Profesor :public Persona {
	private:
		int codigo;
		String^ objPerfil;

	public:
		//Profesor();

		Profesor(int codigo, String^ objPerfi);
		
	};
}