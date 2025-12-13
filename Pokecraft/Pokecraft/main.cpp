#include <iostream>
#include <vector>
#include <random>
#include <algorithm> 


#include "Partida.h"
#include "Pokemon.h"
#include "Mapa.h"
#include "PokemonAgua.h"
#include "PokemonElectrico.h"
#include "PokemonFuego.h"
#include "PokemonPlanta.h"
#include "Casilla.h"
#include "Objeto.h"

// Configuración de Memory Leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

using namespace std;


void mostrarBienvenida();
void mostrarGanador(Pokemon* ganador);
void mostrarEstadisticas();
void gestionarMovimiento(Pokemon* p, int& dx, int& dy); // Pide input o genera random
void corregirLimitesMapa(Pokemon* p, int tamannoMapa);
void limpiarPokemonsMuertos(vector<Pokemon*>& pokemons);


int main()
{
    // Configuración inicial
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    srand(static_cast<unsigned int>(time(nullptr)));

    mostrarBienvenida();

   
    Partida* partida = new Partida();
    int numJugadores, tamannoMapa, numeroNPCs;

    cout << "Introduce el tamanno del mapa: (MAX 10)" << endl;
    cin >> tamannoMapa;

   
    Mapa* mapa = new Mapa(tamannoMapa, 5);
    partida->setMapa(mapa);

    cout << "Introduce el numero de jugadores reales: " << endl;
    cin >> numJugadores;

    cout << "Introduce el numero de NPCs: " << endl;
    cin >> numeroNPCs;

    
    if ((numeroNPCs + numJugadores) > 100) {
        cout << "Error: Excedido numero de jugadores maximo" << endl;
        delete partida;
        liberarRecursos();
        return 0;
    }


    int pokemonsTotales = numJugadores + numeroNPCs;
    vector<Pokemon*> Pokemons = partida->crearPokemons(pokemonsTotales);

   
    cout << "\n=== ASIGNACION DE POKEMONS ===" << endl;
    mostrarEstadisticas();

    for (int i = 0; i < numJugadores; i++) {
        Pokemons[i]->setControlado(true);
        cout << "JUGADOR " << (i + 1) << " -> TU POKEMON ES: \x1b[32m" << Pokemons[i]->getNombre() << "\x1b[0m" << endl;
    }

    
    int indexBatalla = 1;
    int tamannoZonaAzul = -4; 

    while (Pokemons.size() > 1) {

        cout << "\x1b[33m\n>>> RONDA " << indexBatalla << " <<<\x1b[0m" << endl;

        
        for (int i = 0; i < Pokemons.size(); i++)
        {
            Pokemon* actual = Pokemons[i];
            if (!actual->getVivo()) continue;

           
            partida->getMapa()->MatrizCasillas[actual->getX()][actual->getY()]->setPokemon(nullptr);

           
            int dx = 0, dy = 0;
            gestionarMovimiento(actual, dx, dy);

           
            actual->moverse(dx, dy);
            corregirLimitesMapa(actual, (int)mapa->MatrizCasillas.size());

            
            Pokemon* rival = partida->comprobarPokemonEnCasilla(actual->getX(), actual->getY());
            Objeto* loot = partida->comprobarObjetoEnCasilla(actual->getX(), actual->getY());

            if (rival && rival->getNombre() != actual->getNombre()) {
                
                partida->batalla(Pokemons, actual, rival);

                
                if (actual->getVivo())
                    partida->getMapa()->MatrizCasillas[actual->getX()][actual->getY()]->setPokemon(actual);
                else if (rival->getVivo())
                    partida->getMapa()->MatrizCasillas[rival->getX()][rival->getY()]->setPokemon(rival);
            }
            else {
              
                partida->getMapa()->MatrizCasillas[actual->getX()][actual->getY()]->setPokemon(actual);
            }

       
            if (loot) {
                cout << "\x1b[32m   [!] " << actual->getNombre() << " ENCUENTRA " << loot->getNombre() << "\x1b[0m" << endl;
                actual->annadirObjeto(loot);
                mapa->MatrizCasillas[actual->getX()][actual->getY()]->setObjeto(nullptr);
            }
        }

      
        tamannoZonaAzul++;
        if (tamannoZonaAzul > 0) {
            partida->reducirZonaAzul(tamannoZonaAzul, tamannoZonaAzul);
        }

       
        limpiarPokemonsMuertos(Pokemons);

        if (Pokemons.size() > 1) {
            cout << "\n--- ESTADO DE LA PARTIDA ---" << endl;
            cout << "Pokemons vivos: " << Pokemons.size() << endl;
            mostrarEstadisticas();
        }

        indexBatalla++;
    }

   
    if (!Pokemons.empty()) {
        mostrarGanador(Pokemons[0]);
    }

   
    for (Pokemon* p : Pokemons) {
        delete p;
    }
    Pokemons.clear();

    
    delete partida;
    liberarRecursos();

    return 0;
}



