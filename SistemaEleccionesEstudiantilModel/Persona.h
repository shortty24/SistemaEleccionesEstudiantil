#pragma once

namespace SistemaEleccionesEstudiantilModel{

	using namespace System;

	public ref class Persona {
		public:
			String^ nombre;
			String^ apellidoPaterno;
			String^ apellidoMaterno;
			String^ genero;

		public:
			//Persona();
			Persona(String^ nombre, String^ apellidoPaterno, String^ apellidoMaterno, String^ genero);

	};
}