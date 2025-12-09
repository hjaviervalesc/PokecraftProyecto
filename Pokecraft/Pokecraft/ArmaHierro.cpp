#include "ArmaHierro.h"

ArmaHierro::ArmaHierro(TiposArma tipoArma, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre) : Arma(0, cogido, numUsos, vivo, x, y, tipo, nombre)
{
	switch (tipoArma)
	{
	case TiposArma::Martillo:
		setDanno(30);
		break;
	case TiposArma::Hacha:
		setDanno(50);
		break;
	case TiposArma::Espada:
		setDanno(80);
		break;
	default:
		break;
	}

}

ArmaHierro::~ArmaHierro()
{

}
