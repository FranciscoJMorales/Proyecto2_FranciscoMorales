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
	String^ Usuario::Buscar(int caso, String^ valorBuscar);
	String^ Usuario::MostrarTareasDía(DateTime^ day);
	int Usuario::ObtenerNuevoId();
	void Usuario::RevisarEventos(DateTime^ hora);

private:
	int Usuario::Comparar(Evento *a, Evento *b, int caso);
	void Usuario::Intercambiar(Evento *a, Evento *b);
};