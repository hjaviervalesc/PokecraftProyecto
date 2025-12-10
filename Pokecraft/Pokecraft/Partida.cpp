#include "Partida.h"
#include "Pokemon.h"
#include "Objeto.h"

#include "TiposObjeto.h"

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

    //Les daría a todos la misma vida
    int vida = 350;

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
std::vector<Objeto*> Partida::objetosMapa()
{
    std::vector<Objeto*> objetos;

    std::vector<std::function<Objeto* ()>> fabricas = {
        []() { return new ArmaduraCuero(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoCuero"); },
        []() { return new ArmaduraHierro(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoHierro"); },
        []() { return new ArmaduraDiamante(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoDiamante"); },
        []() { return new ArmaduraCuero(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasCuero"); },
        []() { return new ArmaduraHierro(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasHierro"); },
        []() { return new ArmaduraDiamante(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasDiamante"); },
        []() { return new ArmaduraCuero(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraCuero"); },
        []() { return new ArmaduraHierro(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraHierro"); },
        []() { return new ArmaduraDiamante(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraDiamante"); },
        []() { return new ArmaMadera(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloMadera"); },
        []() { return new ArmaHierro(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloHierro"); },
        []() { return new ArmaDiamante(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloDiamante"); },
        []() { return new ArmaMadera(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaMadera"); },
        []() { return new ArmaHierro(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaHierro"); },
        []() { return new ArmaDiamante(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaDiamante"); },
        []() { return new ArmaMadera(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaMadera"); },
        []() { return new ArmaHierro(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaHierro"); },
        []() { return new ArmaDiamante(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaDiamante"); },
        //Botiquin va a regenerar siempre 150
        []() { return new Botiquin(150, false, 1, true, rand() % 200, rand() % 200, BotiquinObjeto, "Botiquin"); },
    };

    int r = rand() % fabricas.size();
    objetos.push_back(fabricas[r]());  // añade un objeto aleatorio

    return objetos;
}

//Recibirá el vector con todos los objetos y el Pokemon al que le toque el turno.
void recolectarObjetos(std::vector<Objeto*>& objetos, Pokemon* pokemon)
{
    int i = 0;
    //Recorrer el vector con todos los objetos 
    while (i < objetos.size())
    {
        //Si coincide localización añade y borra
        if (objetos[i]->getX() == pokemon->getX() && objetos[i]->getY() == pokemon->getY())
        {
            //La lsta de objetos de pokemon no tiene limite, se pueden almacenar los que sean
            pokemon->annadirObjeto(objetos[i]);
            objetos.erase(objetos.begin() + i);
        }
        else
        {
            i++; 
        }
    }
}

void usarObjetos(Pokemon* pokemonDuelo)
{
    std::list<Objeto*>* objetosPokemon = pokemonDuelo->getObjetos();

    if ((*objetosPokemon).empty())
    {
        return;
    }
    //Objeto de los primeros 5 de la lista si tiene 5 sino entre el maximo posible
    int max = std::min((int)objetosPokemon->size(), 5);
    int i = rand() % max;  
    auto it = (*objetosPokemon).begin();
    std::advance(it, i);

    if ((*it)->getTipoObjeto() == Armas)
    {
        //utilizar aqui es para hacer daño no para sumarle el daño al pokemos que use el arma!!!!!!!!!!!!!!!!!!!!!!!!!!!
        (*it)->utilizar(pokemonDuelo);
    }
    else if ((*it)->getTipoObjeto() == Armadura)
    {
        //Arreglar en armadura.cpp numUsos porque como solo va a tener 1 siempre deberiamos de hacerlo estatico y en armas deberiamos de definir estaticamente en numUsos en el constructor!!!!!!!!!!!!!!!!!!!
        (*it)->utilizar(pokemonDuelo);
    }
    else if ((*it)->getTipoObjeto() == BotiquinObjeto)
    {
        (*it)->utilizar(pokemonDuelo);
    }
    
}

//SmartPointers????????????????
//Arreglar en armadura.cpp numUsos porque como solo va a tener 1 siempre deberiamos de hacerlo estatico y en armas deberiamos de definir estaticamente en numUsos en el constructor!!!!!!!!!!!!!!!!!!!
//utilizar aqui es para hacer daño no para sumarle el daño al pokemos que use el arma!!!!!!!!!!!!!!!!!!!!!!!!!!!!111
////CHATGPTeada para sustituir un switch, ns como quereis hacerlo