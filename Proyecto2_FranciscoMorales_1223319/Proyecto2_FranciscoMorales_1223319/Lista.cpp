#include "Lista.h"



Lista::Lista()
{
	head = nullptr;
	tail = nullptr;
}


Lista::~Lista()
{
}

void Lista::Agregar(Evento *nuevo) {
	length++;
	tail = nuevo;
	if (head == nullptr) {
		head = nuevo;
	}
	else {
		AgregarRecursivo(nuevo, head);
	}
}

Evento *Lista::Eliminar(int posicion) {
	if (head != nullptr) {
		if (posicion == 0) {
			length--;
			if (head == tail) {
				tail = nullptr;
			}
			Evento *aux = head;
			head = head->sig;
			if (head != nullptr) {
				head->ant = nullptr;
			}
			aux->sig = nullptr;
			aux->ant = nullptr;
			return aux;
		}
		else if (posicion == length - 1) {
			length--;
			Evento *aux = tail;
			tail = tail->ant;
			tail->sig = nullptr;
			aux->sig = nullptr;
			aux->ant = nullptr;
			return aux;
		}
		else {
			return EliminarRecursivo(head, posicion);
		}
	}
	else {
		return nullptr;
	}
}

void Lista::AgregarRecursivo(Evento *nuevo, Evento *pos) {
	if (pos->sig != nullptr) {
		AgregarRecursivo(nuevo, pos->sig);
	}
	else {
		pos->sig = nuevo;
		nuevo->ant = pos;
	}
}

Evento *Lista::EliminarRecursivo(Evento *pos, int cantidad) {
	if (cantidad > 0) {
		if (pos->sig != nullptr) {
			return EliminarRecursivo(pos->sig, cantidad - 1);
		}
		else {
			return nullptr;
		}
	}
	else {
		if (pos->ant != nullptr) {
			pos->ant->sig = pos->sig;
		}
		if (pos->sig != nullptr) {
			pos->sig->ant = pos->ant;
		}
		pos->ant = nullptr;
		pos->sig = nullptr;
		length--;
		return pos;
	}
}