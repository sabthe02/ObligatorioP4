#include "Simple.h"

Simple :: Simple():Camion()
{

}

Simple :: Simple(String matricula, String marca, int cantViajes, String departamento): Camion(matricula, marca, cantViajes), depto(departamento)
{

}

Simple :: Simple(String matricula, String marca, int cantViajes, Camionero * camionero, String departamento): Camion(matricula, marca, cantViajes, camionero), depto(departamento)
{

}

String Simple :: getDepto()
{
    return depto;
}
void Simple :: setDepto(String Departamento)
{
    depto = Departamento;
}

Simple :: ~Simple ()
{

}

String Simple :: getTipo()
{
    return "SIMPLE";
}


