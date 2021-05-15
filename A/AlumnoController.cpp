#include "AlumnoController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System::IO;

AlumnoController::AlumnoController() {
	this->listaAlumnos = gcnew List<Alumno^>();
}

Alumno^ AlumnoController::buscarAlumno(String^ coodigoAlumno) {
	Alumno^ objAlumnoEncontrado; 
	array<String^>^ lineas = File::ReadAllLines("alumnos.txt");
	
	String^ separadores = ";";
	for each (String ^ lineaAlumno in lineas) {
		array<String^>^ palabras = lineaAlumno->Split(separadores->ToCharArray());
		String^ codigo = palabras[0];
		String^ nombre = palabras[0];
		String^ apellidoPaterno = palabras[2];
		String^ apellidoMaterno = palabras[3];
		String^ genero = palabras[4];
		int grado = Convert::ToInt32(palabras[5]);
		String^ seccion = palabras[6];
		String^ nivel = palabras[7];
		if (codigo == coodigoAlumno) {
			objAlumnoEncontrado = gcnew Alumno(codigo, nombre, apellidoPaterno, apellidoMaterno, genero, grado, seccion, nivel);
			break;
		}
	}
	return objAlumnoEncontrado;
}