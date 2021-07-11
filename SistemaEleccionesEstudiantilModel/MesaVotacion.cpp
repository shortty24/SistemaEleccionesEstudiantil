#include "MesaVotacion.h"

using namespace SistemaEleccionesEstudiantilModel;
/*MesaVotacion::MesaVotacion() {
}*/

MesaVotacion::MesaVotacion(int codigo, int nroMesa, int nroAula) {
	this->codigo = codigo;
	this->nroMesa = nroMesa;
	this->nroAula = nroAula;
	this->objListaElectores = gcnew List<Alumno^>();
	this->objListaMiembrosMesa = gcnew List<Profesor^>();
}
MesaVotacion::MesaVotacion(int codigo, int nroMesa, int nroAula, int anhoEleccion) {
	this->codigo = codigo;
	this->nroMesa = nroMesa;
	this->nroAula = nroAula;
	this->anhoEleccion = anhoEleccion;
	this->objListaElectores = gcnew List<Alumno^>();
	this->objListaMiembrosMesa = gcnew List<Profesor^>();
}