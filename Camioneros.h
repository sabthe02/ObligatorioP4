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

        Nodo *abbCam;
        bool Miembro(int, Nodo *);
        void Insertar(Camionero, Nodo *&);
        bool Vacio(Nodo*);
        Camionero * Encontrar(int, Nodo *);
        void ListCamioneros(iterador&, Nodo *);
        Camionero MostTattoos (Nodo *, int&);

public:
        Camioneros();
        ~Camioneros();
        bool Member(int);
        void Insert(Camionero); // Aca no seria (Camionero *)
        Camionero * Find(int); //Camionero * find (int) ??
        bool Empty ();
        void listarCamioneros(iterador&);
        Camionero MayorCantTatuajes ();

};


#endif // CAMIONEROS_H_INCLUDED
