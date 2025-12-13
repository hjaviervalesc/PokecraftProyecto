#pragma once
#include "Entidad.h"
#include <list>
#include "TiposPokemon.h"
class Objeto;
/**
 * @brief Clase que representa un Pokemon en el juego.
 * Hereda de Entidad e incluye estadísticas, objetos y comportamiento de combate.
 *
 * @note Cada Pokemon es propietario de los objetos que posee y se encargará de
 *       liberar la memoria de esos objetos al ser destruido.
 */
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
	static int contadorPokemon;
	bool controlado;
public:
	/**
	  * @brief Constructor del Pokemon.
	  * @param x Posición X inicial.
	  * @param y Posición Y inicial.
	  * @param vida Vida inicial.
	  * @param objetos Lista de objetos inicial (el Pokemon se hace propietario).
	  * @param tipo Tipo de Pokemon.
	  * @param armadura Nivel inicial de armadura.
	  * @param vivo Estado de vida inicial.
	  * @param nombre Nombre del Pokemon.
	  * @param vidaMax Vida máxima del Pokemon.
	  * @param danno Daño base del Pokemon.
	  * @param velocidad Velocidad del Pokemon.
	  */
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
	inline bool getControlado() {
		return controlado;
	}

	void annadirObjeto(Objeto* objeto);
	void annadirVida(int vida);
	void restarVida(int dannoRecibido);
	void annadirArmadura(int armadura);
	void moverse(int x, int y);
	void atacar(Pokemon* atacado);
	virtual int calcularDanno(TiposPokemon tipoPokemon) = 0;
	void setControlado(bool estado);

	static int getContadorPokemon();

};

