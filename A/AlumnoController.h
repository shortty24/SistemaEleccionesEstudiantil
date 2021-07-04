#pragma once

namespace SistemaEleccionesEstudiantilController {
	using namespace SistemaEleccionesEstudiantilModel;
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::Data::SqlClient;
	
	public ref class AlumnoController {

	private:
		List<Alumno^>^ listaAlumnos;
		SqlConnection^ objConexion;
	public:
		AlumnoController();
		Alumno^ buscarAlumno(String^ codigoAlumno);
		List<Alumno^>^ buscarAlumnosxNivelxGradoxSeccion(String^ nivel, int grado, String^ seccion);
		int verificarSiAlumnoPertenecePartidoPolitico(String^ codigoALumno);
		void AbrirConexion();
		void CerrarConexion();
		int validarExisteAlumno(String^ dni);
		Alumno^ buscarAlumnoxDNI(String^ dni);
		int buscarMesaVotacionxAlumno(String^ dni);
		List<Alumno^>^ buscarAlumnosxMesaVotacion(int codigoMesa);
		List<Alumno^>^ buscarAlumnosxPartido(int codigoPartido);
		void insertarAlumno(Alumno^ objAlumno);
	}; 
}