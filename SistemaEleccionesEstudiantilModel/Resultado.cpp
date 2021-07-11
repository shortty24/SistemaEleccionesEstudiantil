#include "Resultado.h"

using namespace SistemaEleccionesEstudiantilModel;

Resultado::Resultado(int codigo, ListaElectoral^ objListaElectoral, int nroVotos) {
	this->codigo = codigo;
	this->objListaElectoral = objListaElectoral;
	this->nroVotos = nroVotos;
}

Resultado::Resultado(ListaElectoral^ objListaElectoral, int nroVotos) {
	this->objListaElectoral = objListaElectoral;
	this->nroVotos = nroVotos;
}