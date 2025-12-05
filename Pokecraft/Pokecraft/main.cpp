#include <iostream>

#include "Partida.h"
#include "Pokemon.h"

#include <vector>

using namespace std;


int main()
{
	//Creo la partida
	Partida partida;

	//Creo un numero de pokemons aleatorios
	vector<Pokemon*> Pokemons = partida.crearPokemons(100);

	//Gestión de Batallas
	int indexBatalla = 1;

	while (Pokemons.size() >1) {

		cout << "RONDA " << indexBatalla << endl;
		cout << endl;

		Pokemons = partida.batalla(Pokemons);

		cout << endl;
		cout << "QUEDAN " << Pokemons.size() << " POKEMONS " << endl;
		cout << endl;

		indexBatalla++;

	}

	cout << endl;
	cout << " ------------------------------- EL GANADOR ES " << Pokemons[0]->getNombre() << " -------------------------------" << endl;
	cout << endl;
}