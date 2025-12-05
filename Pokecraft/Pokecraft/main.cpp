#include <iostream>

#include "Partida.h"
#include "Pokemon.h"
#include "PokemonAgua.h"
#include "PokemonElectrico.h"
#include "PokemonFuego.h"
#include "PokemonPlanta.h"

#include <vector>

using namespace std;


int main()
{
	//Para MEMORY LEAKS
	 _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 
	 
	Partida partida;


	vector<Pokemon*> Pokemons = partida.crearPokemons(100);

	cout << "=== POKEMONS CREADOS ===" << endl;
	cout << "Total de Pokemons: " << Pokemon::getContadorPokemon() << endl;
	cout << "Pokemons de Agua: " << PokemonAgua::getContadorAgua() << endl;
	cout << "Pokemons Electricos: " << PokemonElectrico::getContadorElectrico() << endl;
	cout << "Pokemons de Fuego: " << PokemonFuego::getContadorFuego() << endl;
	cout << "Pokemons de Planta: " << PokemonPlanta::getContadorPlanta() << endl;
	cout << endl;

	int indexBatalla = 1;

	while (Pokemons.size() >1) {

		cout << "RONDA " << indexBatalla << endl;
		cout << endl;

		Pokemons = partida.batalla(Pokemons);

		cout << endl;
		cout << "QUEDAN " << Pokemons.size() << " POKEMONS " << endl;
		cout << "Agua: " << PokemonAgua::getContadorAgua() 
		     << " | Electricos: " << PokemonElectrico::getContadorElectrico()
		     << " | Fuego: " << PokemonFuego::getContadorFuego()
		     << " | Planta: " << PokemonPlanta::getContadorPlanta()
		     << " | Total: " << Pokemon::getContadorPokemon() << endl;
		cout << endl;

		indexBatalla++;

	}

	cout << endl;
	cout << " ------------------------------- EL GANADOR ES " << Pokemons[0]->getNombre() << " -------------------------------" << endl;
	cout << endl;

	for (Pokemon* p : Pokemons) {
		delete p;
	}

	Pokemons.clear();

}