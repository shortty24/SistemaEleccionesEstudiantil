#include "EleccionController.h"
#include "ListaElectoralController.h"
#include "MesaController.h"

using namespace SistemaEleccionesEstudiantilController;
using namespace System::IO;

EleccionController::EleccionController() {
	this->listaElecciones = gcnew List<Eleccion^>();
	this->objConexion = gcnew SqlConnection();
}

void EleccionController::AbrirConexion() {
	/*La cadena conexion está compuesto de: Servidor BD, nombre de BD, usuario de BD y contraseña de BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20165855;User ID=a20165855;Password=h7b3EJcM;";
	this->objConexion->Open(); /*Ya establecí la conexión con la BD*/
}

void EleccionController::CerrarConexion() {
	this->objConexion->Close();
}

Eleccion^ EleccionController::buscarEleccionActiva() {	
	Eleccion^ objEleccionActiva = nullptr;
	ListaElectoralController^ objGestorListaElectoral = gcnew ListaElectoralController();
	MesaController^ objGestorMesa = gcnew MesaController();

	AbrirConexion();
	SqlCommand^ objQuery = gcnew SqlCommand();
	objQuery->Connection = this->objConexion;
	objQuery->CommandText = "Select * from Eleccion where estado = 'A';";

	SqlDataReader^ objData = objQuery->ExecuteReader(); /*Cuando es un select, se utiliza el ExecuteReader*/
	while (objData->Read()) {
		int anho = safe_cast<int>(objData[0]);
		String^ fechaVotacion = safe_cast<String^>(objData[1]);
		String^ estado = safe_cast<String^>(objData[2]);

		objEleccionActiva = gcnew Eleccion(anho, fechaVotacion, estado);
		objEleccionActiva->objListaElectoral = objGestorListaElectoral->buscarListaElectoralesxAnho(anho);
		objEleccionActiva->listaMesas = objGestorMesa->buscarMesasVotacionxAnho(anho);

	}
	objData->Close();
	CerrarConexion();
	return objEleccionActiva;
}