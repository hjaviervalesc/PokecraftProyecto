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

    //srand(static_cast<unsigned int>(time(nullptr)));
    vector<Pokemon*> pokemons;
    pokemons.reserve(cantidad);

    for (int i = 0; i < cantidad; i++) {
       pokemons.push_back(crearPokemonAleatorio());
    }

    return pokemons;
}

std::vector<Pokemon*> Partida::batalla(std::vector<Pokemon*>& lista, Pokemon* actual, Pokemon* rival)
{  
    usarObjetos(actual);
    usarObjetos(rival);

        Pokemon* pokemonVeloz;
        Pokemon* pokemonLento;

        if (actual->getVelocidad() > rival->getVelocidad())
        {
            pokemonVeloz = actual;
            pokemonLento = rival;
        }
        else 
        {
            pokemonVeloz = rival;
            pokemonLento = actual;
        }

        while (pokemonVeloz->getVida() > 0 && pokemonLento->getVida() > 0) 
        {

            pokemonVeloz->atacar(pokemonLento);

            if(pokemonLento->getVida() > 0)
            pokemonLento->atacar(pokemonVeloz);

        }

        size_t indexToDelete = SIZE_MAX;
        size_t ganador = SIZE_MAX;

        if (actual->getVida() <= 0)
        {
            for (int i = 0; i < lista.size(); i++) {
                if (lista[i] == actual) {
                    indexToDelete = i;
                }
                if (lista[i] == rival) {
                    ganador = i;
                }
            }      
        }

        if (rival->getVida() <= 0)
        {
            for (int i = 0; i < lista.size(); i++) {
                if (lista[i] == rival) {
                    indexToDelete = i;
                }
                if (lista[i] == actual) {
                    ganador = i;
                }
            }
        }

        cout << endl << "------- BATALLA ENTRE " << pokemonVeloz->getNombre() << " y " << pokemonLento->getNombre() << " ----> GANA " << lista[ganador]->getNombre() << " -------" << endl << endl;

            if (indexToDelete != -1)
            lista[indexToDelete]->setVivo(false);
        
        /*if (indexToDelete != -1) 
        {
            delete lista[indexToDelete];
            lista[indexToDelete] = nullptr;
        }
    

    lista.erase(
        std::remove(lista.begin(), lista.end(), nullptr),
        lista.end()
    );*/

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
        break;

    case 1:
        p = new PokemonAgua(0, 0, vida, equipInicio(), TiposPokemon::Agua, 0, true, nombresAgua[rand() % nombresAgua.size()], vida, damage, velocidad);
        break;

    case 2:
        p = new PokemonPlanta(0, 0, vida, equipInicio(), TiposPokemon::Planta, 0, true, nombresPlanta[rand() % nombresPlanta.size()], vida, damage, velocidad);
        break;

    case 3:
        p = new PokemonElectrico(0, 0, vida, equipInicio(), TiposPokemon::Electrico, 0, true, nombresElectrico[rand() % nombresElectrico.size()], vida, damage, velocidad);
        break;

    default:  
        p = nullptr;
        break;
    }

    int x = 0;
        int y= 0;

    do {

        x = rand() % mapa->MatrizCasillas.size();
        y = rand() % mapa->MatrizCasillas.size();

   } while (mapa->MatrizCasillas[x][y]->pokemon != nullptr);
   
    mapa->MatrizCasillas[x][y]->pokemon = p;

    p->setX(x);
    p->setY(y);

    return p;

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

void Partida::usarObjetos(Pokemon* pokemonDuelo)
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

    cout << pokemonDuelo->getNombre() << " UTILIZA " << (*it)->getNombre() << endl;
    
}

void Partida::reducirZonaAzul(int x, int y) {

    int tamaño = mapa->MatrizCasillas.size(); // tamaño del cuadrado, ejemplo 3x3
    int mitad = tamaño / 2; // distancia desde el centro al borde

    for (int i = -mitad; i <= mitad; ++i) {
        for (int j = -mitad; j <= mitad; ++j) {
            // saltamos el centro si no lo quieres
            if (i == 0 && j == 0) continue;

            // solo bordes del cuadrado
            if (i == -mitad || i == mitad || j == -mitad || j == mitad) {
                int nx = x + i;
                int ny = y + j;

                // revisar que no se salga de los límites
                if (nx >= 0 && nx < mapa->MatrizCasillas.size() && ny >= 0 && ny < mapa->MatrizCasillas.size()) {
                    Casilla* c = mapa->MatrizCasillas[nx][ny];

                    if (c->pokemon) {
                        c->pokemon->setVivo(false);
                        cout << "La zona azul mata a " << c->pokemon->getNombre() << endl;
                        c->pokemon = nullptr;
                    }

                    // aquí haces lo que quieras con la casilla
                }
            }
        }
    }
}

Objeto* Partida::ComprobarObjetoEnCasilla(int x, int y) {
    return mapa->MatrizCasillas[x][y]->objeto;
}

Pokemon* Partida::ComprobarPokemonEnCasilla(int x, int y) {
    return mapa->MatrizCasillas[x][y]->pokemon;
}

//SmartPointers????????????????
//Arreglar en armadura.cpp numUsos porque como solo va a tener 1 siempre deberiamos de hacerlo estatico y en armas deberiamos de definir estaticamente en numUsos en el constructor!!!!!!!!!!!!!!!!!!!
//utilizar aqui es para hacer daño no para sumarle el daño al pokemos que use el arma!!!!!!!!!!!!!!!!!!!!!!!!!!!!111
////CHATGPTeada para sustituir un switch, ns como quereis hacerlo