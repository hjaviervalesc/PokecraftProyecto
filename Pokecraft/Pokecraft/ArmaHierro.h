#pragma once
#include "Arma.h"
#include "TiposArma.h"
class ArmaHierro : public Arma
{
private:
	TiposArma tipoArma;
public:
	ArmaHierro(TiposArma tipoArma, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	~ArmaHierro();
};
