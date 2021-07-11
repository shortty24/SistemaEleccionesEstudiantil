#pragma once

namespace SistemaEleccionesEstudiantilController {
	using namespace SistemaEleccionesEstudiantilModel;
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::Data::SqlClient;

	public ref class EleccionController {

	public:
		List<Eleccion^>^ listaElecciones;
		SqlConnection^ objConexion;

	public:
		EleccionController();
		void AbrirConexion();
		void CerrarConexion();
		Eleccion^ buscarEleccionActiva();
	};
}