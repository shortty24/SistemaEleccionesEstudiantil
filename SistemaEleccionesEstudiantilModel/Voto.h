#pragma once
#include "ListaElectoral.h"
#include "MesaVotacion.h"

using namespace System;

public ref class Voto {
private:
	int codigo;
	String^ fechaVotacion;
	ListaElectoral^ objListaElectoral;
	MesaVotacion^ objMesaVotacion;

public:
	Voto();
	Voto(int codigo, String^ fechaVotacion, ListaElectoral^ objListaElectoral, MesaVotacion^ objMesaVotacion);
};