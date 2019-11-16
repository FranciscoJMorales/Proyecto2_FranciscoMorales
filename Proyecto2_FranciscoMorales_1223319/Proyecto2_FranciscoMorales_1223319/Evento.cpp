#include "Evento.h"


//Constructor, nunca es utilizado
Evento::Evento()
{
	sig = nullptr;
	ant = nullptr;
}


Evento::~Evento()
{
}

//Devuelve la fecha del evento, utilizado para hacer comparaciones
System::DateTime^ Evento::FechaInicio() {
	return gcnew System::DateTime(año, mes, día);
}