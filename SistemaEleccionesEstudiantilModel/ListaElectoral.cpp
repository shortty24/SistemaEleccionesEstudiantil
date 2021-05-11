#include "ListaElectoral.h"

using namespace SistemaEleccionesEstudiantilModel;

ListaElectoral::ListaElectoral(int codigo, int anhoEleccion, PartidoPolitico^ objPartidoPolitico, List<Alumno^>^ objListaAlumnos) {
	this->codigo = codigo;
	this->anhoEleccion = anhoEleccion;
	this->objPartidoPolitico = objPartidoPolitico;
	this->objListaAlumnos = objListaAlumnos;
}