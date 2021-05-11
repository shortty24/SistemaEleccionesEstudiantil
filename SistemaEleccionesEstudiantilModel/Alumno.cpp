#include "Alumno.h"

using namespace SistemaEleccionesEstudiantilModel;

Alumno::Alumno(int codigo, int grado, char seccion, String^ objNivel) {
	this->codigo = codigo;
	this->grado = grado;
	this->seccion = seccion;
	this->objNivel = objNivel;
}