#pragma once

using namespace System::Collections::Generic;
using namespace SistemaEleccionesEstudiantilModel;
using namespace System;
using namespace System::Data::SqlClient;

namespace SistemaEleccionesEstudiantilController {

	public ref class ProfesorController {
	private:
		List<Profesor^>^ listaProfesores;
		SqlConnection^ objConexion;

	public:
		ProfesorController();
		void AbrirConexion();
		void CerrarConexion();
		int validarExisteProfesor(String^ dni);
		List<Profesor^>^ buscarProfesorxMesaVotacion(int codigoMesa);
	};
}