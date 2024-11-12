#include "Camioneros.h"

Camioneros::Camioneros()
{
    abbCam=NULL;

}


Camioneros::~Camioneros()
{

}
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

bool Camioneros::Member(int c)
{

    return (Miembro(c, abbCam));

}

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


void Camioneros:: ListCamioneros(iterador &iter, Nodo * abb)
{

    if (abb!=NULL)
    {
        ListCamioneros(iter, abb->hizq);
        iter.insertar(&abb->info);
        ListCamioneros(iter, abb->hder);

    }

}

Camionero Camioneros::MostTattoos (Nodo *abb, int &cant)
{
    Camionero camionero;
    if (abb!=NULL)
    {
        if (abb->info.getCantTatuajes() >=cant)
        {
            camionero = abb->info;
            cant = camionero.getCantTatuajes();
        }
        MostTattoos(abb->hizq, cant);
        MostTattoos(abb->hder, cant);

    }
    return camionero;

}

void Camioneros::Insert(Camionero c)
{

    Insertar(c, abbCam);

}

Camionero * Camioneros::Find(int c)
{

    return Encontrar(c,abbCam);

}

bool Camioneros::Empty()
{

    return Vacio(abbCam);

}


void Camioneros::listarCamioneros(iterador &iter)
{

    ListCamioneros(iter, abbCam);

}

Camionero Camioneros:: MayorCantTatuajes ()
{

    int cant = 0;

    return MostTattoos(abbCam, cant);

}
