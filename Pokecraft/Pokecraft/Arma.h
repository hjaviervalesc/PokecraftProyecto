#pragma once
#include "Objeto.h"
class Arma : public Objeto
{
private:
	int danno;
public:
	Arma(int danno, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre);
	virtual ~Arma();
	virtual void utilizar(Pokemon* pokemon);

	int getDanno();

	void setDanno(int danno);

};

