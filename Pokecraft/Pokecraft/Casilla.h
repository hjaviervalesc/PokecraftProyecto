#pragma once

class Pokemon;
class Objeto;

class Casilla
{
private:
    Pokemon* pokemon; // No posee el puntero, memoria gestionada externamente
    Objeto* objeto;   // No posee el puntero, memoria gestionada externamente

public:
    Casilla() : pokemon(nullptr), objeto(nullptr) {}
    virtual ~Casilla();

    // Getters
    Pokemon* getPokemon() const { return pokemon; }
    Objeto* getObjeto() const { return objeto; }

    // Setters
    void setPokemon(Pokemon* p) { pokemon = p; }
    void setObjeto(Objeto* o) { objeto = o; }
};
