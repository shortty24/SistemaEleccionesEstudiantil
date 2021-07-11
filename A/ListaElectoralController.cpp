#include "ListaElectoralController.h"
#include "AlumnoController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace SistemaEleccionesEstudiantilModel;
using namespace System;
using namespace System::IO;

ListaElectoralController::ListaElectoralController() {
	this->listaElectoral = gcnew List<ListaElectoral^>();
	this->objConexion = gcnew SqlConnection();
}

/*Métodos con base de datos*/
void ListaElectoralController::AbrirConexion() {
	/*La cadena conexion está compuesto de: Servidor BD, nombre de BD, usuario de BD y contraseña de BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20165855;User ID=a20165855;Password=h7b3EJcM;";
	this->objConexion->Open(); /*Ya establecí la conexión con la BD*/
}

void ListaElectoralController::CerrarConexion() {
	this->objConexion->Close();
}

List<ListaElectoral^>^ ListaElectoralController::buscarListaElectorales() {
	List<ListaElectoral^>^ listasElectoreles = gcnew List<ListaElectoral^>();
	AlumnoController^ objGestorAlumno = gcnew AlumnoController();
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select * from ListaElectoral l, PartidoPolitico p" +
							" where l.codigoPartido = p.Codigo;";

	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		int codigoLista = safe_cast<int>(objData[0]);
		String^ anho = Convert::ToString(safe_cast<int>(objData[1]));
		int codigoPartido= safe_cast<int>(objData[2]);
		String^ nombre = safe_cast<String^>(objData[4]);
		String^ simbolo = safe_cast<String^>(objData[5]);
		String^ fechaFundacion = safe_cast<String^>(objData[6]);

		PartidoPolitico^ objPartidoPolitico = gcnew PartidoPolitico(codigoPartido, nombre, simbolo, fechaFundacion);

		ListaElectoral^ objListaElectoral= gcnew ListaElectoral(codigoLista, anho, objPartidoPolitico);

		objListaElectoral->objListaAlumnos = objGestorAlumno->buscarAlumnosxListaElectoral(codigoLista);
		listasElectoreles->Add(objListaElectoral);
	}
	objData->Close();
	CerrarConexion();
	return listasElectoreles;
}

List<ListaElectoral^>^ ListaElectoralController::buscarListaElectoralesxAnho(int anho) {
	List<ListaElectoral^>^ listasElectoreles = gcnew List<ListaElectoral^>();
	AlumnoController^ objGestorAlumno = gcnew AlumnoController();
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select * from ListaElectoral l, PartidoPolitico p where l.codigoPartido = p.Codigo and l.anho=" + anho + ";";

	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		int codigoLista = safe_cast<int>(objData[0]);
		String^ anho = Convert::ToString(safe_cast<int>(objData[1]));
		int codigoPartido = safe_cast<int>(objData[2]);
		String^ nombre = safe_cast<String^>(objData[4]);
		String^ simbolo = safe_cast<String^>(objData[5]);
		String^ fechaFundacion = safe_cast<String^>(objData[6]);

		PartidoPolitico^ objPartidoPolitico = gcnew PartidoPolitico(codigoPartido, nombre, simbolo, fechaFundacion);

		ListaElectoral^ objListaElectoral = gcnew ListaElectoral(codigoLista, anho, objPartidoPolitico);

		objListaElectoral->objListaAlumnos = objGestorAlumno->buscarAlumnosxListaElectoral(codigoLista);
		listasElectoreles->Add(objListaElectoral);
	}
	objData->Close();
	CerrarConexion();
	return listasElectoreles;
}






/*Métodos con archivos .txt*/
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