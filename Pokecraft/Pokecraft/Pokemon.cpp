#include "Pokemon.h"
#include "Objeto.h"

int Pokemon::contadorPokemon = 0;

Pokemon::Pokemon(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno, int velocidad): Entidad(x, y, vivo, nombre)
{
	this->vida = vida;
	this->objetos = objetos;
	this->tipo = tipo;
	this->armadura = armadura;
	this->danno = danno;
	this->vidaMax = vidaMax;
	this->velocidad = velocidad;
	contadorPokemon++;
}

Pokemon::~Pokemon()
{
	contadorPokemon--;
	if (objetos != nullptr)
	{
		for (Objeto* o : *objetos)
		{
			delete o;
		}

		delete objetos;
		objetos = nullptr;
	}
}

int Pokemon::getContadorPokemon()
{
	return contadorPokemon;
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
	this->x += x;
	this->y += y;
}

void Pokemon::atacar(Pokemon* atacado)
{
	int danno = calcularDanno(atacado->getTipo());
	atacado->restarVida(danno);
}

void Pokemon::setControlado(bool estado) {
	controlado = estado;
}

//void::Pokemon::usarObjetoAleatorio() {
//	if (objetos->size() == 0) return;
//
//	int index = rand() % objetos->size();
//
//	auto it = objetos->begin();
//	std::advance(it, index);
//
//	Objeto* aleatorio = *it;
//
//	aleatorio->utilizar(this);
//}
