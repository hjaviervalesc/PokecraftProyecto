#pragma once
#include "Arma.h"
#include "TiposArma.h"
class ArmaMadera : public Arma
{
private:
	TiposArma tipoArma;
public:
	ArmaMadera(TiposArma tipoArma, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	~ArmaMadera();
};
