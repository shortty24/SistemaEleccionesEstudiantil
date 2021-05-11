#include "PartidoPolitico.h"

using namespace SistemaEleccionesEstudiantilModel;

PartidoPolitico::PartidoPolitico(int codigo, String^ objNombre, char simbolo, String^ objFechaFundacion, List<Alumno^>^ objListaAlumnos) {
	this->codigo = codigo;
	this->objNombre = objNombre;
	this->simbolo = simbolo;
	this->objFechaFundacion = objFechaFundacion;
	this->objListaAlumnos = objListaAlumnos;

}