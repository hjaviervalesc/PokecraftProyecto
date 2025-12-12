#include "Mapa.h"

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

Mapa::Mapa(int tamanno, int nObjetos)
{
    CrearMapa(tamanno);
    GenerarObjetos(nObjetos);
}

	void Mapa::CrearMapa(int tamanno) {

		MatrizCasillas.resize(tamanno, std::vector<Casilla*>(tamanno, nullptr));

		for (int i = 0; i < tamanno; i++) {
			for (int j = 0; j < tamanno; j++) {
				MatrizCasillas[i][j] = new Casilla;
			}
		}
       
	}

	void Mapa::GenerarObjetos(int nObjetos) {

        std::vector<Objeto*> poolObjetosMapa = getPoolObjetos();

        for (int i = 0; i < nObjetos; i++) {

            int x = 0, y = 0;

            do {
                x = rand() % MatrizCasillas.size();
                y = rand() % MatrizCasillas.size();
            } 
            while (MatrizCasillas[x][y]->objeto != nullptr);

            int r = rand() % poolObjetosMapa.size();
            MatrizCasillas[x][y]->objeto = poolObjetosMapa[r]; 

        }

	}

Mapa::~Mapa()
{  
    for (size_t i = 0; i < MatrizCasillas.size(); ++i) {
        for (size_t j = 0; j < MatrizCasillas[i].size(); ++j) {
            Casilla* c = MatrizCasillas[i][j];
            if (c != nullptr) {

                delete c;
                MatrizCasillas[i][j] = nullptr;
            }
        }
    }
    MatrizCasillas.clear();
}

std::vector<Objeto*> Mapa::getPoolObjetos()
{ 
    return {
        new ArmaduraCuero(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoCuero"),
    new ArmaduraHierro(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoHierro"),
    new ArmaduraDiamante(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoDiamante"),

    new ArmaduraCuero(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasCuero"),
    new ArmaduraHierro(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasHierro"),
    new ArmaduraDiamante(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasDiamante"),

    new ArmaduraCuero(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraCuero"),
    new ArmaduraHierro(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraHierro"),
    new ArmaduraDiamante(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraDiamante"),

    new ArmaMadera(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloMadera"),
    new ArmaHierro(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloHierro"),
    new ArmaDiamante(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloDiamante"),

    new ArmaMadera(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaMadera"),
    new ArmaHierro(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaHierro"),
    new ArmaDiamante(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaDiamante"),

    new ArmaMadera(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaMadera"),
    new ArmaHierro(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaHierro"),
    new ArmaDiamante(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaDiamante"),

    new Botiquin(150, false, 1, true, rand() % 200, rand() % 200, BotiquinObjeto, "Botiquin")
    };
}