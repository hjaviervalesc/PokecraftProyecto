#include "ArmaduraCuero.h"

ArmaduraCuero::ArmaduraCuero(TiposArmadura tipoArmadura, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre) :Armadura(0, cogido, numUsos, vivo, x, y, tipo, nombre)
{
	switch (tipoArmadura)
	{
	case TiposArmadura::Casco:
		setResistencia(20);
		break;
	case TiposArmadura::Mallas:
		setResistencia(30);
		break;
	case TiposArmadura::Pechera:
		setResistencia(50);
		break;
	default:
		break;
	}

}

ArmaduraCuero::~ArmaduraCuero()
{
}