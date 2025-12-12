#pragma once

#include "Pokemon.h"
#include "Mapa.h"
#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <functional>
#include <memory>  

class Partida
{

public:

	Mapa* mapa;
	Partida();
	std::vector<Pokemon*> crearPokemons(int cantidad);
	std::vector<Pokemon*> batalla(std::vector<Pokemon*>& lista, Pokemon* actual, Pokemon* rival);
	Pokemon* crearPokemonAleatorio();
	std::list<Objeto*>* equipInicio();

	Objeto* ComprobarObjetoEnCasilla(int x, int y);
	Pokemon* ComprobarPokemonEnCasilla(int x, int y);

	void reducirZonaAzul(int x, int y);
	void usarObjetos(Pokemon* pokemonDuelo);

private:

	int jugadores = 100;
};

void liberarRecursos();

