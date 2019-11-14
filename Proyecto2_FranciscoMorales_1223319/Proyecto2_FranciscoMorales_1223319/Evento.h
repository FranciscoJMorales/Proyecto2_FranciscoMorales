#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>

class Evento
{
public:
	Evento *sig;
	Evento *ant;
	int año;
	int mes;
	int día;
	int horaInicio;
	int minutosInicio;
	int id;
	std::string descripción;
	int prioridad;

	Evento();
	~Evento();
	System::DateTime^ Evento::FechaInicio();
	virtual System::String^ Evento::ToString() const = 0;
};

