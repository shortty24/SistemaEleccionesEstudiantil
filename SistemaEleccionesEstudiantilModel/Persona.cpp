#include "Persona.h"

using namespace SistemaEleccionesEstudiantilModel;

/*Persona::Persona() {
	nombre = "Name";
	apellidoPaterno = "Father's last name";
	apellidoMaterno = "Mother's last name";
	genero = "Gender";
}*/

Persona::Persona(String^ nombre, String^ apellidoPaterno, String^ apellidoMaterno, String^ genero) {
	this->nombre = nombre;
	this->apellidoPaterno = apellidoPaterno;
	this->apellidoMaterno = apellidoMaterno;
	this->genero = genero;	
}

Persona::Persona(String^ dni,String^ nombre, String^ apellidoPaterno, String^ apellidoMaterno, String^ genero) {
	this->dni = dni;
	this->nombre = nombre;
	this->apellidoPaterno = apellidoPaterno;
	this->apellidoMaterno = apellidoMaterno;
	this->genero = genero;
}
