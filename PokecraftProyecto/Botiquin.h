#pragma once
#include "Objeto.h"
class Botiquin :public Objeto
{
private:
	int regeneracion;
public:
	Botiquin(int regeneracion, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	virtual ~Botiquin();
	virtual void utilizar(Pokemon* pokemon);

};

