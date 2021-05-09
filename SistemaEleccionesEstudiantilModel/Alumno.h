#pragma once
#include "Persona.h"
using namespace System;

public ref class Alumno : public Persona {
private:
	int codigo;
	int grado;
	char seccion;
	String^ objNivel;
	 
public:
	Alumno();
	Alumno(int codigo, int grado, char seccion, String^ objNivel);
};