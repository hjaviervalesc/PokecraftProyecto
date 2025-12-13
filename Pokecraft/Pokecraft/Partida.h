#pragma once


#include <iostream>
#include <vector>
#include <list>
class Pokemon;
class Mapa;
class Objeto;
class Partida
{
public:

    Partida();
    ~Partida();
    // Métodos principales
    std::vector<Pokemon*> crearPokemons(int cantidad);
    std::vector<Pokemon*> batalla(std::vector<Pokemon*>& lista, Pokemon* actual, Pokemon* rival);
    Pokemon* crearPokemonAleatorio();
    std::list<Objeto*>* equipInicio();

    Objeto* comprobarObjetoEnCasilla(int x, int y);
    Pokemon* comprobarPokemonEnCasilla(int x, int y);

    void reducirZonaAzul(int x, int y);
    void usarObjetos(Pokemon* pokemonDuelo);

    // Getter y Setter para mapa
    Mapa* getMapa() const { return mapa; }
    void setMapa(Mapa* nuevoMapa) { mapa = nuevoMapa; }

private:

    Mapa* mapa;
    
};

void liberarRecursos();
