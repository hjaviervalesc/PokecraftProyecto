#pragma once
#include "Pokemon.h"
class PokemonElectrico :public Pokemon
{
public:
	PokemonElectrico(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno, int velocidad);
	~PokemonElectrico();
	virtual int calcularDanno(TiposPokemon tipoPokemon);
};

