#include "PokemonElectrico.h"
#include "Objeto.h"

PokemonElectrico::PokemonElectrico(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo,std::string nombre, int vidaMax, int danno) : Pokemon(x, y, vida, objetos, tipo, armadura, vivo, nombre, vidaMax, danno)
{																																						///int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno
}

PokemonElectrico::~PokemonElectrico()
{
}

int PokemonElectrico::calcularDanno(TiposPokemon tipoPokemon)
{
	return danno * 1.1f;
}
