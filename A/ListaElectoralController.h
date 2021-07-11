#pragma once

namespace SistemaEleccionesEstudiantilController {

	using namespace SistemaEleccionesEstudiantilModel;
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::Data::SqlClient;

	public ref class ListaElectoralController {
	private:
		List<ListaElectoral^>^ listaElectoral;
		SqlConnection^ objConexion;

	public:
		ListaElectoralController();
		/*M�todos con base de datos*/
		void AbrirConexion();
		void CerrarConexion();
		List<ListaElectoral^>^ buscarListaElectorales();
		List<ListaElectoral^>^ buscarListaElectoralesxAnho(int anho);

		/*M�todos con archivos .txt*/
		void CargarPartidosDesdeArchivo();
		List<Alumno^>^ BuscarAlumnosListaElectoral(int codigoPartido);
		int ObtenerCantidadListasElectorales();
		List<ListaElectoral^>^ obtenerListasElectorales();
		PartidoPolitico^ buscarPartidoPoliticoxCodigo(int codigoPartido);
		List<ListaElectoral^>^ buscarListaElectoral(String^ anhoBuscar);
	};
}