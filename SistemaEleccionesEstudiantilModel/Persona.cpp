#include "Persona.h"

using namespace SistemaEleccionesEstudiantilModel;

Persona::Persona() {
	objNombre = "Name";
	objApellidoPaterno = "Father's last name";
	objApellidoMaterno = "Mother's last name";
	objGenero = "Gender";
}

Persona::Persona(String^ objNombre, String^ objApellidoPaterno, String^ objApellidoMaterno, String^ objGenero) {
	this->objNombre = objNombre;
	this->objApellidoPaterno = objApellidoPaterno;
	this->objApellidoMaterno = objApellidoMaterno;
	this->objGenero = objGenero;
}
