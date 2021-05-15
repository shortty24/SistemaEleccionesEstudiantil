#include "Alumno.h"

using namespace SistemaEleccionesEstudiantilModel;

Alumno::Alumno(String^ codigo, String^ nombre, String^ apellidoPaterno, String^ objApellidoMaterno, String^ genero, int grado, String^ seccion, String^ nivel) :Persona(nombre, apellidoPaterno, apellidoMaterno, genero){
	this->codigo = codigo;
	this->grado = grado;
	this->seccion = seccion;
	this->nivel = nivel;
}