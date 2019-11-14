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
	/*bool Lista::Ordenado();
	bool Lista::OrdenadoGen();
	void Lista::Intercambiar(Evento *p1, Evento *p2);
	int Lista::LengthIntervalo(Pokemon *inicio, Pokemon *fin);
	Pokemon *Lista::ObtenerPrimeroGeneración(int g);
	Pokemon *Lista::ObtenerÚltimoGeneración(int g);

private:
	bool Lista::OrdenadoRecursivo(Pokemon *pos);
	bool Lista::OrdenadoGenRecursivo(Pokemon *pos);*/
private:
	void Lista::AgregarRecursivo(Evento *nuevo, Evento *pos);
	Evento *Lista::EliminarRecursivo(Evento *pos, int cantidad);
	System::String^Lista::StringRecursivo(Evento *pos);
};

