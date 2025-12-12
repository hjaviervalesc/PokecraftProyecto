#include "Casilla.h"


Casilla::~Casilla()
{
	// Solo liberamos el objeto si permanece en la casilla.
	// Los Pokemon son gestionados por el vector de Partida/main, por lo que
	if (objeto != nullptr) {
		delete objeto;
		objeto = nullptr;
	}
	pokemon = nullptr;
}