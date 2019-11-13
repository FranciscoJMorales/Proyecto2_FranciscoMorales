#include "Usuario.h"



Usuario::Usuario(String^ name)
{
	nombre = name;
}


String^ Usuario::Exportar() {
	return "";
}

void Usuario::Importar(String^ archivo) {

}

Evento *Usuario::Buscar(int caso) {
	return nullptr;
}