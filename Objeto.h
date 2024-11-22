#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED

#include "Str.h"

class Objeto{

private:

public:
    // Constructor por defecto
    Objeto();

    // Destructor virtual
    // se llamen correctamente al eliminar un objeto de este tipo.
    virtual ~Objeto();

    // Método virtual puro que debe ser implementado por las clases derivadas.
    virtual String getTipo() = 0;
};

#endif // OBJETO_H_INCLUDED