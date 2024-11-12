#include "Grande.h"


Grande :: Grande():Camion(), FechaAdquirido()
{
Volumen = 0;
}

Grande :: Grande(String mat, String mar, int cantViajes, float vol, Fecha f): Camion(mat, mar, cantViajes), FechaAdquirido(f)
{
    Volumen = vol;
}

Grande :: Grande(String mat, String mar, int cantViajes, Camionero * cam, float vol, Fecha f): Camion(mat, mar, cantViajes, cam), FechaAdquirido(f)
{
    Volumen = vol;
}

Grande::Grande(const Grande &otro):Camion(otro), FechaAdquirido(otro.FechaAdquirido) {

Volumen = otro.Volumen;

}

float Grande :: getVolumen()
{
    return Volumen;
}

Fecha Grande :: getFechaAdquirida()
{
    return FechaAdquirido;
}

void Grande :: setVolumen(float vol)
{
    Volumen = vol;
}

void Grande :: setFechaAdquirido(Fecha f)
{
    FechaAdquirido = f;
}

Grande :: ~Grande ()
{

}

String Grande :: getTipo()
{
    return "Grande";
}

float Grande::calcularCapacidadAnualDeVolumen() {

    return (*this).getCantViajesAnuales()*Volumen;

}
