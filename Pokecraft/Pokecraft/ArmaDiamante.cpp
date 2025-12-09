#include "ArmaDiamante.h"

ArmaDiamante::ArmaDiamante(TiposArma tipoArma, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre) : Arma(0, cogido, numUsos, vivo, x, y, tipo, nombre)
{
	switch (tipoArma)
	{
		case TiposArma::Martillo:
			setDanno(50);
			break;
		case TiposArma::Hacha:
			setDanno(80);
			break;
		case TiposArma::Espada:
			setDanno(110);
			break;
		default:
			break;
	}	

}

ArmaDiamante::~ArmaDiamante()
{
}
