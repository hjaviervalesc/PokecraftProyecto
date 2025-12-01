#include "Botiquin.h"
#include "Pokemon.h"

Botiquin::Botiquin(int regeneracion, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre): Objeto(cogido, numUsos, vivo, x, y, tipo, nombre)
{
}

Botiquin::~Botiquin()
{
}

void Botiquin::utilizar(Pokemon* pokemon)
{
	pokemon->annadirVida(this->regeneracion);
	numUsos--;
	if (numUsos <= 0)
	{
		vivo = false;
	}
}
