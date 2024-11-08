#include "Camiones.h"

int Camiones::h(String x) {

int y = x.sumarCaracteres();

    return (y % B);
}

void Camiones :: crearLista (Nodo * &L)
{
    L = NULL;
}
void Camiones :: destruirLista (Nodo * &L)
{
    Nodo * aux = L;
    while (aux != NULL)
    {
        L = aux->sig;
        delete (aux);
        aux = L;
    }
    L = aux;
}

bool Camiones :: perteneceLista (Nodo * L, String mat)
{
    bool existe = false;
    while (!existe && L != NULL)
        if (L->info->getMatricula() == mat)
            existe = true;
        else
            L = L->sig;
    return existe;
}

void Camiones :: insFrontEnLista (Nodo * &L, Camion * c)
{
    Nodo * aux = new Nodo;
    aux->info = c;
    aux->sig = L;
    L = aux;
}
Camion * Camiones :: obtenerEnLista (Nodo * L, String mat)
{
    while (L->info->getMatricula() != mat)
        L = L->sig;
    return (L->info);
}

void Camiones :: listarTodosEnLista (Nodo * L, iterador &iter)
{
    while (L != NULL)
    {
        iter.insertar(L->info);
        L = L->sig;
    }
}

float Camiones :: volumenPorLista (Nodo * L)
{
    int volumenLista = 0;
    while (L != NULL)
    {
        volumenLista = L->info->calcularCapacidadAnualDeVolumen()+volumenLista;
        L = L->sig;
    }
return volumenLista;
}

void Camiones::cantidadEnFlotaLista(Nodo *L, int &simples, int &grandes, int &conremolque) {

    simples = 0;
    grandes = 0;
    conremolque = 0;

    while (L != NULL)
    {
        if(L->info->getTipo() =="Simple") {
            simples++;
        }
        else {
            if ((L->info->getTipo() =="Grande")){
                grandes++;
            }
            else {
                conremolque++;
            }
        }
        L = L->sig;
    }

}

Camiones::Camiones() {

    for (int i=0; i <B; i++) {
        crearLista(Hash[i]);
    }

}

Camiones::~Camiones() {

    for (int i=0;i<B;i++) {
        destruirLista(Hash[i]);
    }

}
bool Camiones::Member(String mat) {

    int cubeta = h(mat);
    return (perteneceLista (Hash[cubeta], mat));
}

void Camiones::Insert(Camion *c) {

    String mat = c->getMatricula();
    int cubeta = h(mat);
    insFrontEnLista (Hash[cubeta], c);
}

Camion* Camiones:: Find(String mat) {

    int cubeta = h(mat);
    return (obtenerEnLista (Hash[cubeta], mat));

}

 void Camiones:: listarCamiones (iterador &iter) {

    for (int i=0; i < B; i++)
    listarTodosEnLista (Hash[i], iter);

 }

 float Camiones:: capacidadAnualFlota() {

     float capacidad;
     for (int i=0;i < B; i++) {
        capacidad = volumenPorLista(Hash[i]);
     }
     return capacidad;
 }

void Camiones::cantidadEnFlota(int &simple, int &grande, int &conremolque) {



}
