#include "MesaVotacion.h"

MesaVotacion::MesaVotacion() {
}

MesaVotacion::MesaVotacion(int codigo, int nroMesa, int nroAula, List<Alumno^>^ objListaElectores, List<Profesor^>^ objListaMiembrosMesa) {
	this->codigo = codigo;
	this->nroMesa = nroMesa;
	this->nroAula = nroAula;
	this->objListaElectores = objListaElectores;
	this->objListaMiembrosMesa = objListaMiembrosMesa;
}