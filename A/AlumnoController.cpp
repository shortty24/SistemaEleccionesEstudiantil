#include "AlumnoController.h"
#include "MesaController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System::IO;

AlumnoController::AlumnoController() {
	this->listaAlumnos = gcnew List<Alumno^>();
	this->objConexion = gcnew SqlConnection();
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
			objAlumnoEncontrado = gcnew Alumno(nombre, apellidoPaterno, apellidoMaterno, genero, grado, seccion, nivel);
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
			Alumno^ objAlumnoEncontrado = gcnew Alumno(nombre, apellidoPaterno, apellidoMaterno, genero, gradoAlumno, seccionAlumno, nivelAlumno);
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

void AlumnoController::AbrirConexion() {
	/*La cadena conexion está compuesto de: Servidor BD, nombre de BD, usuario de BD y contraseña de BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20165855;User ID=a20165855;Password=h7b3EJcM;";
	this->objConexion->Open(); /*Ya establecí la conexión con la BD*/
}

void AlumnoController::CerrarConexion() {
	this->objConexion->Close();
}

int AlumnoController::validarExisteAlumno(String^ dni) {
	int existe = 0;
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select * from Alumno where dni ='" + dni + "';";
	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		existe = 1;
	}
	objData->Close();
	CerrarConexion();
	return existe;
}

Alumno^ AlumnoController::buscarAlumnoxDNI(String^ dni) {
	Alumno^ objAlumno = nullptr;
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select * from Alumno where dni ='" + dni + "';";
	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		String^ dni = safe_cast<String^>(objData[0]);
		String^ nombres = safe_cast<String^>(objData[1]);
		String^ apellidoPaterno = safe_cast<String^>(objData[2]);
		String^ apellidoMaterno = safe_cast<String^>(objData[3]);
		String^ genero = safe_cast<String^>(objData[4]);
		int grado = safe_cast<int>(objData[5]);
		String^ seccion = safe_cast<String^>(objData[6]);
		String^ nivel = safe_cast<String^>(objData[7]);

		objAlumno = gcnew Alumno(dni, nombres, apellidoPaterno, apellidoMaterno, genero, grado, seccion, nivel);
	}
	objData->Close();
	CerrarConexion();
	return objAlumno;
}

int AlumnoController::buscarMesaVotacionxAlumno(String^ dni) {
	int codigoMesa;
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select * from AlumnoxMesaVotacion where dniAlumno ='" + dni + "';";
	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		codigoMesa = safe_cast<int>(objData[0]);
	}
	objData->Close();
	CerrarConexion();
	return codigoMesa;
}

List<Alumno^>^ AlumnoController::buscarAlumnosxMesaVotacion(int codigoMesa) {
	List<Alumno^>^ listaAlumnos = gcnew List<Alumno^>();
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select a.* from AlumnoxMesaVotacion axm, Alumno a where axm.codigoMesa = "+ codigoMesa + 
							" and  axm.dniAlumno=a.dni;";

	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		String^ dni = safe_cast<String^>(objData[0]);
		String^ nombres = safe_cast<String^>(objData[1]);
		String^ apellidoPaterno = safe_cast<String^>(objData[2]);
		String^ apellidoMaterno = safe_cast<String^>(objData[3]);
		String^ genero = safe_cast<String^>(objData[4]);
		int grado = safe_cast<int>(objData[5]);
		String^ seccion = safe_cast<String^>(objData[6]);
		String^ nivel = safe_cast<String^>(objData[7]);

		Alumno^ objAlumno = gcnew Alumno(dni, nombres, apellidoPaterno, apellidoMaterno, genero, grado, seccion, nivel);
		listaAlumnos->Add(objAlumno);
	}
	objData->Close();
	CerrarConexion();
	return listaAlumnos;
}

