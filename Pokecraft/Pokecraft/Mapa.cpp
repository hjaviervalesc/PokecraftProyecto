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

Mapa::Mapa(int tamaño, int nObjetos)
{
    CrearMapa(tamaño);
    GenerarObjetos(nObjetos);
}

	void Mapa::CrearMapa(int tamaño) {

		MatrizCasillas.resize(tamaño, std::vector<Casilla*>(tamaño, nullptr));

		for (int i = 0; i < tamaño; i++) {
			for (int j = 0; j < tamaño; j++) {
				MatrizCasillas[i][j] = new Casilla;
			}
		}
        

	}

	void Mapa::GenerarObjetos(int nObjetos) {

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

        for (int i = 0; i < nObjetos; i++) {

            int x = 0, y = 0;

            do {
                x = rand() % MatrizCasillas.size();
                y = rand() % MatrizCasillas.size();
            } 
            while (MatrizCasillas[x][y]->objeto != nullptr);

            int r = rand() % fabricas.size();
            MatrizCasillas[x][y]->objeto = fabricas[r](); 

        }

	}