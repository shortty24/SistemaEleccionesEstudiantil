#include "VotoController.h"


using namespace SistemaEleccionesEstudiantilController;
using namespace System::IO;

VotoController::VotoController() {
	this->objConexion = gcnew SqlConnection();
}

void VotoController::AbrirConexion() {
	/*La cadena conexion está compuesto de: Servidor BD, nombre de BD, usuario de BD y contraseña de BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20165855;User ID=a20165855;Password=h7b3EJcM;";
	this->objConexion->Open(); /*Ya establecí la conexión con la BD*/
}

void VotoController::CerrarConexion() {
	this->objConexion->Close();
}

void VotoController::RegistrarVoto(Voto^ objVoto) {
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	//objQuery->CommandText = "insert	into Alumno values ('" +objAlumno->dni + "', '" + objAlumno->nombre + "', '" + objAlumno->apellidoPaterno + "', '" + objAlumno->apellidoMaterno;
	objQuery->CommandText = "insert	into Voto (fechaVotacion, codigoMesa, codigoListaElectoral) values (@p1,@p2,@p3);";

	/*Esto de los parámetros es solo para el INSERT*/
	SqlParameter^ p1 = gcnew SqlParameter("@p1", System::Data::SqlDbType::VarChar, 10);
	p1->Value = objVoto->fechaVotacion;
	SqlParameter^ p2 = gcnew SqlParameter("@p2", System::Data::SqlDbType::Int);
	p2->Value = objVoto->objMesaVotacion->codigo;
	SqlParameter^ p3 = gcnew SqlParameter("@p3", System::Data::SqlDbType::Int);
	p3->Value = objVoto->objListaElectoral->codigo;

	objQuery->Parameters->Add(p1);
	objQuery->Parameters->Add(p2);
	objQuery->Parameters->Add(p3);
	
	/*UPDATE, DELETE, INSERT no devuelven datos y, por lo tanto, deben utilizar el método ExecuteNonQuery*/
	objQuery->ExecuteNonQuery();
	CerrarConexion();
}

int VotoController::ContarVotos(String^ fechaVotacion, int codigListaElectoral) {
	int nroVotos = 0;
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select count(*) from Voto where fechaVotacion='"+fechaVotacion+"' and codigoListaElectoral="+codigListaElectoral+";";
	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		nroVotos = safe_cast<int>(objData[0]);
	}
	objData->Close();
	CerrarConexion();

	return nroVotos;
}