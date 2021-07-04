#include "PartidoPoliticoController.h"
#include "AlumnoController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System;
using namespace System::IO;	/*Este es el namesapce que permite manipular las clases y m�todos para manejo de archivos de texto*/

PartidoPoliticoController::PartidoPoliticoController() {
	this->listaPartidosPoliticos = gcnew List<PartidoPolitico^>();
	this->objConexion = gcnew SqlConnection();
}

void PartidoPoliticoController::AbrirConexion() {
	/*La cadena conexion est� compuesto de: Servidor BD, nombre de BD, usuario de BD y contrase�a de BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20165855;User ID=a20165855;Password=h7b3EJcM;";
	this->objConexion->Open(); /*Ya establec� la conexi�n con la BD*/
}

void PartidoPoliticoController::CerrarConexion() {
	this->objConexion->Close();
}

List<PartidoPolitico^>^ PartidoPoliticoController::buscarPartidosBD() {
	AlumnoController^ objGestorAlumno = gcnew AlumnoController();
	List<PartidoPolitico^>^ listaPartidosPoliticos = gcnew List<PartidoPolitico^>();
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select * from PartidoPolitico;";
	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		String^ simbolo = safe_cast<String^>(objData[2]);
		String^ fecha = safe_cast<String^>(objData[3]);

		PartidoPolitico^ objPartido = gcnew PartidoPolitico(codigo, nombre, simbolo, fecha);
		objPartido->listaAlumnos = objGestorAlumno->buscarAlumnosxPartido(codigo);
		listaPartidosPoliticos->Add(objPartido);
	}
	objData->Close();
	CerrarConexion();

	return listaPartidosPoliticos;
}

void PartidoPoliticoController::CargarPartidosDesdeArchivo() {
	this->listaPartidosPoliticos->Clear();
	array<String^>^ lineas = File::ReadAllLines("partidosPoliticos.txt");

	String^ separadores = ";";
	for each (String^ lineaPartidoPolitico in lineas) {
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

void PartidoPoliticoController::GuardarPartidoPoliticoEnArchivo(PartidoPolitico^ objPartido) {
	this->listaPartidosPoliticos->Clear();
	CargarPartidosDesdeArchivo();
	this->listaPartidosPoliticos->Add(objPartido);
	/*Primero vamos a guardar la informaci�n de los miembros de los partidos en sus respectivos archivos*/
	/*1ro. Voy a contar cuantos miembros en total entre todos los partidos*/
	int totalMiembros = 0;
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartidoGrabar = this->listaPartidosPoliticos[i];
		totalMiembros = totalMiembros + objPartidoGrabar->listaAlumnos->Count;
	}
	array<String^>^ lineasArchivo = gcnew array<String^>(totalMiembros);
	int k = 0;
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartidoGrabar = this->listaPartidosPoliticos[i];
		for (int j = 0; j < objPartidoGrabar->listaAlumnos->Count; j++) {
			Alumno^ objAlumno = objPartidoGrabar->listaAlumnos[j];
			lineasArchivo[k] = objAlumno->dni + ";" + objPartidoGrabar->codigo;
			k++;
		}
	}
	/*Aqu� ya mi array de lineasArchivo est� OK, con la informaci�n a grabar*/
	File::WriteAllLines("miembrosPartido.txt", lineasArchivo);
	
	array<String^>^ lineasArchivoPartido = gcnew array<String^>(this->listaPartidosPoliticos->Count);
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartido = this->listaPartidosPoliticos[i];
		lineasArchivoPartido[i] = objPartido->codigo + ";" + objPartido->nombre + ";" + objPartido->simbolo + ";" + objPartido->fechaFundacion;
	}
	/*Aqu� ya mi array de lineasArchivoPartido est� OK, con la informaci�n a grabar*/
	File::WriteAllLines("partidosPoliticos.txt", lineasArchivoPartido);
}

List<PartidoPolitico^>^ PartidoPoliticoController::obtenerListaPartidos() {
	return this->listaPartidosPoliticos;
}

List<PartidoPolitico^>^ PartidoPoliticoController::buscarPartidos(String^ nombreBuscar) {
	List<PartidoPolitico^>^ listaPartidosEncontrados = gcnew List<PartidoPolitico^>();
	array<String^>^ lineas = File::ReadAllLines("partidosPoliticos.txt");

	String^ separadores = ";";
	for each (String ^ lineaPartidoPolitico in lineas) {
		array<String^>^ palabras = lineaPartidoPolitico->Split(separadores->ToCharArray());
		int codigoPartido = Convert::ToInt32(palabras[0]);
		String^ nombrePartido = palabras[1];
		String^ simbolo = palabras[2];
		String^ fechaFundacion = palabras[3];
		if (nombrePartido->ToUpper() == nombreBuscar->ToUpper()) {
			PartidoPolitico^ objPartido = gcnew PartidoPolitico(codigoPartido, nombrePartido, simbolo, fechaFundacion);
			List<Alumno^>^ listaAlumnosPartido = BuscarAlumnosPartidoPolitico(codigoPartido);
			objPartido->listaAlumnos = listaAlumnosPartido;
			listaPartidosEncontrados->Add(objPartido);
		}
	}
	return listaPartidosEncontrados;
} 

