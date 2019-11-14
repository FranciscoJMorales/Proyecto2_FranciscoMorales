#include "Evento.h"



Evento::Evento()
{
	sig = nullptr;
	ant = nullptr;
}


Evento::~Evento()
{
}

System::DateTime^ Evento::FechaInicio() {
	return gcnew System::DateTime(año, mes, día);
}