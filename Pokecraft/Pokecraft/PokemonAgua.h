#pragma once
#include "Pokemon.h"
class PokemonAgua : public Pokemon
{
public:
	PokemonAgua(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno, int velocidad);
	~PokemonAgua();
	virtual int calcularDanno(TiposPokemon tipoPokemon);
};

