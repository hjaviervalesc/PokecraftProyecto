#include "ArmaduraDiamante.h"

ArmaduraDiamante::ArmaduraDiamante(TiposArmadura tipoArmadura, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre) :Armadura(0, cogido, numUsos, vivo, x, y, tipo, nombre)
{
	switch (tipoArmadura)
	{
	case TiposArmadura::Casco:
		setResistencia(40);
		break;
	case TiposArmadura::Mallas:
		setResistencia(80);
		break;
	case TiposArmadura::Pechera:
		setResistencia(110);
		break;
	default:
		break;
	}

}

ArmaduraDiamante::~ArmaduraDiamante()
{

}