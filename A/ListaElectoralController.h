#pragma once

namespace SistemaEleccionesEstudiantilController {

	using namespace SistemaEleccionesEstudiantilModel;
	using namespace System::Collections::Generic;
	using namespace System;

	public ref class ListaElectoralController {
	private:
		List<ListaElectoral^>^ listaElectoral;
	public:
		ListaElectoralController();
		void CargarPartidosDesdeArchivo();
		List<Alumno^>^ BuscarAlumnosListaElectoral(int codigoPartido);
		int ObtenerCantidadListasElectorales();
		List<ListaElectoral^>^ obtenerListasElectorales();
		PartidoPolitico^ buscarPartidoPoliticoxCodigo(int codigoPartido);
		List<ListaElectoral^>^ buscarListaElectoral(String^ anhoBuscar);
	};
}