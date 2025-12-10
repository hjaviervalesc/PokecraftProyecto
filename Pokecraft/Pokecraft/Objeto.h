#pragma once
#include "Entidad.h"
#include "TiposObjeto.h"
class Pokemon;
class Objeto : public Entidad
{
protected:
	bool cogido;
	int numUsos;
	TiposObjeto tipo;
public:
	Objeto(bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);

	virtual ~Objeto();
	virtual void utilizar(Pokemon* pokemon) = 0;

	int getX();
	int getY();
	TiposObjeto getTipoObjeto();

};

