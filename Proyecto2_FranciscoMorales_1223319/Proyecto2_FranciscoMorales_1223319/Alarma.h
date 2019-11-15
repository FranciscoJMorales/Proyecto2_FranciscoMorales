#pragma once
#include "Evento.h"
#include "Recordatorio.h"
#include <string>
#include <msclr\marshal_cppstd.h>

class Alarma : public Recordatorio
{
public:
	Alarma(System::String^ info);
	Alarma(int ID, System::String^ info, System::DateTime^ fecha, int P);
	~Alarma();
	System::String^ Alarma::ToString() const override;
};