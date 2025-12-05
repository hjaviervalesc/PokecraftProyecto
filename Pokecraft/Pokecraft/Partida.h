#pragma once

#include "Pokemon.h"

#include <vector>

class Partida
{

public:

	std::vector<Pokemon*> crearPokemons(int cantidad);
	std::vector<Pokemon*> batalla(std::vector<Pokemon*> &lista);
	Pokemon* crearPokemonAleatorio();

private:

	int jugadores = 100;
};

