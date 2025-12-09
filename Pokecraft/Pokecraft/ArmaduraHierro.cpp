#include "ArmaduraHierro.h"

ArmaduraHierro::ArmaduraHierro(TiposArmadura tipoArmadura, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre) :Armadura(0, cogido, numUsos, vivo, x, y, tipo, nombre)
{
	switch (tipoArmadura)
	{
	case TiposArmadura::Casco:
		setResistencia(30);
		break;
	case TiposArmadura::Mallas:
		setResistencia(50);
		break;
	case TiposArmadura::Pechera:
		setResistencia(80);
		break;
	default:
		break;
	}

}

ArmaduraHierro::~ArmaduraHierro()
{

}