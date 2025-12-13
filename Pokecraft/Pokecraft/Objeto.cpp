#include "Objeto.h"

Objeto::Objeto(bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre): Entidad(x,y,vivo,nombre)
{
	this->cogido = cogido;
	this->numUsos = numUsos;
	this->tipo = tipo;
}

Objeto::~Objeto()
{

}


TiposObjeto Objeto::getTipoObjeto()
{
	return this->tipo;
}