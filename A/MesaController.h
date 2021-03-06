#pragma once

namespace SistemaEleccionesEstudiantilController {
	using namespace SistemaEleccionesEstudiantilModel;
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::Data::SqlClient;

	public ref class MesaController {

	public:
		List<MesaVotacion^>^ listaMesaVotacion;
		SqlConnection^ objConexion;
	public:
		MesaController();
		void AbrirConexion();
		void CerrarConexion();
		MesaVotacion^ buscarMesaVotacionxAlumno(String^ dni);
		List<MesaVotacion^>^ buscarMesasVotacionxAnho(int anho);
	};
}