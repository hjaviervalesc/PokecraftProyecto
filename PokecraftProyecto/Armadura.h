#pragma once
#include "Objeto.h"
class Armadura :public Objeto
{
private:
	int resistencia;
public:
	Armadura(int resistencia, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	virtual ~Armadura();
	virtual void utilizar(Pokemon* pokemon);
};

