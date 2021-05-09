#include "Persona.h"

Persona::Persona(String^ objNombre, String^ objApellidoPaterno, String^ objApellidoMaterno, String^ objGenero) {
	this->objNombre = objNombre;
	this->objApellidoPaterno = objApellidoPaterno;
	this->objApellidoMaterno = objApellidoMaterno;
	this->objGenero = objGenero;
}