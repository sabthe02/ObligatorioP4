#ifndef CAMIONEROS_H_INCLUDED
#define CAMIONEROS_H_INCLUDED

#include "Camionero.h"
#include "Iterador.h"


class Camioneros
{

private:
    struct Nodo
    {
        Camionero info;      // Información del camionero almacenado en el nodo.
        Nodo *hizq;          // Puntero al hijo izquierdo.
        Nodo *hder;          // Puntero al hijo derecho.
    };

    Nodo *abbCam;            // Puntero a la raíz del árbol binario de camioneros.

    // Verifica si un camionero con una cédula específica está en el árbol.
    bool Miembro(int, Nodo *);

    // Inserta un nuevo camionero en el árbol.
    void Insertar(Camionero, Nodo *&);

    // Verifica si el árbol está vacío.
    bool Vacio(Nodo*);

    // Busca un camionero con una cédula específica en el árbol.
    Camionero * Encontrar(int, Nodo *);

    // Llena un iterador con los camioneros almacenados en el árbol.
    void ListCamioneros(iterador&, Nodo *);

    // Encuentra al camionero con mayor cantidad de tatuajes en el árbol.
    Camionero MostTattoos(Nodo *, Camionero camionero);

public:
    // Constructor por defecto.
    Camioneros();

    // Destructor.
    ~Camioneros();

    // Verifica si un camionero con una cédula específica está en el árbol 
    bool Member(int);

    // Inserta un nuevo camionero en el árbol 
    void Insert(Camionero);

    // Busca un camionero con una cédula específica en el árbol 
    Camionero * Find(int);

    // Verifica si el árbol de camioneros está vacío
    bool Empty();

    // Llena un iterador con todos los camioneros registrados
    void listarCamioneros(iterador&);

    // Encuentra al camionero con la mayor cantidad de tatuajes
    Camionero MayorCantTatuajes();
};

#endif // CAMIONEROS_H_INCLUDED