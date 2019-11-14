#pragma once
#include "Evento.h"
#include <string>
#include <msclr\marshal_cppstd.h>

class Recordatorio : public Evento
{
public:
	Recordatorio(System::String^ info);
	Recordatorio(int ID, System::String^ info, System::DateTime^ fecha, int hF, int minF, int P);
	Recordatorio();
	~Recordatorio();
	void Recordatorio::Postponer();
	System::String^ Recordatorio::ToString() const override;
};