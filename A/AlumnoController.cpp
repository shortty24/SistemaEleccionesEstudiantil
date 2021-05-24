#include "AlumnoController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System::IO;

AlumnoController::AlumnoController() {
	this->listaAlumnos = gcnew List<Alumno^>();
}

Alumno^ AlumnoController::buscarAlumno(String^ codigoAlumno) {
	Alumno^ objAlumnoEncontrado; 
	array<String^>^ lineas = File::ReadAllLines("alumnos.txt");
	
	String^ separadores = ";";
	for each (String ^ lineaAlumno in lineas) {
		array<String^>^ palabras = lineaAlumno->Split(separadores->ToCharArray());
		String^ codigo = palabras[0];
		String^ nombre = palabras[1];
		String^ apellidoPaterno = palabras[2];
		String^ apellidoMaterno = palabras[3];
		String^ genero = palabras[4];
		int grado = Convert::ToInt32(palabras[5]);
		String^ seccion = palabras[6];
		String^ nivel = palabras[7];
		if (codigo == codigoAlumno) {
			objAlumnoEncontrado = gcnew Alumno(codigo, nombre, apellidoPaterno, apellidoMaterno, genero, grado, seccion, nivel);
			break;
		}
	}
	return objAlumnoEncontrado;
}

List<Alumno^>^ AlumnoController::buscarAlumnosxNivelxGradoxSeccion(String^ nivel, int grado, String^ seccion) {
	List<Alumno^>^ listaAlumnosEncontrados = gcnew List<Alumno^>();
	array<String^>^ lineas = File::ReadAllLines("alumnos.txt");

	String^ separadores = ";";
	for each (String ^ lineaAlumno in lineas) {
		array<String^>^ palabras = lineaAlumno->Split(separadores->ToCharArray());
		String^ codigo = palabras[0];
		String^ nombre = palabras[1];
		String^ apellidoPaterno = palabras[2];
		String^ apellidoMaterno = palabras[3];
		String^ genero = palabras[4];
		int gradoAlumno = Convert::ToInt32(palabras[5]);
		String^ seccionAlumno = palabras[6];
		String^ nivelAlumno = palabras[7];
		if (gradoAlumno==grado && nivelAlumno==nivel && seccionAlumno==seccion) {
			Alumno^ objAlumnoEncontrado = gcnew Alumno(codigo, nombre, apellidoPaterno, apellidoMaterno, genero, gradoAlumno, seccionAlumno, nivelAlumno);
			listaAlumnosEncontrados->Add(objAlumnoEncontrado);
		}
	}
	return listaAlumnosEncontrados;
}

int AlumnoController::verificarSiAlumnoPertenecePartidoPolitico(String^ codigoAlumno) {
	int pertenece = 0;
	array<String^>^ lineas = File::ReadAllLines("miembrosPartido.txt");
	String^ separadores = ";";
	for each (String ^ lineaAlumno in lineas) {
		array<String^>^ palabras = lineaAlumno->Split(separadores->ToCharArray());
		String^ codigoAlumnoArchivo = palabras[0];
		if (codigoAlumnoArchivo == codigoAlumno) {
			pertenece = 1;
			break;
		}
	}
	return pertenece;
}
