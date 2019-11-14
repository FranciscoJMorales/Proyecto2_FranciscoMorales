#include "Usuario.h"



Usuario::Usuario(String^ info)
{
	eventos = new Lista();
	nombre = info->Substring(0, info->IndexOf(","));
	info = info->Remove(0, info->IndexOf(",") + 1);
	contraseña = info->Substring(0, info->IndexOf("\r\n"));
	info = info->Remove(0, info->IndexOf("\r\n") + 2);
	while (info->IndexOf("\r\n") != -1) {
		String^ tipo = info->Substring(0, info->IndexOf(","));
		info = info->Remove(0, info->IndexOf(",") + 1);
		if (tipo == "Actividad") {
			eventos->Agregar(new Actividad(info->Substring(0, info->IndexOf("\r\n"))));
		}
		else if (tipo == "Recordatorio") {
			eventos->Agregar(new Recordatorio(info->Substring(0, info->IndexOf("\r\n"))));
		}
		else {
			eventos->Agregar(new Alarma(info->Substring(0, info->IndexOf("\r\n"))));
		}
		info = info->Remove(0, info->IndexOf("\r\n") + 2);
	}
}

void Usuario::Agregar(Evento *nuevo) {
	nuevo->id = eventos->length;
	eventos->Agregar(nuevo);
	StreamWriter^ escritor = gcnew StreamWriter("..//" + nombre + ".txt", true);
	escritor->Write(nuevo->ToString());
	escritor->Close();
}

String^ Usuario::Exportar() {
	String^ info = nombre + "," + contraseña + "\r\n";
	info += eventos->String();
	return info;
}

void Usuario::Ordenar(int caso) {
	Evento *i = eventos->head;
	int n = 0;
	bool intercambio = true;
	do {
		intercambio = false;
		n = 0;
		i = eventos->head;
		while (n < eventos->length - 1) {
			intercambio = Comparar(i, i->sig, caso);
			n++;
			i = i->sig;
		}
	} while (intercambio);
	StreamWriter^ escritor = gcnew StreamWriter("..//" + nombre + ".txt", false);
	escritor->Write(Exportar());
	escritor->Close();
}
Evento *Usuario::Buscar(int caso) {
	return nullptr;
}

bool Usuario::Comparar(Evento *a, Evento *b, int caso) {
	int c = a->FechaInicio()->CompareTo(b->FechaInicio());
	if (a->FechaInicio()->CompareTo(b->FechaInicio()) > 0) {
		Intercambiar(a, b);
		return true;
	}
	else if (a->FechaInicio()->CompareTo(b->FechaInicio()) == 0) {
		switch (caso) {
		//Ordenar por identificador
		case 0:
			if (a->id > b->id) {
				Intercambiar(a, b);
				return true;
			}
			else {
				return false;
			}
			break;
		//Ordenar por fecha (incluyendo horas y minutos)
		case 1:
			if (a->horaInicio > b->horaInicio || (a->horaInicio == b->horaInicio && a->minutosInicio > b->minutosInicio)) {
				Intercambiar(a, b);
				return true;
			}
			else {
				return false;
			}
			break;
		//Ordenar por prioridad
		case 2:
			if (a->prioridad < b->prioridad) {
				Intercambiar(a, b);
				return true;
			}
			else {
				return false;
			}
			break;
		//Ordenar por fecha (Sin incluir horas y minutos)
		case 3:
			return false;
			break;
		}
	}
	else {
		return false;
	}
}

void Usuario::Intercambiar(Evento *a, Evento *b) {
	if (a == eventos->head) {
		eventos->head = b;
	}
	else if (b == eventos->head) {
		eventos->head = a;
	}
	if (a == eventos->tail) {
		eventos->tail = b;
	}
	else if (b == eventos->head) {
		eventos->tail = a;
	}
	Evento *aux = b->sig;
	a->sig = b->sig;
	aux = a->ant;
	b->ant = a->ant;
	a->ant = b;
	b->sig = a;
}

String^ Usuario::MostrarTareasDía(DateTime^ day) {
	Evento *i = eventos->head;
	String^ tareas = "";
	while (i != nullptr) {
		if (i->año == day->Year && i->mes == day->Month && i->día == day->Day) {
			tareas += i->ToString();
		}
		i = i->sig;
	}
	return tareas;
}