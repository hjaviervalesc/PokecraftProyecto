#include <iostream>

#include "Partida.h"
#include "Pokemon.h"
#include "PokemonAgua.h"
#include "PokemonElectrico.h"
#include "PokemonFuego.h"
#include "PokemonPlanta.h"
#include "Objeto.h"

#include <vector>

using namespace std;


int main()
{
	//Para MEMORY LEAKS
	 _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 
	 
	Partida partida; 

	int numJugadores;
	int tamannoMapa;
	int numeroNPCs;

	cout << "Introduce el tamanno del mapa: (MAX 10)" << endl;
	cin >> tamannoMapa;

	Mapa* mapa = new Mapa(tamannoMapa, 5);
	partida.mapa = mapa;

	cout << "Introduce el numero de jugadores reales: " << endl;
	cin >> numJugadores ;

	cout << "Introduce el numero de NPCs: " << endl;
	cin >> numeroNPCs;

	if (numeroNPCs > 100)
	{
		cout << "Excedido numero de jugadores maximo" << endl;

		delete mapa;
		partida.mapa = nullptr;
		liberarRecursos();
		return 0;
	}

	int pokemonsTotales = numJugadores + numeroNPCs;

	vector<Pokemon*> Pokemons = partida.crearPokemons(pokemonsTotales);

	cout << "=== POKEMONS CREADOS ===" << endl;
	cout << "Total de Pokemons: " << Pokemon::getContadorPokemon() << endl;
	cout << "Pokemons de Agua: " << PokemonAgua::getContadorAgua() << endl;
	cout << "Pokemons Electricos: " << PokemonElectrico::getContadorElectrico() << endl;
	cout << "Pokemons de Fuego: " << PokemonFuego::getContadorFuego() << endl;
	cout << "Pokemons de Planta: " << PokemonPlanta::getContadorPlanta() << endl;
	cout << endl;

	int indexBatalla = 1;
	int tamannoZonaAzul = -4;

	for (int i = 0; i < numJugadores; i++) {
		Pokemons[i]->setControlado(true);

		cout << "JUGADOR NUMERO " << (i + 1) << " TU POKEMON ES " << Pokemons[i]->getNombre() << endl;
	}

	while (Pokemons.size() >1) {

		cout << "RONDA " << indexBatalla << endl;
		cout << endl;

		for (int i = 0; i < Pokemons.size(); i++)
		{
			Pokemon* pokemonActual = Pokemons[i];

			if (!pokemonActual->getVivo()) continue;


			partida.mapa->MatrizCasillas[pokemonActual->getX()][pokemonActual->getY()]->pokemon = nullptr;

			int xDirection = 0;
			int yDirection = 0;

			if (pokemonActual->getControlado()) 
			{

				do {
					cout << "JUGADOR, ELIGE EL MOVIMIENTO DE " << pokemonActual->getNombre() << endl;
					cout << " ESCRIBE -1 PARA IZQUIERDA, 0 PARA NO MOVERTE EN X O 1 PARA DERECHA" << endl;
					cin >> xDirection;
					cout << " ESCRIBE -1 PARA ARRIBA, 0 PARA NO MOVERTE EN Y O 1 PARA ABAJO" << endl;
					cin >> yDirection;
				} while ((xDirection < -1 || xDirection > 1) && (yDirection < -1 || yDirection > 1));

			}
			else {
				xDirection = (rand() % 3) - 1;
				yDirection = (rand() % 3) - 1;
			}


			pokemonActual->moverse(xDirection, yDirection);

			if (pokemonActual->getX() < 0) { pokemonActual->setX(0); }
			if (pokemonActual->getX() > mapa->MatrizCasillas.size()-1) { pokemonActual->setX((int)mapa->MatrizCasillas.size() - 1); }
			if (pokemonActual->getY() < 0) { pokemonActual->setY(0); }
			if (pokemonActual->getY() > mapa->MatrizCasillas.size() - 1) { pokemonActual->setY((int)mapa->MatrizCasillas.size() - 1); }

			cout << pokemonActual->getNombre() << " ESTA EN X:" << pokemonActual->getX() << " Y :" << pokemonActual->getY() << endl;

			Pokemon* rival = partida.ComprobarPokemonEnCasilla(pokemonActual->getX(), pokemonActual->getY());
			Objeto* loot = partida.ComprobarObjetoEnCasilla(pokemonActual->getX(), pokemonActual->getY());

			if (rival && rival->getNombre() != pokemonActual->getNombre()) {
				partida.batalla(Pokemons, pokemonActual, rival);

				if (!pokemonActual->getVivo()) partida.mapa->MatrizCasillas[pokemonActual->getX()][pokemonActual->getY()]->pokemon = rival;
				if (!rival->getVivo()) partida.mapa->MatrizCasillas[rival->getX()][rival->getY()]->pokemon = pokemonActual;
			}
			else {

				partida.mapa->MatrizCasillas[pokemonActual->getX()][pokemonActual->getY()]->pokemon = pokemonActual;
			}

			if (loot) {
				cout << pokemonActual->getNombre() << " ENCUENTRA " << loot->getNombre() << endl;
				pokemonActual->annadirObjeto(loot);
				mapa->MatrizCasillas[pokemonActual->getX()][pokemonActual->getY()]->objeto = nullptr;
			}

		}

		tamannoZonaAzul++;

		if(tamannoZonaAzul >0)
		partida.reducirZonaAzul(tamannoZonaAzul, tamannoZonaAzul);


		Pokemons.erase(
			std::remove_if(
				Pokemons.begin(),
				Pokemons.end(),
				[](Pokemon* p) {
					if (!p->getVivo()) {
						delete p;   // liberar memoria
						p = nullptr;
						return true; // eliminar del vector
					}
					return false;
				}
			),
			Pokemons.end()
		);

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
	cout << " ------------------------------- RECOGE TU PREMIO -------------------------------" << endl;
	cout << endl;

	cout << R"(
  .     '     ,
    _________
 _ /_|_____|_\ _
   '. \   / .'
     '.\ /.'
       '.'
)" << endl;

	for (Pokemon* p : Pokemons) {
		delete p;
	}

	Pokemons.clear();

	// Liberar mapa y recursos asociados
	delete mapa;
	partida.mapa = nullptr;

    // Liberar vectores estáticos y otros recursos globales utilizados por Partida
    liberarRecursos();

}