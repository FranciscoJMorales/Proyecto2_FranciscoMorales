#pragma once
#include "Evento.h"
#include <string>
#include <msclr\marshal_cppstd.h>

class Actividad : public Evento
{
public:
	int horaFin;
	Actividad *sig;
	std::string personas;
	std::string lugar;
	std::string materiales;

	Actividad(System::String^ ID, System::String^ Description);
	~Actividad();
	System::String^ Actividad::ToString() const override;
};

