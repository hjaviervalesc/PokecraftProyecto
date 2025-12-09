#pragma once
#include "Armadura.h"
#include "TiposArmadura.h"
class ArmaduraHierro : public Armadura
{
private:
	TiposArmadura tipoArmadura;
public:
	ArmaduraHierro(TiposArmadura tipoArmadura, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	~ArmaduraHierro();
};


