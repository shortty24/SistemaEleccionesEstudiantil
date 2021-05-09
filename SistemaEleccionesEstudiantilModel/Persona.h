#pragma once

using namespace System;

public ref class Persona {
protected:
	String^ objNombre;
	String^ objApellidoPaterno;
	String^ objApellidoMaterno;
	String^ objGenero;

public:
	Persona();
	Persona(String^ objNombre, String^ objApellidoPaterno, String^ objApellidoMaterno, String^ objGenero);
};