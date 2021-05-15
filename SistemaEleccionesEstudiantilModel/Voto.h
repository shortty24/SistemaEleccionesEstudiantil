#pragma once
#include "ListaElectoral.h"
#include "MesaVotacion.h"

namespace SistemaEleccionesEstudiantilModel {

	using namespace System;

	public ref class Voto {
		public:
			int codigo;
			String^ fechaVotacion;
			ListaElectoral^ objListaElectoral;
			MesaVotacion^ objMesaVotacion;

		public:
			//Voto();
			Voto(int codigo, String^ fechaVotacion, ListaElectoral^ objListaElectoral, MesaVotacion^ objMesaVotacion);
	};
}