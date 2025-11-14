#include "Arma.h"
#include "Pokemon.h"

Arma::Arma(int danno, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre):Objeto(cogido, numUsos, vivo, x, y, tipo, nombre)
{
}

Arma::~Arma()
{
}

void Arma::utilizar(Pokemon* pokemon)
{
	pokemon->restarVida(danno);
	numUsos--;
	if (numUsos <= 0)
	{
		vivo = false;
	}
}


