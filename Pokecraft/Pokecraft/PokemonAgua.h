#pragma once
#include "Pokemon.h"
class PokemonAgua : public Pokemon
{
	PokemonAgua(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, std::string nombre, bool vivo, int vidaMax, int danno);
	~PokemonAgua();
	virtual int calcularDanno(TiposPokemon tipoPokemon);
};

