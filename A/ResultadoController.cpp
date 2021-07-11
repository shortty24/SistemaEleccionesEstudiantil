#include "ResultadoController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System::IO;

ResultadoController::ResultadoController() {
	this->objConexion = gcnew SqlConnection();
}

void ResultadoController::AbrirConexion() {
	/*La cadena conexion está compuesto de: Servidor BD, nombre de BD, usuario de BD y contraseña de BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20165855;User ID=a20165855;Password=h7b3EJcM;";
	this->objConexion->Open(); /*Ya establecí la conexión con la BD*/
}

void ResultadoController::CerrarConexion() {
	this->objConexion->Close();
}

void ResultadoController::RegistrarResultado(Resultado^ objResultado) {
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	//objQuery->CommandText = "insert	into Alumno values ('" +objAlumno->dni + "', '" + objAlumno->nombre + "', '" + objAlumno->apellidoPaterno + "', '" + objAlumno->apellidoMaterno;
	objQuery->CommandText = "insert	into Resultado (cantVotos, codigoListaElectoral, anhoEleccion) values (@p1,@p2,@p3);";

	/*Esto de los parámetros es solo para el INSERT*/
	SqlParameter^ p1 = gcnew SqlParameter("@p1", System::Data::SqlDbType::Int);
	p1->Value = objResultado->nroVotos;
	SqlParameter^ p2 = gcnew SqlParameter("@p2", System::Data::SqlDbType::Int);
	p2->Value = objResultado->objListaElectoral->codigo;
	SqlParameter^ p3 = gcnew SqlParameter("@p3", System::Data::SqlDbType::Int);
	p3->Value = objResultado->objListaElectoral->anhoEleccion;

	objQuery->Parameters->Add(p1);
	objQuery->Parameters->Add(p2);
	objQuery->Parameters->Add(p3);

	/*UPDATE, DELETE, INSERT no devuelven datos y, por lo tanto, deben utilizar el método ExecuteNonQuery*/
	objQuery->ExecuteNonQuery();
	CerrarConexion();
}