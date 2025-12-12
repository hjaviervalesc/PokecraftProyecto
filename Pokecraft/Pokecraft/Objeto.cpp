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

int Objeto::getX()
{
	return this->x;
}
int Objeto::getY()
{
	return this->y;
}
TiposObjeto Objeto::getTipoObjeto()
{
	return this->tipo;
}