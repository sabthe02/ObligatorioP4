#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED
#include "Objeto.h"
#include <cstddef>
class iterador{

    private:
        struct Nodo {   Objeto * info;
                        Nodo * sig;
                    };
        Nodo * prim;        // Puntero al primer nodo de la lista.
        Nodo * ulti;        // Puntero al último nodo de la lista.
        Nodo * actual;      // Puntero al nodo actual durante la iteración.

    public:
    // Constructor por defecto
    iterador();

    // Inserta un objeto en la lista gestionada por el iterador.
    void insertar(Objeto*);

    // Indica si hay más objetos disponibles en la lista para iterar.
    bool hayMasObjetos();

    // Devuelve el próximo objeto en la lista y avanza el iterador.
    Objeto* proximoObjeto();

    // Destructor
    ~iterador();
};

#endif // ITERADOR_H_INCLUDED