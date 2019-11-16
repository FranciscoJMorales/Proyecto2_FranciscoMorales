#pragma once
#include "Evento.h"

class Lista
{
public:
	Evento *head;
	Evento *tail;
	int length;

	Lista();
	~Lista();
	void Lista::Agregar(Evento *nuevo);
	Evento *Lista::Eliminar(int posicion);
	System::String^Lista::String();

private:
	void Lista::AgregarRecursivo(Evento *nuevo, Evento *pos);
	Evento *Lista::EliminarRecursivo(Evento *pos, int cantidad);
	System::String^Lista::StringRecursivo(Evento *pos);
};

