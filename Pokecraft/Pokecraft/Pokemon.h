#pragma once
#include "Entidad.h"
#include <list>
#include "TiposPokemon.h"
class Objeto;
class Pokemon : public Entidad
{
protected:
	int vida;
	std::list<Objeto*>* objetos;
	TiposPokemon tipo;
	int armadura;
	int danno;
	int vidaMax;
	int velocidad;
public:
	Pokemon(int x, int y, int vida, std::list<Objeto*>* objetos, TiposPokemon tipo, int armadura, bool vivo, std::string nombre, int vidaMax, int danno, int velocidad);
	virtual ~Pokemon();
	inline int getVida()
	{
		return vida;
	}
	inline std::list<Objeto*>* getObjetos()
	{
		return objetos;
	}
	inline int getArmadura()
	{
		return armadura;
	}
	inline int getDanno()
	{
		return danno;
	}
	inline int getVelocidad()
	{
		return velocidad;
	}
	inline TiposPokemon getTipo()
	{
		return tipo;
	}

	void annadirObjeto(Objeto* objeto);
	void annadirVida(int vida);
	void restarVida(int dannoRecibido);
	void annadirArmadura(int armadura);
	void moverse(int x, int y);
	void atacar(Pokemon* atacado);
	virtual int calcularDanno(TiposPokemon tipoPokemon) = 0;

};

