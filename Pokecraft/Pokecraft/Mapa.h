#pragma once

#include <vector>

class Objeto;
class Casilla;
/**
 * @brief Representa el mapa del juego, compuesto por una matriz de casillas.
 * Cada casilla puede contener un Pokemon o un Objeto.
 */
class Mapa
{
public:

    /**
        * @brief Constructor que crea el mapa y genera objetos aleatorios.
        * @param tamanno Tamaño del mapa (número de casillas por lado).
        * @param nObjetos Número de objetos a colocar aleatoriamente en el mapa.
        */
    Mapa(int tamanno, int nObjetos);

    /**
     * @brief Destructor del mapa.
     * Libera la memoria de todas las casillas.
     */
    ~Mapa();

    std::vector<std::vector<Casilla*>> MatrizCasillas; 

    /**
     * @brief Inicializa la matriz de casillas del mapa.
     * @param tamanno Tamaño de la matriz.
     */
    void crearMapa(int tamanno);
    Objeto* generarObjetoAleatorio();
    /**
     * @brief Coloca objetos aleatorios en las casillas vacías del mapa.
     * @param nObjetos Número de objetos a generar.
     */
    void generarObjetos(int nObjetos);

    /**
     * @brief Devuelve un pool de objetos que pueden aparecer en el mapa.
     * @return Vector de punteros a objetos recién creados.
     */
    //std::vector<Objeto*> getPoolObjetos();
};

