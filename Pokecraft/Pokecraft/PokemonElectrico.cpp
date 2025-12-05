#include "PokemonElectrico.h"
#include "Objeto.h"

int PokemonElectrico::contadorElectrico = 0;

PokemonElectrico::PokemonElectrico(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno, int velocidad) : Pokemon(x, y, vida, objetos, tipo, armadura, vivo, nombre, vidaMax, danno, velocidad)
{
	contadorElectrico++;																																						///int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno
}

PokemonElectrico::~PokemonElectrico()
{
	contadorElectrico--;
}

int PokemonElectrico::calcularDanno(TiposPokemon tipoPokemon)
{
	return (int)(danno * 1.1f);
}

int PokemonElectrico::getContadorElectrico()
{
	return contadorElectrico;
}
