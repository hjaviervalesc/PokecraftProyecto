#pragma once
#include "Pokemon.h"
class PokemonPlanta :public Pokemon
{
	PokemonPlanta(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno);
	~PokemonPlanta();
	virtual int calcularDanno(TiposPokemon tipoPokemon);
};

