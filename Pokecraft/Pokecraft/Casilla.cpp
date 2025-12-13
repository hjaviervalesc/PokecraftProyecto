#include "Casilla.h"
#include "Objeto.h"
#include "Pokemon.h"
Casilla::~Casilla()
{
	// Primero comprobamos si objeto no es nulo
	if (objeto != nullptr && !objeto->getCogido()) {
		delete objeto;
	}
	pokemon = nullptr;
	objeto = nullptr;
}