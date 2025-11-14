#pragma once
#include "Objeto.h"
class Arma : public Objeto
{
private:
	int danno;
	int rango;
public:
	Arma(int danno, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	virtual ~Arma();
	virtual void utilizar(Pokemon* pokemon);
};

