#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED
#include "Objeto.h"
#include <cstddef>
class iterador{

    private:
        struct Nodo {   Objeto * info;
                        Nodo * sig;
                    };
        Nodo * prim;
        Nodo * ulti;
        Nodo * actual;

    public:
        iterador();
        void insertar(Objeto*);
        bool hayMasObjetos();
        Objeto* proximoObjeto();
        bool esVacio ();
        
        ~iterador ();
};


#endif // ITERADOR_H_INCLUDED
