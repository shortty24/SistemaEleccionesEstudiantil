#pragma once

namespace SistemaEleccionesEstudiantilModel{

	using namespace System;

	public ref class Persona {
		public:
			String^ dni;
			String^ nombre;
			String^ apellidoPaterno;
			String^ apellidoMaterno;
			String^ genero;

		public:
			//Persona();
			Persona(String^ nombre, String^ apellidoPaterno, String^ apellidoMaterno, String^ genero);
			Persona(String^ dni, String^ nombre, String^ apellidoPaterno, String^ apellidoMaterno, String^ genero);
	};
}