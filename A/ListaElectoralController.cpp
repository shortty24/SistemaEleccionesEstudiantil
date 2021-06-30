#include "ListaElectoralController.h"
#include "AlumnoController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System;
using namespace System::IO;

ListaElectoralController::ListaElectoralController() {
	this->listaElectoral = gcnew List<ListaElectoral^>();
}

void ListaElectoralController::CargarPartidosDesdeArchivo() {
	this->listaElectoral->Clear();
	array<String^>^ lineas = File::ReadAllLines("listasElectorales.txt");

	String^ separadores = ";";
	for each (String ^ lineaListasElectorales in lineas) {
		array<String^>^ palabras = lineaListasElectorales->Split(separadores->ToCharArray());
		int codigoLista = Convert::ToInt32(palabras[0]);
		String^ anho = palabras[1];
		int codigoPartido = Convert::ToInt32(palabras[2]);
		PartidoPolitico^ objCodigoPartido = buscarPartidoPoliticoxCodigo(codigoPartido);
		ListaElectoral^ objListaElectoral = gcnew ListaElectoral(codigoLista, anho, objCodigoPartido);	
		List<Alumno^>^ listaElectoral = BuscarAlumnosListaElectoral(codigoPartido);
		objListaElectoral->objListaAlumnos = listaElectoral;
		this->listaElectoral->Add(objListaElectoral);
	}
}

List<Alumno^>^ ListaElectoralController::BuscarAlumnosListaElectoral(int codigoPartido) {
	List<Alumno^>^ listaAlumnosEncontrados = gcnew List<Alumno^>();
	array<String^>^ lineas = File::ReadAllLines("miembrosListas.txt");

	String^ separadores = ";";
	for each (String ^ lineaMiembroListaElectoral in lineas) {
		array <String^>^ palabras = lineaMiembroListaElectoral->Split(separadores->ToCharArray());
		int codigoListaPartido = Convert::ToInt32(palabras[0]);
		int codigoAlumno = Convert::ToInt32(palabras[1]);
		if (codigoListaPartido == codigoPartido) {
			AlumnoController^ gestorAlumnoController = gcnew AlumnoController();
			Alumno^ objAlumno = gestorAlumnoController->buscarAlumno(Convert::ToString(codigoAlumno));
			listaAlumnosEncontrados->Add(objAlumno);
		}
	}
	return listaAlumnosEncontrados;
}

int ListaElectoralController::ObtenerCantidadListasElectorales() {
	return this->listaElectoral->Count;
}

List<ListaElectoral^>^ ListaElectoralController::obtenerListasElectorales() {
	return this->listaElectoral;
}

PartidoPolitico^ ListaElectoralController::buscarPartidoPoliticoxCodigo(int codigoPartido) {
	PartidoPolitico^ objPartidoPoliticoEncontrado;
	array<String^>^ lineas = File::ReadAllLines("partidosPoliticos.txt");

	String^ separadores = ";";
	for each (String ^ lineaPartidoPolitico in lineas) {
		array<String^>^ palabras = lineaPartidoPolitico->Split(separadores->ToCharArray());
		int codigoPartidoPolitico = Convert::ToInt32(palabras[0]);
		String^ nombrePartido = palabras[1];
		String^ simbolo = palabras[2];
		String^ fechaFundacion = palabras[3];
		if (codigoPartidoPolitico == codigoPartido) {
			objPartidoPoliticoEncontrado = gcnew PartidoPolitico(codigoPartidoPolitico, nombrePartido, simbolo, fechaFundacion);
			List<Alumno^>^ listaAlumnosPartido = BuscarAlumnosListaElectoral(codigoPartido);
			objPartidoPoliticoEncontrado->listaAlumnos = listaAlumnosPartido;
			break;
		}
	}
	return objPartidoPoliticoEncontrado;
}

List<ListaElectoral^>^ ListaElectoralController::buscarListaElectoral(String^ anhoBuscar) {
	List<ListaElectoral^>^ listaPartidosEncontrados = gcnew List<ListaElectoral^>();
	array<String^>^ lineas = File::ReadAllLines("listasElectorales.txt");

	String^ separadores = ";";
	for each (String ^ lineaPartidoPolitico in lineas) {
		array<String^>^ palabras = lineaPartidoPolitico->Split(separadores->ToCharArray());
		int codigoLista = Convert::ToInt32(palabras[0]);
		String^ anho = palabras[1];
		int codigoPartido = Convert::ToInt32(palabras[2]);
		if (anho == anhoBuscar) {
			PartidoPolitico^ objCodigoPartido = buscarPartidoPoliticoxCodigo(codigoPartido);
			ListaElectoral^ objListaElectoral = gcnew ListaElectoral(codigoLista, anho, objCodigoPartido);
			List<Alumno^>^ listaElectoral = BuscarAlumnosListaElectoral(codigoPartido);
			objListaElectoral->objListaAlumnos = listaElectoral;
			this->listaElectoral->Add(objListaElectoral);
		}
	}
	return listaElectoral;
}