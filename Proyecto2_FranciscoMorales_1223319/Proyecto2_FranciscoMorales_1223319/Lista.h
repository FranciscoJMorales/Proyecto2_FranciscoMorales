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
	/*bool Lista::Ordenado();
	bool Lista::OrdenadoGen();
	void Lista::Intercambiar(Pokemon *p1, Pokemon *p2);
	int Lista::LengthIntervalo(Pokemon *inicio, Pokemon *fin);
	Pokemon *Lista::ObtenerPrimeroGeneración(int g);
	Pokemon *Lista::ObtenerÚltimoGeneración(int g);
	System::String^Lista::String();

private:
	bool Lista::OrdenadoRecursivo(Pokemon *pos);
	bool Lista::OrdenadoGenRecursivo(Pokemon *pos);
	System::String^Lista::StringRecursivo(Pokemon *pos);*/
	void Lista::AgregarRecursivo(Evento *nuevo, Evento *pos);
	Evento *Lista::EliminarRecursivo(Evento *pos, int cantidad);
};

