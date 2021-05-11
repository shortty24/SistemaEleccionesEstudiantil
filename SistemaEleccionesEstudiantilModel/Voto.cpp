#include "Voto.h"

using namespace SistemaEleccionesEstudiantilModel;

/*De la clase "Voto" quiero definir el método "Voto"*/
/*Voto::Voto() {
	codigo = 10;
}*/

Voto::Voto(int codigo, String^ fechaVotacion, ListaElectoral^ objListaElectoral, MesaVotacion^ objMesaVotacion) {
	this->codigo = codigo;
	this->fechaVotacion = fechaVotacion;
	this->objListaElectoral = objListaElectoral;
	this->objMesaVotacion = objMesaVotacion;

}