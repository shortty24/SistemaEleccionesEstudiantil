#include "Alumno.h"

using namespace SistemaEleccionesEstudiantilModel;

Alumno::Alumno(String^ nombre, String^ apellidoPaterno, String^ objApellidoMaterno, String^ genero, int grado, String^ seccion, String^ nivel) :Persona(dni, nombre, apellidoPaterno, apellidoMaterno, genero){
	
	this->grado = grado;
	this->seccion = seccion;
	this->nivel = nivel;
}

Alumno::Alumno(String^ dni,String^ nombre, String^ apellidoPaterno, String^ objApellidoMaterno, String^ genero, int grado, String^ seccion, String^ nivel) :Persona(dni, nombre, apellidoPaterno, apellidoMaterno, genero) {
	this->grado = grado;
	this->seccion = seccion;
	this->nivel = nivel;
}