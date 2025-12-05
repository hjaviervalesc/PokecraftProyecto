#include "PokemonAgua.h"
#include "Objeto.h"

int PokemonAgua::contadorAgua = 0;

PokemonAgua::PokemonAgua(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno, int velocidad) : Pokemon(x, y, vida, objetos, tipo, armadura, vivo, nombre, vidaMax, danno, velocidad)
{
	contadorAgua++;						
}

PokemonAgua::~PokemonAgua()
{
	contadorAgua--;
}

int PokemonAgua::calcularDanno(TiposPokemon tipoPokemon)
{
	int danno = this->danno;
	switch (tipoPokemon)
	{
	case Fuego:
		danno *= 2;
		break;
	case Agua:
		break;
	case Planta:
		danno /= 2;
		break;
	case Electrico:
		break;
	default:
		break;
	}

	return danno;
}

int PokemonAgua::getContadorAgua()
{
	return contadorAgua;
}
