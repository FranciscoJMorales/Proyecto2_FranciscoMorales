#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>

class Evento
{
public:
	Evento *sig;
	Evento *ant;
	int a�o;
	int mes;
	int d�a;
	int horaInicio;
	int minutosInicio;
	int id;
	std::string descripci�n;
	int prioridad;

	Evento();
	~Evento();
	System::DateTime^ Evento::FechaInicio();
	virtual System::String^ Evento::ToString() const = 0;
};

