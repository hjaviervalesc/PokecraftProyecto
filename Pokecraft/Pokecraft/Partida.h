#pragma once

#include "Pokemon.h"
#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <functional>
#include <memory>  

class Partida
{

public:

	std::vector<Pokemon*> crearPokemons(int cantidad);
	std::vector<Pokemon*> batalla(std::vector<Pokemon*> &lista);
	Pokemon* crearPokemonAleatorio();
	std::list<Objeto*>* equipInicio();
	std::vector<std::unique_ptr<Objeto>> objetosMapa();

private:

	int jugadores = 100;
};

