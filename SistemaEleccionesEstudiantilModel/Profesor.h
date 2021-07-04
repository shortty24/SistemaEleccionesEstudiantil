#pragma once
#include "Persona.h"

namespace SistemaEleccionesEstudiantilModel {

	using namespace System;

	public ref class Profesor :public Persona {
		public:

			String^ perfil;

		public:
			//Profesor();

			Profesor(String^ dni, String^ nombre, String^ apellidoPaterno, String^ apellidoMaterno, String^ genero, String^ perfil);
	};
}