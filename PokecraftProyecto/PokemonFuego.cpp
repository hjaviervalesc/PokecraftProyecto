#include "PokemonFuego.h"
#include "Objeto.h"

PokemonFuego::PokemonFuego(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo,std::string nombre, int vidaMax, int danno): Pokemon(x, y, vida, objetos, tipo, armadura, vivo,nombre, vidaMax, danno)
{
}

PokemonFuego::~PokemonFuego()
{
}

int PokemonFuego::calcularDanno(TiposPokemon tipoPokemon)
{
	int danno = this->danno;
	switch (tipoPokemon)
	{
	case Fuego:
		break;
	case Agua:
		danno /= 2;
		break;
	case Planta:
		danno *= 2;		
		break;
	case Electrico:
		break;
	default:
		break;
	}

	return danno;
}
