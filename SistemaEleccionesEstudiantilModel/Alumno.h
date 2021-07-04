#pragma once
#include "Persona.h"

namespace SistemaEleccionesEstudiantilModel {

	using namespace System;

	public ref class Alumno : public Persona {
	public:
		int grado;
		String^ seccion;
		String^ nivel;
	 
	public:
		//Alumno();
		Alumno(String^ nombre, String^ apellidoPaterno, String^ objApellidoMaterno, String^ genero, int grado, String^ seccion, String^ nivel);
		Alumno(String^ dni,String^ nombre, String^ apellidoPaterno, String^ objApellidoMaterno, String^ genero, int grado, String^ seccion, String^ nivel);
	};
}