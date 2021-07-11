#pragma once
#include "ListaElectoral.h"
#include "MesaVotacion.h"
#include "Resultado.h"

namespace SistemaEleccionesEstudiantilModel {

	using namespace System;

	public ref class Eleccion {
	public:
		int anho;
		String^ fechaVotacion;
		String^ estado;
		List<ListaElectoral^>^ objListaElectoral;
		List<MesaVotacion^>^ listaMesas;
		List<Resultado^>^ listaResultados;

	public:
		Eleccion(int anho, String^ fechaVotaacion, String^ estado);
	};
}