#include "Camion.h"

// Constructor por defecto
Camion :: Camion ():Matricula(), Marca()
{
    CantViajesAnuales = 0;
    Cam = NULL;
}

// Constructor común. Inicializa matrícula, marca y cantidad de viajes anuales.
Camion :: Camion (String matricula, String marca, int cantViajes): Matricula(matricula), Marca(marca)
{
    CantViajesAnuales = cantViajes;
}

// Constructor común. Inicializa matrícula, marca y cantidad de viajes anuales,  y asigna un camionero.
Camion :: Camion (String matricula, String marca, int cantViajes, Camionero * camionero): Matricula(matricula), Marca(marca)
{
    CantViajesAnuales = cantViajes;
    Cam = camionero;
}

// Constructor de copia. 
Camion::Camion (const Camion &otro): Matricula(otro.Matricula), Marca(otro.Marca)
{

    CantViajesAnuales = otro.CantViajesAnuales;


    if (otro.Cam!= NULL) {
        Camionero *aux = new Camionero;
        aux = otro.Cam;
        setCamionero(aux);
    }
    else {
        Cam = NULL;
    }

}

// Devuelve la matrícula del camión.
String Camion :: getMatricula()
{
    return Matricula;
}

// Devuelve la marca del camión.
String Camion :: getMarca()
{
    return Marca;
}

// Devuelve la cantidad de viajes anuales del camión.
int Camion :: getCantViajesAnuales()
{
    return CantViajesAnuales;
}

// Devuelve el puntero al camionero asociado al camión.
Camionero * Camion :: getCamionero()
{
    return Cam;
}

// Modifica la marca del camión
void Camion :: setMarca (String marca)
{
    Marca = marca;
}

// Modifica la cantidad de viajes anuales del camion
void Camion :: setCantViajesAnuales(int catViajes)
{
    CantViajesAnuales = catViajes;
}

// Asocia un camionero al camión.
void Camion :: setCamionero(Camionero * camionero)
{
    Cam = camionero;


}

// Destructor
Camion :: ~Camion ()
{

}


