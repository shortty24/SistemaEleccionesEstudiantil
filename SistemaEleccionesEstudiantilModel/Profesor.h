#pragma once
#include "Persona.h"

public ref class Profesor :public Persona {
	private:
		int codigo;
		String^ objPerfil;
	

	public:
		Profesor();
		Profesor(int codigo, String^ objPerfi);
};