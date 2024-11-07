#include "Camion.h"



Camion :: Camion ()
{

}

Camion :: Camion (String matricula, String marca, int cantViajes): Matricula(matricula), Marca(marca)
{
    CantViajesAnuales = cantViajes;
}


Camion :: Camion (String matricula, String marca, int cantViajes, Camionero * camionero): Matricula(matricula), Marca(marca)
{
    CantViajesAnuales = cantViajes;
    Cam = camionero;
}

String Camion :: getMatricula()
{
    return Matricula;
}


String Camion :: getMarca()
{
    return Marca;
}

int Camion :: getCantViajesAnuales()
{
    return CantViajesAnuales;
}

Camionero * Camion :: getCamionero()
{
    return Cam;
}

void Camion :: setMarca (String marca)
{
    Marca = marca;
}
void Camion :: setCantViajesAnuales(int catViajes)
{
    CantViajesAnuales = catViajes;
}
void Camion :: setCamionero(Camionero * camionero)
{
    Cam = camionero;
}


Camion :: ~Camion ()
{
    Cam = NULL;
}
