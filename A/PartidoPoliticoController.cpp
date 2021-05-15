#include "PartidoPoliticoController.h"
#include "AlumnoController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System;
using namespace System::IO;	/*Este es el namesapce que permite manipular las clases y métodos para manejo de archivos de texto*/

PartidoPoliticoController::PartidoPoliticoController() {
	this->listaPartidosPoliticos = gcnew List<PartidoPolitico^>();

}

void PartidoPoliticoController::CargarPartidosDesdeArchivo() {
	array<String^>^ lineas = File::ReadAllLines("partidosPoliticos.txt");

	String^ separadores = ";";
	for each (String ^ lineaPartidoPolitico in lineas) {
		array<String^>^ palabras = lineaPartidoPolitico->Split(separadores->ToCharArray());	
		int codigoPartido = Convert::ToInt32(palabras[0]);
		String^ nombrePartido = palabras[1];
		String^ simbolo = palabras[2];
		String^ fechaFundacion = palabras[3];
		PartidoPolitico^ objPartido = gcnew PartidoPolitico(codigoPartido, nombrePartido, simbolo, fechaFundacion);
		List<Alumno^>^ listaAlumnosPartido = BuscarAlumnosPartidoPolitico(codigoPartido);
		objPartido->listaAlumnos = listaAlumnosPartido;
		this->listaPartidosPoliticos->Add(objPartido);
	}
}

List<Alumno^>^ PartidoPoliticoController::BuscarAlumnosPartidoPolitico(int codigoPartido) {
	List<Alumno^>^ listaAlumnosEncontrados = gcnew List<Alumno^>();
	array<String^>^ lineas = File::ReadAllLines("miembrosPartido.txt");

	String^ separadores = ";";
	for each (String ^ lineaMiembroPartido in lineas) {
		array <String^>^ palabras = lineaMiembroPartido->Split(separadores->ToCharArray());
		String^ codigoAlumno = palabras[0];
		int codigoPartidoEncontrado = Convert::ToInt32(palabras[1]);
		if (codigoPartidoEncontrado == codigoPartido) {
			AlumnoController^ gestorAlumnoController = gcnew AlumnoController();
			Alumno^ objAlumno = gestorAlumnoController->buscarAlumno(codigoAlumno);
			listaAlumnosEncontrados->Add(objAlumno);
		} 
	}
	return listaAlumnosEncontrados;
}

int PartidoPoliticoController::ObtenerCantidadPartidos() {
	return this->listaPartidosPoliticos->Count;
}

PartidoPolitico^ PartidoPoliticoController::ObtenerPartidoLista(int indice) {
	return this->listaPartidosPoliticos[indice]; 
}