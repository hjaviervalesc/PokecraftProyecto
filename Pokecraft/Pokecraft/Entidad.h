#pragma once
#include <string>
/**
 * @brief Clase base para todas las entidades del juego, como Pokemons u objetos.
 * Contiene posición, estado de vida y nombre.
 */
class Entidad
{
protected:
	int x, y;
	bool vivo;
	std::string nombre;
public:
	/**
	* 
	* @param x Posición horizontal inicial.
	* @param y Posición vertical inicial.
	* @param vivo Estado inicial de vida.
	* @param nombre Nombre de la entidad.
	*/
	Entidad(int x, int y, bool vivo, std::string nombre);
	virtual ~Entidad();
	inline const int getX()
	{
		return x;
	}
	inline const int getY()
	{
		return y;
	}
	inline void setX(int x)
	{
		this->x = x;
	}
	inline void setY(int y)
	{
		this->y = y;
	}
	inline bool getVivo()
	{
		return vivo;
	}
	inline void setVivo(bool vivo)
	{
		this->vivo = vivo;
	}
	inline std::string getNombre()
	{
		return nombre;
	}

};

