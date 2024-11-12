#include "Iterador.h"

iterador::iterador() {
    prim = NULL;
    ulti = NULL;
    actual = NULL;

}

void iterador::insertar(Objeto *o) {
    Nodo* aux = new Nodo;
    aux->info = o;
    aux->sig = NULL;

    if (prim == NULL) {
        prim = aux;
        ulti = aux;
        actual = prim;
    }
    else {
        ulti->sig = aux;
        ulti = aux;
        //prim->sig = aux;
    }

}
bool iterador::hayMasObjetos() {
    bool hay = true;
    if (actual==NULL) {
        hay = false;
    }
    return hay;

}
Objeto* iterador::proximoObjeto() {
    Objeto* aux = actual->info;
    actual = actual->sig;
    return (aux);
}



 bool iterador :: esVacio ()
    {
        return (prim == NULL);
    }


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
