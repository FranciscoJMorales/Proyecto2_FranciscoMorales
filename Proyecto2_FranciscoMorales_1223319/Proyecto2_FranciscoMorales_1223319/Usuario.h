#pragma once
#include "Evento.h"
#include "Lista.h"
#include "Actividad.h"
#include "Recordatorio.h"
#include "Alarma.h"

using namespace System;

ref class Usuario
{
public:
	String^ nombre;
	String^ contraseña;
	Lista *eventos;

	Usuario(String^ name);
	String^ Usuario::Exportar();
	void Usuario::Importar(String^ archivo);
	Evento *Usuario::Buscar(int caso);
};