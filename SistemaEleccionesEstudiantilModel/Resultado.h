#pragma once
#include "ListaElectoral.h"

namespace SistemaEleccionesEstudiantilModel {

	using namespace System;

	public ref class Resultado {
	public:
		int codigo;
		ListaElectoral^ objListaElectoral;
		int nroVotos;

	public:
		Resultado(int codigo, ListaElectoral^ objListaElectoral, int nroVotos);
		Resultado(ListaElectoral^ objListaElectoral, int nroVotos);
	};
}