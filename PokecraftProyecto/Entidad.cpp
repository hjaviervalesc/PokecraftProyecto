#include "Entidad.h"
#include <string>

Entidad::Entidad(int x, int y, bool vivo, std::string nombre)
{
	this->x = x;
	this->y = y;
	this->vivo = vivo;
	this->nombre = nombre;
}

Entidad::~Entidad()
{
}

