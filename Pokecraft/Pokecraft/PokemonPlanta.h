#pragma once
#include "Pokemon.h"
class PokemonPlanta :public Pokemon
{
public:
	PokemonPlanta(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno, int velocidad);
	~PokemonPlanta();
	virtual int calcularDanno(TiposPokemon tipoPokemon);
};

