#pragma once

using namespace System::Collections::Generic;
using namespace SistemaEleccionesEstudiantilModel;
using namespace System;
using namespace System::Data::SqlClient;

namespace SistemaEleccionesEstudiantilController {

	public ref class VotoController {
	private:
		SqlConnection^ objConexion;

	public:
		VotoController();
		void AbrirConexion();
		void CerrarConexion();
		void RegistrarVoto(Voto^ objVoto);
		int ContarVotos(String^ fechaVotacion, int codigListaElectoral);

	};
}