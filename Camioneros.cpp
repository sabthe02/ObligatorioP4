#include "Camioneros.h"

// Constructor por defecto
Camioneros::Camioneros()
{
    abbCam=NULL;

}

// Destructor
Camioneros::~Camioneros()
{

}

// Verifica si un camionero con la cédula 'c' esta en el arbol
bool Camioneros::Miembro(int c, Nodo * abb )
{
    bool pertenece;

    if (abb== NULL)
    {
        pertenece = false;
    }
    else
    {
        if (abb->info.getCedula() ==c)
        {
            pertenece = true;
        }
        else
        {
            if (c < abb->info.getCedula())
            {
                pertenece = Miembro(c,abb->hizq);
            }
            else
            {
                pertenece = Miembro(c,abb->hder);
            }
        }
    }
    return pertenece;

}

// Verifica si un camionero con la cédula 'c' pertenece al árbol 
bool Camioneros::Member(int c)
{

    return (Miembro(c, abbCam));

}

// Inserta un camionero nuevo en el arbol
void Camioneros:: Insertar(Camionero c, Nodo * &abb)
{
    if (abb==NULL)
    {
        abb = new Nodo;
        abb->info = c;
        abb->hizq = NULL;
        abb->hder = NULL;
    }
    else
    {
        if ((c.getCedula()) < (abb->info.getCedula()))
        {
            Insertar(c,abb->hizq);
        }
        else
        {
            Insertar(c,abb->hder);
        }
    }

}


// Encuentra y devuelve un puntero al camionero con la cédula 'c' en el arbol
Camionero * Camioneros::Encontrar(int c, Nodo * abb)
{
    Camionero * camionero;
    if (abb->info.getCedula() ==c)
    {
        camionero = &abb->info;
    }
    else
    {
        if (c < abb->info.getCedula())
        {
            Encontrar (c,abb->hizq);
        }
        else
        {
            Encontrar(c,abb->hder);
        }
    }

    return camionero;
}

// Verifica si el árbol está vacío.
bool Camioneros::Vacio (Nodo *abb)
{

    bool es;
    if (abb==NULL)
    {
        es = true;
    }
    else
    {
        es = false;
    }

    return es;

}

// Recorre el abb y agrega los camioneros al iterador.
void Camioneros:: ListCamioneros(iterador &iter, Nodo * abb)
{

    if (abb!=NULL)
    {
        ListCamioneros(iter, abb->hizq);
        iter.insertar(&abb->info);
        ListCamioneros(iter, abb->hder);

    }

}

// Encuentra el camionero con la mayor cantidad de tatuajes
Camionero Camioneros::MostTattoos (Nodo *abb, Camionero camionero)
{
    if (abb!=NULL)
    {
        if (abb->info.getCantTatuajes() >= camionero.getCantTatuajes())
        {
            camionero = abb->info;

        }

        camionero = MostTattoos(abb->hizq, camionero);
        camionero = MostTattoos(abb->hder, camionero);

    }

    return camionero;
}

// Inserta un nuevo camionero en el árbol 
void Camioneros::Insert(Camionero c)
{

    Insertar(c, abbCam);

}

// Encuentra y devuelve un puntero al camionero con la cédula 'c' en el árbol principal.
Camionero * Camioneros::Find(int c)
{

    return Encontrar(c,abbCam);

}

// Verifica si el árbol de camioneros está vacío
bool Camioneros::Empty()
{

    return Vacio(abbCam);

}

// Llena un iterador con todos los camioneros registrados
void Camioneros::listarCamioneros(iterador &iter)
{

    ListCamioneros(iter, abbCam);

}

// Encuentra y devuelve el camionero con la mayor cantidad de tatuajes en el árbol principal.
Camionero Camioneros:: MayorCantTatuajes ()
{


    Camionero cam = MostTattoos(abbCam, abbCam->info);

    return cam;

}