void PartidoPoliticoController::eliminarPartidoPolitico(int codigoPartidoEliminar) {
	CargarPartidosDesdeArchivo();
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartido = this->listaPartidosPoliticos[i];
		if (objPartido->codigo == codigoPartidoEliminar) {
			this->listaPartidosPoliticos->RemoveAt(i);
			break;
		}
	}

	/*Primero vamos a guardar la informaci�n de los miembros de los partidos en sus respectivos archivos*/
	/*1ro. Voy a contar cuantos miembros en total entre todos los partidos*/
	int totalMiembros = 0;
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartidoGrabar = this->listaPartidosPoliticos[i];
		totalMiembros = totalMiembros + objPartidoGrabar->listaAlumnos->Count;
	}
	array<String^>^ lineasArchivo = gcnew array<String^>(totalMiembros);
	int k = 0;
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartidoGrabar = this->listaPartidosPoliticos[i];
		for (int j = 0; j < objPartidoGrabar->listaAlumnos->Count; j++) {
			Alumno^ objAlumno = objPartidoGrabar->listaAlumnos[j];
			lineasArchivo[k] = objAlumno->dni + ";" + objPartidoGrabar->codigo;
			k++;
		}
	}
	/*Aqu� ya mi array de lineasArchivo est� OK, con la informaci�n a grabar*/
	File::WriteAllLines("miembrosPartido.txt", lineasArchivo);

	array<String^>^ lineasArchivoPartido = gcnew array<String^>(this->listaPartidosPoliticos->Count);
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartido = this->listaPartidosPoliticos[i];
		lineasArchivoPartido[i] = objPartido->codigo + ";" + objPartido->nombre + ";" + objPartido->simbolo + ";" + objPartido->fechaFundacion;
	}
	/*Aqu� ya mi array de lineasArchivoPartido est� OK, con la informaci�n a grabar*/
	File::WriteAllLines("partidosPoliticos.txt", lineasArchivoPartido);
}

PartidoPolitico^ PartidoPoliticoController::buscarPartidoPoliticoxCodigo(int codigoPartido) {
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
			List<Alumno^>^ listaAlumnosPartido = BuscarAlumnosPartidoPolitico(codigoPartido);
			objPartidoPoliticoEncontrado->listaAlumnos = listaAlumnosPartido;
			break;
		}
	}
	return objPartidoPoliticoEncontrado;
}

void PartidoPoliticoController::EditarPartidoPolitico(int codigoPartidoEditar, List<Alumno^>^ listaMiembros) {
	this->listaPartidosPoliticos->Clear();
	CargarPartidosDesdeArchivo();
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartido = this->listaPartidosPoliticos[i];
		if (objPartido->codigo == codigoPartidoEditar) {
			this->listaPartidosPoliticos[i]->listaAlumnos=listaMiembros;
			break;
		}
	}

	/*Primero vamos a guardar la informaci�n de los miembros de los partidos en sus respectivos archivos*/
	/*1ro. Voy a contar cuantos miembros en total entre todos los partidos*/
	int totalMiembros = 0;
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartidoGrabar = this->listaPartidosPoliticos[i];
		totalMiembros = totalMiembros + objPartidoGrabar->listaAlumnos->Count;
	}
	array<String^>^ lineasArchivo = gcnew array<String^>(totalMiembros);
	int k = 0;
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartidoGrabar = this->listaPartidosPoliticos[i];
		for (int j = 0; j < objPartidoGrabar->listaAlumnos->Count; j++) {
			Alumno^ objAlumno = objPartidoGrabar->listaAlumnos[j];
			lineasArchivo[k] = objAlumno->dni + ";" + objPartidoGrabar->codigo;
			k++;
		}
	}
	/*Aqu� ya mi array de lineasArchivo est� OK, con la informaci�n a grabar*/
	File::WriteAllLines("miembrosPartido.txt", lineasArchivo);

	array<String^>^ lineasArchivoPartido = gcnew array<String^>(this->listaPartidosPoliticos->Count);
	for (int i = 0; i < this->listaPartidosPoliticos->Count; i++) {
		PartidoPolitico^ objPartido = this->listaPartidosPoliticos[i];
		lineasArchivoPartido[i] = objPartido->codigo + ";" + objPartido->nombre + ";" + objPartido->simbolo + ";" + objPartido->fechaFundacion;
	}
	/*Aqu� ya mi array de lineasArchivoPartido est� OK, con la informaci�n a grabar*/
	File::WriteAllLines("partidosPoliticos.txt", lineasArchivoPartido);
}