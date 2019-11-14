#pragma once
#include "Evento.h"
#include "Lista.h"
#include "Actividad.h"
#include "Recordatorio.h"
#include "Alarma.h"

using namespace System;
using namespace System::IO;

ref class Usuario
{
public:
	String^ nombre;
	String^ contraseña;
	Lista *eventos;

	Usuario(String^ info);
	void Usuario::Agregar(Evento *nuevo);
	String^ Usuario::Exportar();
	void Usuario::Ordenar(int caso);
	Evento *Usuario::Buscar(int caso);
	String^ Usuario::MostrarTareasDía(DateTime^ day);

private:
	bool Usuario::Comparar(Evento *a, Evento *b, int caso);
	void Usuario::Intercambiar(Evento *a, Evento *b);
};