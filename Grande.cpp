#include "Grande.h"

// Constructor por defecto
Grande :: Grande():Camion(), FechaAdquirido()
{
Volumen = 0;
}

// Constructor común (sin camionero asociado)
Grande :: Grande(String mat, String mar, int cantViajes, float vol, Fecha f): Camion(mat, mar, cantViajes), FechaAdquirido(f)
{
    Volumen = vol;
}
// Constructor común (con camionero asociado)
Grande :: Grande(String mat, String mar, int cantViajes, Camionero * cam, float vol, Fecha f): Camion(mat, mar, cantViajes, cam), FechaAdquirido(f)
{
    Volumen = vol;
}

// Constructor de copia
Grande::Grande(const Grande &otro): Camion(otro), FechaAdquirido(otro.FechaAdquirido) {

    Volumen = otro.Volumen;

}
// Devuelve el volumen
float Grande :: getVolumen()
{
    return Volumen;
}

// Devuelve la fecha de adquirido
Fecha Grande :: getFechaAdquirida()
{
    return FechaAdquirido;
}
// Permite modificar el valor del volumen
void Grande :: setVolumen(float vol)
{
    Volumen = vol;
}
// Permite modificar la fecha de adquirido
void Grande :: setFechaAdquirido(Fecha f)
{
    FechaAdquirido = f;
}

// Destructor
Grande :: ~Grande ()
{

}
// Devuelve el tipo de camión
String Grande :: getTipo()
{
    return "Grande";
}

//Calcula la capacidad anual de volumen
float Grande::calcularCapacidadAnualDeVolumen() {

    return (*this).getCantViajesAnuales()*Volumen;

}
