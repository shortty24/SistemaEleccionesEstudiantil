#include "ListaElectoral.h"

using namespace SistemaEleccionesEstudiantilModel;

ListaElectoral::ListaElectoral(int codigo, String^ anhoEleccion, PartidoPolitico^ objPartidoPolitico) {
	this->codigo = codigo;
	this->anhoEleccion = anhoEleccion;
	this->objPartidoPolitico=objPartidoPolitico;
	this->objListaAlumnos=gcnew List<Alumno^>();
}

ListaElectoral::ListaElectoral(int codigo, String^ anhoEleccion, PartidoPolitico^ objPartidoPolitico, List<Alumno^>^ objListaAlumnos) {
	this->codigo = codigo;
	this->anhoEleccion = anhoEleccion;
	this->objPartidoPolitico = objPartidoPolitico;
	this->objListaAlumnos = objListaAlumnos;
}