#include "ConRemolque.h"


ConRemolque :: ConRemolque()
{
    capRemolque = -1;
}

ConRemolque :: ConRemolque (String mat, String mar, int cantViajes, float vol, Fecha f, float cap): Grande(mat, mar, cantViajes, vol, f)
{
        capRemolque = cap;
}

ConRemolque :: ConRemolque (String mat, String mar, int cantViajes, Camionero * cam, float vol, Fecha f, float cap): Grande(mat, mar, cantViajes, cam, vol, f)
{
    capRemolque = cap;
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
    return "CONREMOLQUE";
}
