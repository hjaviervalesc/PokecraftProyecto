#pragma once
#include "Pokemon.h"
#include <vector>
#include "Casilla.h"

class Mapa
{
public:

	Mapa(int tamanno, int nObjetos);
	~Mapa();

	std::vector<std::vector<Casilla*>> MatrizCasillas;
	
	void CrearMapa(int tamanno);
	void GenerarObjetos(int nObjetos);

	std::vector<Objeto*> getPoolObjetos();
};