void mostrarBienvenida() {
    cout << "\x1b[33m";
    cout << "***************************************" << endl;
    cout << "                                     " << endl;
    cout << "      \x1b[31mBIENVENIDO A\x1b[33m       " << endl;
    cout << "      \x1b[34mPOKECRAFT BATTLE ROYALE\x1b[33m  " << endl;
    cout << "                                     " << endl;
    cout << "***************************************\n" << endl;
    cout << "Las reglas son claras: \nEl usuario:\n -elige un tamanno del mapa\n -elige el numero de jugadores y NPCs (Suma ambos MAX 100)\n -comenzara la batalla y el usuario movera su pokemon en los diferentes turnos\n -el ganador recibira un premio\n" << endl;
    cout << "CREACION DE PARTIDA" << endl << endl;


    cout << "\x1b[0m";
}

void mostrarEstadisticas() {
    cout << "Total: " << Pokemon::getContadorPokemon()
        << " | Agua: " << PokemonAgua::getContadorAgua()
        << " | Elec: " << PokemonElectrico::getContadorElectrico()
        << " | Fuego: " << PokemonFuego::getContadorFuego()
        << " | Planta: " << PokemonPlanta::getContadorPlanta() << endl;
}

void gestionarMovimiento(Pokemon* p, int& dx, int& dy) {
    if (p->getControlado()) {
        do {
            cout << "JUGADOR, ELIGE EL MOVIMIENTO DE " << p->getNombre() << endl;
            cout << "Movimiento horizontal: -1 es IZQUIERDA, 0 es quieto, 1 es DERECHA" << endl;
            cin >> dx;
            cout << "Movimiento vertical: -1 es ARRIBA, 0 es quieto, 1 es ABAJO" << endl;
            cin >> dy;
        } while ((dx < -1 || dx > 1) || (dy < -1 || dy > 1));
    }
    else {
      
        dx = (rand() % 3) - 1;
        dy = (rand() % 3) - 1;
    }
}

void corregirLimitesMapa(Pokemon* p, int tamannoMapa) {
    int maxCoord = tamannoMapa - 1;
    if (p->getX() < 0) p->setX(0);
    if (p->getX() > maxCoord) p->setX(maxCoord);
    if (p->getY() < 0) p->setY(0);
    if (p->getY() > maxCoord) p->setY(maxCoord);
}

void limpiarPokemonsMuertos(vector<Pokemon*>& pokemons) {
    pokemons.erase(
        std::remove_if(
            pokemons.begin(),
            pokemons.end(),
            [](Pokemon* p) {
                if (!p->getVivo()) {
                    delete p;   // Liberamos la memoria aquí
                    return true; // Lo sacamos del vector
                }
                return false;
            }
        ),
        pokemons.end()
    );
}

void mostrarGanador(Pokemon* ganador) {
    cout << endl;
    cout << " ------------------------------- EL GANADOR ES " << ganador->getNombre() << " -------------------------------" << endl;
    cout << endl;
    cout << " ------------------------------- RECOGE TU PREMIO -------------------------------" << endl;
    cout << "\x1b[34m";
    cout << R"(
  .      '      ,
    _________
 _ /_|_____|_\ _
   '. \   / .'
     '.\ /.'
       '.'
)" << endl;
    cout << "\x1b[0m";
}