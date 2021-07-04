#pragma once

namespace SistemaEleccionesEstudiantilController{
	
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaEleccionesEstudiantilModel;
	using namespace System::Data::SqlClient;

	public ref class PartidoPoliticoController {
	private:
		List<PartidoPolitico^>^ listaPartidosPoliticos;
		SqlConnection^ objConexion;
	
	public:
		/*Propósito del constructor: Crear espacio de memorioa o inicializar los atributos*/
		PartidoPoliticoController();
		/*Métdos con base de datos*/
		void AbrirConexion();
		void CerrarConexion();
		List<PartidoPolitico^>^ buscarPartidosBD();

		/*Métods con archivos*/
		void CargarPartidosDesdeArchivo();
		List<Alumno^>^ BuscarAlumnosPartidoPolitico(int codigoPartido);
		int ObtenerCantidadPartidos();
		PartidoPolitico^ ObtenerPartidoLista(int indice);
		void GuardarPartidoPoliticoEnArchivo(PartidoPolitico^ objPartido);
		List<PartidoPolitico^>^ obtenerListaPartidos();
		List<PartidoPolitico^>^ buscarPartidos(String^ nombreBuscar);
		void eliminarPartidoPolitico(int codigoPartidoEliminar);
		PartidoPolitico^ buscarPartidoPoliticoxCodigo(int codigoPartido);
		void EditarPartidoPolitico(int codigoPartidoEditar, List<Alumno^>^ listaMiembros);
	};
} 