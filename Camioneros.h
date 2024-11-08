#ifndef CAMIONEROS_H_INCLUDED
#define CAMIONEROS_H_INCLUDED

#include "Camionero.h"
#include "Iterador.h"


class Camioneros{

private:
    struct Nodo {
                        Camionero info;
                        Nodo * hizq;
                        Nodo * hder;
                    };

        Nodo *abb;
        bool Miembro(int, Nodo *);
        void Insertar(Camionero, Nodo *&);
        Camionero Encontrar(int, Nodo *);
        void ListCamioneros(iterador&, Nodo *);
        float volumenPorLista(Nodo *);
public:
        Camioneros();
        ~Camioneros();
        bool Member(int);
        void Insert(Camionero);
        Camionero Find(int);
        void listarCamioneros(iterador&);

};


#endif // CAMIONEROS_H_INCLUDED
