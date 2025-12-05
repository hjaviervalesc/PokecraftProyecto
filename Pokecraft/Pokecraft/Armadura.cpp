#include "Armadura.h"
#include "Pokemon.h"

//Armadura::Armadura(int resistencia, bool cogido, int numUsos, bool vivo, int x, int y, TiposObjeto tipo, std::string nombre) :Objeto(cogido, numUsos, vivo, x, y, tipo, nombre)
//{
//}

Armadura::~Armadura()
{
}

void Armadura::utilizar(Pokemon* pokemon)
{
	pokemon->annadirArmadura(resistencia);
	vivo = false;
	
}
