#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED

#include "Camion.h"
#include "Iterador.h"

const int B = 100;

class Camiones{

private:
    struct Nodo {   Camion * info;
                    Nodo * sig;
                    };
        Nodo * Hash[B];

        int h(String);
        void crearLista (Nodo * &);
        void destruirLista (Nodo * &);
        bool perteneceLista (Nodo *, String);
        void insFrontEnLista (Nodo * &, Camion *);
        Camion * obtenerEnLista (Nodo *, String);
        void listarTodosEnLista(Nodo *, iterador&);
        float volumenPorLista (Nodo *);
        void cantidadEnFlotaLista (Nodo *, int&, int&, int&);

public:
        Camiones();
        ~Camiones();
        bool Member(String);
        void Insert(Camion*);
        Camion* Find(String);
        void listarCamiones(iterador&);
        float capacidadAnualFlota();
        void cantidadEnFlota(int&, int&, int&);

};

#endif // CAMIONES_H_INCLUDED
