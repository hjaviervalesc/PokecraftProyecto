#pragma once
#include "Arma.h"
#include "TiposArma.h"
class ArmaDiamante : public Arma
{
private:
	TiposArma tipoArma;
public:
	ArmaDiamante(TiposArma tipoArma, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	~ArmaDiamante();
};
