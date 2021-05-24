#include "PartidoPolitico.h"

using namespace SistemaEleccionesEstudiantilModel;

PartidoPolitico::PartidoPolitico(int codigo, String^ nombre, String^ simbolo, String^ fechaFundacion) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->simbolo = simbolo;
	this->fechaFundacion = fechaFundacion;
	this->listaAlumnos = gcnew List<Alumno^>();
}

PartidoPolitico::PartidoPolitico(int codigo, String^ nombre, String^ simbolo, String^ fechaFundacion, List<Alumno^>^ listaMiembros) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->simbolo = simbolo;
	this->fechaFundacion = fechaFundacion;
	this->listaAlumnos = listaMiembros;
}