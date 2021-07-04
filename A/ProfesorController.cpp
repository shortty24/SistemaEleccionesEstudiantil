#include "ProfesorController.h"

using namespace SistemaEleccionesEstudiantilController;

ProfesorController::ProfesorController() {
	this->listaProfesores = gcnew List<Profesor^>();
	this->objConexion = gcnew SqlConnection();

}

void ProfesorController::AbrirConexion() {
	/*La cadena conexion está compuesto de: Servidor BD, nombre de BD, usuario de BD y contraseña de BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20165855;User ID=a20165855;Password=h7b3EJcM;";
	this->objConexion->Open(); /*Ya establecí la conexión con la BD*/
}

void ProfesorController::CerrarConexion() {
	this->objConexion->Close();
}

int ProfesorController::validarExisteProfesor(String^ dni) {
	int existe = 0;
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select * from Profesor where dni ='" + dni + "';";
	SqlDataReader^ objData=objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		existe = 1;
	}
	objData->Close();
	CerrarConexion();
	return existe;
}

List<Profesor^>^ ProfesorController::buscarProfesorxMesaVotacion(int codigoMesa) {
	List<Profesor^>^ listaProfesores= gcnew List<Profesor^>();
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select p.* from ProfesorxMesaVotacion axm, Profesor p where axm.codigoMesa = " + codigoMesa +
		" and  axm.dniProfesor=p.dni;";

	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		String^ dni = safe_cast<String^>(objData[0]);
		String^ nombres = safe_cast<String^>(objData[1]);
		String^ apellidoPaterno = safe_cast<String^>(objData[2]);
		String^ apellidoMaterno = safe_cast<String^>(objData[3]);
		String^ genero = safe_cast<String^>(objData[4]);
		String^ perfil = safe_cast<String^>(objData[5]);


		Profesor^ objProfesor = gcnew Profesor(dni, nombres, apellidoPaterno, apellidoMaterno, genero, perfil);
		listaProfesores->Add(objProfesor);
	}
	objData->Close();
	CerrarConexion();
	return listaProfesores;
}