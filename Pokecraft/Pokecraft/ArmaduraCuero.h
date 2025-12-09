#pragma once
#include "Armadura.h"
#include "TiposArmadura.h"
class ArmaduraCuero : public Armadura
{
private:
	TiposArmadura tipoArmadura;
public:
	ArmaduraCuero(TiposArmadura tipoArmadura, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	~ArmaduraCuero();
};