List<Alumno^>^ AlumnoController::buscarAlumnosxPartido(int codigoPartido) {
	List<Alumno^>^ listaAlumnos = gcnew List<Alumno^>();
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select a.* from AlumnoxPartidoPolitico axp, Alumno a where axp.codigoPartido = " + codigoPartido +
		" and  axp.dniAlumno=a.dni;";

	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		String^ dni = safe_cast<String^>(objData[0]);
		String^ nombres = safe_cast<String^>(objData[1]);
		String^ apellidoPaterno = safe_cast<String^>(objData[2]);
		String^ apellidoMaterno = safe_cast<String^>(objData[3]);
		String^ genero = safe_cast<String^>(objData[4]);
		int grado = safe_cast<int>(objData[5]);
		String^ seccion = safe_cast<String^>(objData[6]);
		String^ nivel = safe_cast<String^>(objData[7]);

		Alumno^ objAlumno = gcnew Alumno(dni, nombres, apellidoPaterno, apellidoMaterno, genero, grado, seccion, nivel);
		listaAlumnos->Add(objAlumno);
	}
	objData->Close();
	CerrarConexion();
	return listaAlumnos;
}

void AlumnoController::insertarAlumno(Alumno^ objAlumno) {
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	//objQuery->CommandText = "insert	into Alumno values ('" +objAlumno->dni + "', '" + objAlumno->nombre + "', '" + objAlumno->apellidoPaterno + "', '" + objAlumno->apellidoMaterno;
	objQuery->CommandText = "insert	into Alumno values(@p1,@p2,@p3,@p4,@p5,@p6,@p7,@p8);";

	/*Esto de los parámetros es solo para el INSERT*/
	SqlParameter^ p1 = gcnew SqlParameter("@p1", System::Data::SqlDbType::VarChar, 8);
	p1->Value = objAlumno->dni;
	SqlParameter^ p2 = gcnew SqlParameter("@p2", System::Data::SqlDbType::VarChar, 30);
	p2->Value = objAlumno->nombre;
	SqlParameter^ p3 = gcnew SqlParameter("@p3", System::Data::SqlDbType::VarChar, 30);
	p3->Value = objAlumno->apellidoPaterno;
	SqlParameter^ p4 = gcnew SqlParameter("@p4", System::Data::SqlDbType::VarChar, 30);
	p4->Value = objAlumno->apellidoMaterno;
	SqlParameter^ p5 = gcnew SqlParameter("@p5", System::Data::SqlDbType::VarChar, 1);
	p5->Value = objAlumno->genero;
	SqlParameter^ p6 = gcnew SqlParameter("@p6", System::Data::SqlDbType::Int);
	p6->Value = objAlumno->grado;
	SqlParameter^ p7 = gcnew SqlParameter("@p7", System::Data::SqlDbType::VarChar, 1);
	p7->Value = objAlumno->seccion;
	SqlParameter^ p8 = gcnew SqlParameter("@p8", System::Data::SqlDbType::VarChar, 30);
	p8->Value = objAlumno->nivel;
	objQuery->Parameters->Add(p1);
	objQuery->Parameters->Add(p2);
	objQuery->Parameters->Add(p3);
	objQuery->Parameters->Add(p4);
	objQuery->Parameters->Add(p5);
	objQuery->Parameters->Add(p6);
	objQuery->Parameters->Add(p7);
	objQuery->Parameters->Add(p8);
	/*UPDATE, DELETE, INSERT no devuelven datos y, por lo tanto, deben utilizar el método ExecuteNonQuery*/
	objQuery->ExecuteNonQuery();
	CerrarConexion();
}

List<Alumno^>^ AlumnoController::buscarAlumnosxListaElectoral(int codigoLista) {
	List<Alumno^>^ listaAlumnos = gcnew List<Alumno^>();
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select a.* from AlumnoxListaElectoral al, Alumno a" +
							" where al.codigoLista = "+ codigoLista +" and al.dniAlumno = a.dni; ";

	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		String^ dni = safe_cast<String^>(objData[0]);
		String^ nombres = safe_cast<String^>(objData[1]);
		String^ apellidoPaterno = safe_cast<String^>(objData[2]);
		String^ apellidoMaterno = safe_cast<String^>(objData[3]);
		String^ genero = safe_cast<String^>(objData[4]);
		int grado = safe_cast<int>(objData[5]);
		String^ seccion = safe_cast<String^>(objData[6]);
		String^ nivel = safe_cast<String^>(objData[7]);

		Alumno^ objAlumno = gcnew Alumno(dni, nombres, apellidoPaterno, apellidoMaterno, genero, grado, seccion, nivel);
		listaAlumnos->Add(objAlumno);
	}
	objData->Close();
	CerrarConexion();
	return listaAlumnos;
}