#include "Iterador.h"

// Constructor por defecto del iterador
iterador::iterador()
{
    prim = NULL;  // Puntero al primer nodo de la lista
    ulti = NULL;  // Puntero al último nodo de la lista
    actual = NULL; // Puntero utilizado para recorrer la lista
}

// Método para insertar un objeto en el iterador
// Crea un nuevo nodo con el objeto proporcionado y lo agrega al final de la lista.
void iterador::insertar(Objeto *o)
{
    Nodo* aux = new Nodo;
    aux->info = o;
    aux->sig = NULL;

    if (prim == NULL)
    {
        prim = aux;
        ulti = aux;
        actual = prim;
    }
    else
    {
        ulti->sig = aux;
        ulti = aux;
    }

}

// Método para verificar si quedan objetos por recorrer
// Retorna true si el puntero 'actual' no es NULL, lo que indica que hay más nodos.
bool iterador::hayMasObjetos()
{
    bool hay = true;
    if (actual==NULL)
    {
        hay = false;
    }
    return hay;

}

// Método para obtener el próximo objeto en la lista
// Devuelve el objeto del nodo apuntado por 'actual' y avanza al siguiente nodo.
Objeto* iterador::proximoObjeto()
{
    Objeto* aux = actual->info;
    actual = actual->sig;
    return (aux);
}

// Destructor 
iterador :: ~iterador ()
{
    Nodo * aux;
    while (prim != NULL)
    {
        aux = prim;
        prim = prim->sig;
        delete aux;
    }
}
