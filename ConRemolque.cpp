#include "ConRemolque.h"

// Constructor por defecto
ConRemolque :: ConRemolque():Grande()
{
    capRemolque = 0;
}
// Constructor comun (sin camionero asignado)
ConRemolque :: ConRemolque (String mat, String mar, int cantViajes, float vol, Fecha f, float cap): Grande(mat, mar, cantViajes, vol, f)
{
        capRemolque = cap;
}
// Constructor comun con camionero asignado
ConRemolque :: ConRemolque (String mat, String mar, int cantViajes, Camionero * cam, float vol, Fecha f, float cap): Grande(mat, mar, cantViajes, cam, vol, f)
{
    capRemolque = cap;
}

// Constructor de copia
ConRemolque::ConRemolque(const ConRemolque &otro): Grande(otro) {

    capRemolque = otro.capRemolque;

}
// Devuelve la capacidad del remolque
float ConRemolque :: getCapRemolque()
{
    return capRemolque;
}
// Permite modificar el valor de capRemolque.
void ConRemolque :: setCapRemolque(float cap)
{
    capRemolque = cap;
}
// Destructor
ConRemolque :: ~ConRemolque ()
{

}
// Devuelve el tipo del camión "ConRemolque"
String ConRemolque :: getTipo()
{
    return "ConRemolque";
}
// calcular la capacidad anual de volumen
float ConRemolque::calcularCapacidadAnualDeVolumen() {

    float capacidad = Grande::calcularCapacidadAnualDeVolumen();

    int cant = (*this).getCantViajesAnuales();

return capacidad + capRemolque*cant;

}
