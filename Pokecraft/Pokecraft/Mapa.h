#pragma once
#include "Pokemon.h"
#include <vector>
#include "Casilla.h"

class Mapa
{
public:

	Mapa(int tamaño, int nObjetos);

	std::vector<std::vector<Casilla*>> MatrizCasillas;
	
	void CrearMapa(int tamaño);
	void GenerarObjetos(int nObjetos);
};

