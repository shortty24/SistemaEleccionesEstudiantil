#include "Profesor.h"

using namespace SistemaEleccionesEstudiantilModel;

Profesor::Profesor(String^ codigo, String^ objPerfi) :Persona(nombre, apellidoPaterno, apellidoMaterno, genero) {
	this->codigo = codigo;
	this->perfil = perfil;
}
