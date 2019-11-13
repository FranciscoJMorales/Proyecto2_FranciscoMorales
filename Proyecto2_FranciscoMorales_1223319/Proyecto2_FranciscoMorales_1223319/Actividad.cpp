#include "Actividad.h"



Actividad::Actividad(System::String^ ID, System::String^ Description)
{
	sig = nullptr;
	ant = nullptr;
}


Actividad::~Actividad()
{
}

System::String^ Actividad::ToString() const {
	return "";
}