#include "Profesor.h"

using namespace SistemaEleccionesEstudiantilModel;

Profesor::Profesor(String^ dni, String^ nombre, String^ apellidoPaterno, String^ apellidoMaterno, String^ genero, String^ perfil):Persona(dni, nombre, apellidoPaterno, apellidoMaterno, genero){
	this->perfil = perfil;
}
