#pragma once

namespace SistemaEleccionesEstudiantilController {
	using namespace System::Collections::Generic;
	using namespace SistemaEleccionesEstudiantilModel;

	public ref class PartidoPoliticoController {
	private:
		List<PartidoPolitico^>^ listaPartidosPoliticos;
	
	public:
		/*Propósito del constructor: Crear espacio de memorioa o inicializar los atributos*/
		PartidoPoliticoController();
		void CargarPartidosDesdeArchivo();
		List<Alumno^>^ BuscarAlumnosPartidoPolitico(int codigoPartido);
		int ObtenerCantidadPartidos();
		PartidoPolitico^ ObtenerPartidoLista(int indice); 
	};
} 