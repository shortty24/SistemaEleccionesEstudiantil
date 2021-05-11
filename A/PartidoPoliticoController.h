#pragma once

namespace SistemaEleccionesEstudiantilController {
	using namespace System::Collections::Generic;
	using namespace SistemaEleccionesEstudiantilModel;

	public ref class PartidoPoliticoController {
	private:
		List<PartidoPolitico^>^ listaPartidosPoliticos;
	
	public:
		PartidoPoliticoController();
	};
}