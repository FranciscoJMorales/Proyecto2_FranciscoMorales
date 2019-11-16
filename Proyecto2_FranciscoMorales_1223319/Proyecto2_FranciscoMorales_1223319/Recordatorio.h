#pragma once
#include "Evento.h"
#include <string>
#include <msclr\marshal_cppstd.h>

class Recordatorio : public Evento
{
public:
	Recordatorio(System::String^ info);
	Recordatorio(int ID, System::String^ info, System::DateTime^ fecha, int P);
	Recordatorio();
	~Recordatorio();
	System::String^ Recordatorio::ToString() const override;
	bool Recordatorio::Mostrar() const override;
};