#include "Arma.h"
#include "Pokemon.h"

Arma::Arma(int danno, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre):Objeto(cogido, numUsos, vivo, x, y, tipo, nombre)
{
}

Arma::~Arma()
{
}

int Arma::getDanno()
{
	return this->danno;
}

void Arma::setDanno(int danno)
{
	this->danno = danno;
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

