#include "Mapa.h"
#include "Objeto.h"
#include "TiposObjeto.h"
#include "ArmaMadera.h"
#include "ArmaHierro.h"
#include "ArmaDiamante.h"
#include "ArmaduraCuero.h"
#include "ArmaduraHierro.h"
#include "ArmaduraDiamante.h"
#include "Botiquin.h"
#include "Casilla.h"

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

Mapa::Mapa(int tamanno, int nObjetos)
{
    crearMapa(tamanno);
    generarObjetos(nObjetos);
}

void Mapa::crearMapa(int tamanno)
{
    MatrizCasillas.resize(tamanno, std::vector<Casilla*>(tamanno, nullptr));

    for (int i = 0; i < tamanno; i++) {
        for (int j = 0; j < tamanno; j++) {
            MatrizCasillas[i][j] = new Casilla;
        }
    }
}
Objeto* Mapa::generarObjetoAleatorio()
{
    int opcion = rand() % 19;
   
    switch (opcion)
    {
    case 0: return new ArmaduraCuero(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoCuero");
    case 1: return new ArmaduraHierro(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoHierro");
    case 2: return new ArmaduraDiamante(Casco, false, 1, true, rand() % 200, rand() % 200, Armadura, "CascoDiamante");

    case 3: return new ArmaduraCuero(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasCuero");
    case 4: return new ArmaduraHierro(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasHierro");
    case 5: return new ArmaduraDiamante(Mallas, false, 1, true, rand() % 200, rand() % 200, Armadura, "MallasDiamante");

    case 6: return new ArmaduraCuero(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraCuero");
    case 7: return new ArmaduraHierro(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraHierro");
    case 8: return new ArmaduraDiamante(Pechera, false, 1, true, rand() % 200, rand() % 200, Armadura, "PecheraDiamante");

    case 9:  return new ArmaMadera(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloMadera");
    case 10: return new ArmaHierro(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloHierro");
    case 11: return new ArmaDiamante(Martillo, false, 1, true, rand() % 200, rand() % 200, Armas, "MartilloDiamante");

    case 12: return new ArmaMadera(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaMadera");
    case 13: return new ArmaHierro(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaHierro");
    case 14: return new ArmaDiamante(Hacha, false, 1, true, rand() % 200, rand() % 200, Armas, "HachaDiamante");

    case 15: return new ArmaMadera(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaMadera");
    case 16: return new ArmaHierro(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaHierro");
    case 17: return new ArmaDiamante(Espada, false, 1, true, rand() % 200, rand() % 200, Armas, "EspadaDiamante");

    case 18: return new Botiquin(150, false, 1, true, rand() % 200, rand() % 200, BotiquinObjeto, "Botiquin");

    default: return nullptr; // Por seguridad
    }
}
void Mapa::generarObjetos(int nObjetos)
{
    for (int i = 0; i < nObjetos; i++) {
        int x, y;
        
        do {
            x = rand() % MatrizCasillas.size();
            y = rand() % MatrizCasillas.size();
        } while (MatrizCasillas[x][y]->getObjeto() != nullptr);

        
        Objeto* nuevoObjeto = generarObjetoAleatorio();

        if (nuevoObjeto != nullptr) {
            MatrizCasillas[x][y]->setObjeto(nuevoObjeto);
        }
    }
}

Mapa::~Mapa() {
    for (auto& fila : MatrizCasillas) {
        for (Casilla* c : fila) {
            if (c) {
            
               
                delete c;
            }
        }
    }
    MatrizCasillas.clear();
}
