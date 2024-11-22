#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED

#include "Camion.h"
#include "Camioneros.h"
#include "Iterador.h"
#include "Grande.h"
#include "Simple.h"
#include "ConRemolque.h"

// Tamaño del hash 
const int B = 100;

class Camiones
{

private:
    struct Nodo
    {
        Camion *info;   // Puntero a un camión almacenado.
        Nodo *sig;      // Puntero al siguiente nodo en la lista.
    };
    Nodo * Hash[B];

    // Función hash que calcula la posición en la tabla para una clave dada.
    int h(String);

    // Crea una lista enlazada inicializada como vacía.
    void crearLista(Nodo *&);

    // Destruye todos los elementos de la lista.
    void destruirLista(Nodo *&);

    // Verifica si un camión con una matrícula específica pertenece a una lista.
    bool perteneceLista(Nodo *, String);

    // Inserta un camión al frente de una lista.
    void insFrontEnLista(Nodo *&, Camion *);

    // Obtiene un camión por su matrícula 
    Camion *obtenerEnLista(Nodo *, String);

    // Llena un iterador con todos los camiones almacenados 
    void listarTodosEnLista(Nodo *, iterador&);

    // Calcula la capacidad total de volumen anual para una lista de camiones
    float volumenPorLista(Nodo *);

    // Cuenta la cantidad de camiones por tipo 
    void cantidadEnFlotaLista(Nodo *, int&, int&, int&);

    // Cuenta los camiones grandes registrados después de una fecha
    int contarCamionesGrandesPostFechaLista(Nodo *, Fecha);

public:
    // Constructor por defecto.
    Camiones();

    // Destructor.
    ~Camiones();

    // Verifica si la tabla hash está vacía.
    bool Empty();

    // Verifica si un camión con una matrícula específica pertenece a la tabla hash
    bool Member(String);

    // Inserta un camión en la tabla hash.
    void Insert(Camion*);

    // Busca un camión por su matrícula 
    Camion* Find(String);

    // Llena un iterador con todos los camiones registrados
    void listarCamiones(iterador&);

    // Calcula la capacidad total de volumen anual de la flota.
    float capacidadAnualFlota();

    // Obtiene la cantidad de camiones en la flota clasificados por tipo.
    void cantidadEnFlota(int&, int&, int&);

    // Cuenta los camiones grandes registrados después de una fecha específica.
    int contarCamionesGrandesPostFecha(Fecha);
};

#endif // CAMIONES_H_INCLUDED