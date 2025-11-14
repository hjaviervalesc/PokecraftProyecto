#pragma once
#include "Pokemon.h"
class PokemonFuego : public Pokemon
{
public:
	PokemonFuego(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno);
	~PokemonFuego();
	virtual int calcularDanno(TiposPokemon tipoPokemon);
};

