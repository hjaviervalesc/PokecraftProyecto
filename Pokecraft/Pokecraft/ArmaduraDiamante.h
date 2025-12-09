#pragma once
#include "Armadura.h"
#include "TiposArmadura.h"
class ArmaduraDiamante : public Armadura
{
private:
	TiposArmadura tipoArmadura;
public:
	ArmaduraDiamante(TiposArmadura tipoArmadura, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	~ArmaduraDiamante();
};


