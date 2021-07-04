#include "MesaController.h"
#include "AlumnoController.h"
#include "ProfesorController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System::IO;

MesaController::MesaController() {
	this->listaMesaVotacion = gcnew List<MesaVotacion^>();
	this->objConexion = gcnew SqlConnection();
}

void MesaController::AbrirConexion() {
	/*La cadena conexion está compuesto de: Servidor BD, nombre de BD, usuario de BD y contraseña de BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20165855;User ID=a20165855;Password=h7b3EJcM;";
	this->objConexion->Open(); /*Ya establecí la conexión con la BD*/
}

void MesaController::CerrarConexion() {
	this->objConexion->Close();
}

MesaVotacion^ MesaController::buscarMesaVotacionxAlumno(String^ dni){
	AlumnoController^ objGestorAlumnoController = gcnew AlumnoController();
	int codigoMesa = objGestorAlumnoController->buscarMesaVotacionxAlumno(dni);
	MesaVotacion^ objMesaVotacion;
	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "select * from MesaVotacion where codigo =" + codigoMesa + ";";
	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		int nroMesa = safe_cast<int>(objData[1]);
		int nroAula = safe_cast<int>(objData[2]);

		objMesaVotacion = gcnew MesaVotacion(codigoMesa, nroMesa, nroAula);
	}
	objData->Close();
	CerrarConexion();

	ProfesorController^ objGestorProfesorController = gcnew ProfesorController();
	objMesaVotacion->objListaElectores = objGestorAlumnoController->buscarAlumnosxMesaVotacion(codigoMesa);
	objMesaVotacion->objListaMiembrosMesa = objGestorProfesorController->buscarProfesorxMesaVotacion(codigoMesa);
	return objMesaVotacion;
}

