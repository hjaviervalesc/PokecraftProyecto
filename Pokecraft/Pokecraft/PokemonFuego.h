#pragma once
#include "Pokemon.h"
class PokemonFuego : public Pokemon
{
private:
	static int contadorFuego;
public:

	PokemonFuego(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno, int velocidad);
	~PokemonFuego();
	virtual int calcularDanno(TiposPokemon tipoPokemon);
	static int getContadorFuego();
};

