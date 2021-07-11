#pragma once

using namespace System::Collections::Generic;
using namespace SistemaEleccionesEstudiantilModel;
using namespace System;
using namespace System::Data::SqlClient;

namespace SistemaEleccionesEstudiantilController {

	public ref class ResultadoController {
	private:
		SqlConnection^ objConexion;

	public:
		ResultadoController();
		void AbrirConexion();
		void CerrarConexion();
		void RegistrarResultado(Resultado^ objResultado);

	};
}