#pragma once
#include <string>
class Entidad
{
protected:
	int x, y;
	bool vivo;
	std::string nombre;
public:
	Entidad(int x, int y, bool vivo, std::string nombre);
	~Entidad();
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

