#pragma once

namespace SistemaEleccionesEstudiantilController {
	using namespace SistemaEleccionesEstudiantilModel;
	using namespace System::Collections::Generic;
	using namespace System;
	
	public ref class AlumnoController {
	private:
		List<Alumno^>^ listaAlumnos;
	public:
		AlumnoController();
		Alumno^ buscarAlumno(String^ codigoAlumno);
		List<Alumno^>^ buscarAlumnosxNivelxGradoxSeccion(String^ nivel, int grado, String^ seccion);
		int verificarSiAlumnoPertenecePartidoPolitico(String^ codigoALumno);
	}; 
}