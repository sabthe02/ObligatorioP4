#include "ConRemolque.h"


ConRemolque :: ConRemolque():Grande()
{
    capRemolque = 0;
}

ConRemolque :: ConRemolque (String mat, String mar, int cantViajes, float vol, Fecha f, float cap): Grande(mat, mar, cantViajes, vol, f)
{
        capRemolque = cap;
}

ConRemolque :: ConRemolque (String mat, String mar, int cantViajes, Camionero * cam, float vol, Fecha f, float cap): Grande(mat, mar, cantViajes, cam, vol, f)
{
    capRemolque = cap;
}

ConRemolque::ConRemolque(const ConRemolque &otro):Grande(otro) {

capRemolque = otro.capRemolque;

}

float ConRemolque :: getCapRemolque()
{
    return capRemolque;
}

void ConRemolque :: setCapRemolque(float cap)
{
    capRemolque = cap;
}

ConRemolque :: ~ConRemolque ()
{

}

String ConRemolque :: getTipo()
{
    return "ConRemolque";
}

float ConRemolque::calcularCapacidadAnualDeVolumen() {

    float capacidad = Grande::calcularCapacidadAnualDeVolumen();

    int cant = (*this).getCantViajesAnuales();

return capacidad + capRemolque*cant;

}
