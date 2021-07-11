#include "Eleccion.h"

using namespace SistemaEleccionesEstudiantilModel;

Eleccion::Eleccion(int anho, String^ fechaVotacion, String^ estado) {
	this->anho = anho;
	this->fechaVotacion = fechaVotacion;
	this->estado = estado;
	this->listaResultados = gcnew List<Resultado^>();
}
