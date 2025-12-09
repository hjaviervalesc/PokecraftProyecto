#include "Partida.h"
#include "Pokemon.h"
#include "Objeto.h"

#include "PokemonFuego.h"
#include "PokemonAgua.h"
#include "PokemonPlanta.h"
#include "PokemonElectrico.h"

#include "Arma.h"
#include "Armadura.h"
#include "Botiquin.h"

#include "ArmaDiamante.h"
#include "ArmaHierro.h"
#include "ArmaMadera.h"
#include "ArmaduraCuero.h"
#include "ArmaduraHierro.h"
#include "ArmaduraDiamante.h"

#include <iostream>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <functional>
#include <memory>  

using namespace std;

std::vector<std::string> nombresFuego = {
    "Charmander","Charmeleon","Charizard","Vulpix","Ninetales","Growlithe","Arcanine","Ponyta","Rapidash","Magmar","Flareon","Moltres","Cyndaquil","Quilava","Typhlosion","Torchic","Combusken","Blaziken","Chimchar","Monferno","Infernape","Tepig","Pignite","Emboar","Fennekin","Braixen","Delphox","Litten","Torracat",
    "Incineroar","Scorbunny","Raboot","Cinderace"
};

std::vector<std::string> nombresAgua = {
    "Squirtle","Wartortle","Blastoise","Psyduck","Golduck","Poliwag","Poliwhirl","Poliwrath","Tentacool","Tentacruel","Seel","Dewgong","Shellder","Cloyster","Krabby","Kingler","Horsea","Seadra","Goldeen","Seaking","Staryu","Starmie","Magikarp","Gyarados","Lapras","Vaporeon","Totodile","Croconaw",
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
    //¿Usamos mejor int?
    for (size_t i = 0; i < lista.size()-1; i = i+2)
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

        while (pokemonVeloz->getVida() > 0 && pokemonLento->getVida() > 0) 
        {

            pokemonVeloz->atacar(pokemonLento);

            if(pokemonLento->getVida() > 0)
            pokemonLento->atacar(pokemonVeloz);

        }

        size_t indexToDelete = SIZE_MAX;
        size_t ganador = SIZE_MAX;

        if (lista[i]->getVida() <= 0) 
        {
            indexToDelete = i;
            ganador = i+1;
        }

        if (lista[i+1]->getVida() <= 0)
        {
            indexToDelete = i+1;
            ganador = i;
        }

        cout << "ENTRE " << pokemonVeloz->getNombre() << " y " << pokemonLento->getNombre() << " ----> GANA " << lista[ganador]->getNombre() << endl;
        
        if (indexToDelete != -1) 
        {
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


Pokemon* Partida::crearPokemonAleatorio( ) {

    int vida = rand() % 300;

    int tipo = rand() % 4; 

    int damage = rand() % 30;
    int velocidad = rand() % 10;
    Pokemon* p;
    switch (tipo) {
    case 0:
        p = new PokemonFuego(0, 0, vida, equipInicio(), TiposPokemon::Fuego, 0, true, nombresFuego[rand() % nombresFuego.size()], vida, damage, velocidad);
        // ChatGPTeada para ver q funciona
        //std::cout << "Equipo de inicio de: ";
        //for (auto* obj : *(p->getObjetos())) {
        //    std::cout << obj->getNombre() << " ";
        //}
        //std::cout << std::endl;

        return p;
    case 1:
        p = new PokemonAgua(0, 0, vida, equipInicio(), TiposPokemon::Agua, 0, true, nombresAgua[rand() % nombresAgua.size()], vida, damage, velocidad);
        return p;
    case 2:
        p = new PokemonPlanta(0, 0, vida, equipInicio(), TiposPokemon::Planta, 0, true, nombresPlanta[rand() % nombresPlanta.size()], vida, damage, velocidad);
        return p;
    case 3:
        p = new PokemonElectrico(0, 0, vida, equipInicio(), TiposPokemon::Electrico, 0, true, nombresElectrico[rand() % nombresElectrico.size()], vida, damage, velocidad);
        return p;
    default:  
        return nullptr;
    }
}

//Tres tipos de clases bases a elegir. Se eligen random para automatizarlo
std::list<Objeto*>* Partida::equipInicio()
{
    std::list<Objeto*>* objetosIniciales = new std::list<Objeto*>();
    int tipo = rand() % 3;
    Objeto* o;
    switch (tipo)
    {
        // x e y = -1 porque pertenecen al personaje
    case 0:
        o = new ArmaMadera(TiposArma::Martillo, true, 1, true, -1, -1, Armas, "MartilloMadera");
        objetosIniciales->push_back(o);
        o = new ArmaduraCuero(TiposArmadura::Casco, true, 1, true, -1, -1, Armadura, "CascoCuero");
        objetosIniciales->push_back(o);
        return objetosIniciales;

    case 1:
        o = new ArmaHierro(TiposArma::Hacha, true, 1, true, -1, -1, Armas, "HachaHierro");
        objetosIniciales->push_back(o);
        return objetosIniciales;

    case 2:
        o = new ArmaduraHierro(TiposArmadura::Pechera, true, 1, true, -1, -1, Armadura, "PecheraHierro");
        objetosIniciales->push_back(o);
        return objetosIniciales;

    default:
        break;
    }
}


//CHATGPTeada para sustituir un switch, ns como quereis hacerlo
std::vector<std::unique_ptr<Objeto>> Partida::objetosMapa()
{
    std::vector<std::unique_ptr<Objeto>> objetos;

    std::vector<std::function<std::unique_ptr<Objeto>()>> fabricas = {
    []() { return std::make_unique<ArmaduraCuero>(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoCuero"); }, 
    []() { return std::make_unique<ArmaduraHierro>(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoHierro"); },
    []() { return std::make_unique<ArmaduraDiamante>(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoDiamante"); },
    []() { return std::make_unique<ArmaduraCuero>(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, " MallasCuero"); },
    []() { return std::make_unique<ArmaduraHierro>(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasHierro"); },
    []() { return std::make_unique<ArmaduraDiamante>(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasDiamante"); },
    []() { return std::make_unique<ArmaduraCuero>(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraCuero"); },
    []() { return std::make_unique<ArmaduraHierro>(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraHierro"); },
    []() { return std::make_unique<ArmaduraDiamante>(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraDiamante"); },
    []() { return std::make_unique<ArmaMadera>(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloMadera");  },
    []() { return std::make_unique<ArmaHierro>(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloHierro");  },
    []() { return std::make_unique<ArmaDiamante>(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloDiamante");  },
    []() { return std::make_unique<ArmaMadera>(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloMadera");  },
    []() { return std::make_unique<ArmaHierro>(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloHierro");  },
    []() { return std::make_unique<ArmaDiamante>(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloDiamante");  },
    []() { return std::make_unique<ArmaMadera>(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaMadera");  },
    []() { return std::make_unique<ArmaHierro>(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaHierro");  },
    []() { return std::make_unique<ArmaDiamante>(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaDiamante");  },
    []() { return std::make_unique<Botiquin>(BotiquinObjeto, false, 1, true, rand() % 200, rand() % 200, BotiquinObjeto, "Botiquin"); },
    };

    int r = rand() % fabricas.size();
    objetos.push_back(fabricas[r]());  // añade un objeto aleatorio

    return objetos;
}

//void recoleccionObjetos(std::vector<std::unique_ptr<Objeto>> objetos, std::list<Objeto*>* objetosJugador)
//{
//    for(int i = 0; objetos[i] ; )
//}