#include "Pokemon.h"
#include "Objeto.h"


Pokemon::Pokemon(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno): Entidad(x, y, vivo, nombre)
{
	this->vida = vida;
	this->objetos = objetos;
	this->tipo = tipo;
	this->armadura = armadura;
	this->danno = danno;
}

Pokemon::~Pokemon()
{
}

void Pokemon::annadirObjeto(Objeto* objeto)
{
	objetos->push_back(objeto);
}

void Pokemon::annadirVida(int vida)
{
	if (this->vida + vida >= vidaMax)
		this->vida = vidaMax;
	else
		this->vida += vida;
}

void Pokemon::restarVida(int dannoRecibido)
{
	this->vida -= dannoRecibido;
	if (this->vida <= 0)
		vivo = false;
}

void Pokemon::annadirArmadura(int armadura)
{
	this->armadura += armadura;
}

void Pokemon::moverse(int x, int y)
{

}

void Pokemon::atacar(Pokemon* atacado)
{
	int danno = calcularDanno(atacado->getTipo());
	atacado->restarVida(danno);
}
