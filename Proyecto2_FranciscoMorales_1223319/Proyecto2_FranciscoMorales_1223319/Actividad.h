#pragma once
#include "Evento.h"
#include <string>
#include <msclr\marshal_cppstd.h>

class Actividad : public Evento
{
public:
	int horaFin;
	int minutosFin;
	std::string personas;
	std::string lugar;
	std::string materiales;

	Actividad(System::String^ info);
	Actividad(int ID, System::String^ info, System::DateTime^ fecha, int hF, int minF, int P, System::String^ people, System::String^ place, System::String^ material);
	~Actividad();
	System::String^ Actividad::ToString() const override;
	bool Actividad::Mostrar() const override;
};

