#include "Usuario.h"


//Constructor que asigna los datos del usuario, así como sus eventos si ya los tenía
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

//Agrega un nuevo evento al final de la lista y lo escribe en el archivo .txt
void Usuario::Agregar(Evento *nuevo) {
	nuevo->id = ObtenerNuevoId();
	eventos->Agregar(nuevo);
	StreamWriter^ escritor = gcnew StreamWriter("..//" + nombre + ".txt", true);
	escritor->Write(nuevo->ToString());
	escritor->Close();
}

//Devuelve la información del archivo .txt del usuario
String^ Usuario::Exportar() {
	String^ info = nombre + "," + contraseña + "\r\n";
	info += eventos->String();
	return info;
}

//Ordena los eventos según el parámetro indicado
void Usuario::Ordenar(int caso) {
	Evento *i = eventos->head;
	bool intercambio = true;
	do {
		intercambio = false;
		i = eventos->head;
		while (i->sig != nullptr) {
			if (Comparar(i, i->sig, caso) > 0) {
				Intercambiar(i, i->sig);
				intercambio = true;
			}
			else {
				i = i->sig;
			}
		}
	} while (intercambio);
	StreamWriter^ escritor = gcnew StreamWriter("..//" + nombre + ".txt", false);
	escritor->Write(Exportar());
	escritor->Close();
}

//Busca un evento dependiendo del parámetro y del valor por buscar
String^ Usuario::Buscar(int caso, String^ valorBuscar) {
	Evento *i = eventos->head;
	Evento *valor = new Recordatorio();
	DateTime^ fecha;
	switch (caso) {
	case 0:
		valor->id = Convert::ToInt32(valorBuscar);
		break;
	case 1:
		fecha = Convert::ToDateTime(valorBuscar);
		valor->año = fecha->Year;
		valor->mes = fecha->Month;
		valor->día = fecha->Day;
		caso = 3;
		break;
	case 2:
		valor->prioridad = Convert::ToInt32(valorBuscar);
		break;
	}
	String^ resultado = "";
	while (i != nullptr) {
		if (Comparar(i, valor, caso) == 0) {
			resultado += i->ToString();
		}
		i = i->sig;
	}
	return resultado;
}

//Compara dos eventos y devuelve un entero indicando la relación entre estos en el parámetro indicado
int Usuario::Comparar(Evento *a, Evento *b, int caso) {
	switch (caso) {
		//Identificador
	case 0:
		if (a->id > b->id) {
			return 1;
		}
		else if (a->id == b->id) {
			return 0;
		}
		else {
			return -1;
		}
		break;
		//Fecha (incluyendo horas y minutos)
	case 1:
		if (a->FechaInicio()->CompareTo(b->FechaInicio()) == 0) {
			if (a->horaInicio > b->horaInicio || (a->horaInicio == b->horaInicio && a->minutosInicio > b->minutosInicio)) {
				return 1;
			}
			else if (a->horaInicio > b->horaInicio && a->minutosInicio == b->minutosInicio) {
				return 0;
			}
			else {
				return -1;
			}
		}
		else {
			return a->FechaInicio()->CompareTo(b->FechaInicio());
		}
		break;
		//Ordenar por prioridad
	case 2:
		if (a->prioridad < b->prioridad) {
			return 1;
		}
		else if (a->prioridad == b->prioridad) {
			return 0;
		}
		else {
			return -1;
		}
		break;
	case 3:
		return a->FechaInicio()->CompareTo(b->FechaInicio());
		break;
	}
}

//Intercambia la posición de los dos eventos especificados. Utilizado al ordenar los eventos
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
	a->sig = b->sig;
	if (a->sig != nullptr) {
		a->sig->ant = a;
	}
	b->ant = a->ant;
	if (b->ant != nullptr) {
		b->ant->sig = b;
	}
	a->ant = b;
	b->sig = a;
}

//Devuelve un string con todas las tareas pendientes del día indicado
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

//Genera un nuevo identificador, el cual se utiliza al agregar un evento nuevo
int Usuario::ObtenerNuevoId() {
	int ID = 0;
	Evento* i = eventos->head;
	if (i == nullptr) {
		return 0;
	}
	while (i != nullptr) {
		if (i->id >= ID) {
			ID = i->id + 1;
		}
		i = i->sig;
	}
	return ID;
}

//Revisa el listado de eventos para saber si ya es hora de mostrar alguno de estos
void Usuario::RevisarEventos(DateTime^ hora) {
	Evento *i = eventos->head;
	while (i != nullptr) {
		if (i->año == hora->Year && i->mes == hora->Month && i->día == hora->Day && i->horaInicio == hora->Hour && i->minutosInicio == hora->Minute) {
			if(i->Mostrar()) {
				System::DateTime^ fecha = gcnew System::DateTime(i->año, i->mes, i->día, i->horaInicio, i->minutosInicio, 0);
				fecha = fecha->AddMinutes(5);
				i->año = fecha->Year;
				i->mes = fecha->Month;
				i->día = fecha->Day;
				i->horaInicio = fecha->Hour;
				i->minutosInicio = fecha->Minute;
			}
		}
		i = i->sig;
	}
}