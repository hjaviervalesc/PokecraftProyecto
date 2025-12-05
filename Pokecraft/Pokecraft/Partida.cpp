#include "Partida.h"
#include "Pokemon.h"

#include "PokemonFuego.h"
#include "PokemonAgua.h"
#include "PokemonPlanta.h"
#include "PokemonElectrico.h"

#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

using namespace std;

std::vector<std::string> nombresFuego = {
    "Charmander","Charmeleon","Charizard","Vulpix","Ninetales","Growlithe","Arcanine","Ponyta","Rapidash","Magmar","Flareon","Moltres","Cyndaquil","Quilava","Typhlosion","Torchic","Combusken","Blaziken","Chimchar","Monferno","Infernape","Tepig","Pignite","Emboar","Fennekin","Braixen","Delphox","Litten","Torracat",
    "Incineroar","Scorbunny","Raboot","Cinderace"
};

std::vector<std::string> nombresAgua = {"Squirtle","Wartortle","Blastoise","Psyduck","Golduck","Poliwag","Poliwhirl","Poliwrath","Tentacool","Tentacruel","Seel","Dewgong","Shellder","Cloyster","Krabby","Kingler","Horsea","Seadra","Goldeen","Seaking","Staryu","Starmie","Magikarp","Gyarados","Lapras","Vaporeon","Totodile","Croconaw",
    "Feraligatr","Mudkip","Marshtomp","Swampert","Piplup","Prinplup","Empoleon","Oshawott","Dewott","Samurott","Sobble","Drizzile","Inteleon"
};

std::vector<std::string> nombresPlanta = {
    "Bulbasaur", "Ivysaur", "Venusaur", "Oddish", "Gloom", "Vileplume","Bellsprout", "Weepinbell", "Victreebel", "Exeggcute", "Exeggutor", "Tangela","Chikorita", "Bayleef", "Meganium", "Hoppip", "Skiploom", "Jumpluff","Sunkern", "Sunflora", "Treecko", "Grovyle", "Sceptile", "Turtwig","Grotle", "Torterra", "Snivy", "Servine", "Serperior", 
    "Chespin", "Quilladin", "Chesnaught", "Rowlet", "Dartrix", "Decidueye"
};

std::vector<std::string> nombresElectrico = {
    "Pikachu", "Raichu", "Magnemite", "Magneton", "Voltorb", "Electrode","Electabuzz", "Jolteon", "Zapdos", "Mareep", "Flaaffy", "Ampharos","Plusle", "Minun", "Shinx", "Luxio", "Luxray", "Pachirisu","Emolga", "Tynamo", "Eelektrik", "Eelektross", "Joltik", "Galvantula","Helioptile", "Heliolisk", "Togedemaru", "Zeraora", "Morpeko",
    "Pikachu Gigantamax"
};

vector<Pokemon*> Partida::crearPokemons(int cantidad) {

    srand(static_cast<unsigned int>(time(nullptr)));
    vector<Pokemon*> pokemons;
    pokemons.reserve(cantidad);

    for (int i = 0; i < cantidad; i++) {
       pokemons.push_back(crearPokemonAleatorio());
    }

    return pokemons;
}

vector<Pokemon*> Partida::batalla(vector<Pokemon*> &lista) {

    for (size_t i = 0; i < lista.size()-1; i= i+2)
    {
        Pokemon* pokemonVeloz;
        Pokemon* pokemonLento;

        if (lista[i]->getVelocidad() > lista[i+1]->getVelocidad()) 
        {
            pokemonVeloz = lista[i];
            pokemonLento = lista[i+1];
        }
        else 
        {
            pokemonVeloz = lista[i+1];
            pokemonLento = lista[i];
        }

        while (pokemonVeloz->getVida() > 0 && pokemonLento->getVida() > 0) {

            pokemonVeloz->atacar(pokemonLento);

            if(pokemonLento->getVida() > 0)
            pokemonLento->atacar(pokemonVeloz);

        }

        size_t indexToDelete = SIZE_MAX;
        size_t ganador = SIZE_MAX;

        if (lista[i]->getVida() <= 0) {
            indexToDelete = i;
            ganador = i+1;
        }

        if (lista[i+1]->getVida() <= 0) {
            indexToDelete = i+1;
            ganador = i;
        }

        cout << "ENTRE " << pokemonVeloz->getNombre() << " y " << pokemonLento->getNombre() << " ----> GANA " << lista[ganador]->getNombre() << endl;
        
        if (indexToDelete != -1) {
            delete lista[indexToDelete];
            lista[indexToDelete] = nullptr;
        }
    }

    lista.erase(
        std::remove(lista.begin(), lista.end(), nullptr),
        lista.end()
    );

    return lista;

}

Pokemon* Partida::crearPokemonAleatorio() {

    int vida = rand() % 300;

    std::list<Objeto*>* objetos = nullptr;

    int tipo = rand() % 4; 

    int damage = rand() % 30;
    int velocidad = rand() % 10;

    switch (tipo) {
        Pokemon* p;

    case 0:
        p = new PokemonFuego(0, 0, vida, objetos, TiposPokemon::Fuego, 0, true, nombresFuego[rand() % nombresFuego.size()], vida, damage, velocidad);
        return p;

        break;
    case 1:
        p = new PokemonAgua(0, 0, vida, objetos, TiposPokemon::Agua, 0, true, nombresAgua[rand() % nombresAgua.size()], vida, damage, velocidad);

        return p;
        break;
    case 2:
        p = new PokemonPlanta(0, 0, vida, objetos, TiposPokemon::Planta, 0, true, nombresPlanta[rand() % nombresPlanta.size()], vida, damage, velocidad);

        return p;
        break;
    case 3:
        p = new PokemonElectrico(0, 0, vida, objetos, TiposPokemon::Electrico, 0, true, nombresElectrico[rand() % nombresElectrico.size()], vida, damage, velocidad);

        return p;
        break;
    default:  return nullptr;
    }
    
}