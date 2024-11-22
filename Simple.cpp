#include "Simple.h"

// Constructor por defecto 
Simple :: Simple():Camion(), depto()
{

}

// Constructor comun (sin camionero asignado)
Simple :: Simple(String matricula, String marca, int cantViajes, String departamento): Camion(matricula, marca, cantViajes), depto(departamento)
{

}
// Constructor comun (con camionero asignado)
Simple :: Simple(String matricula, String marca, int cantViajes, Camionero * camionero, String departamento): Camion(matricula, marca, cantViajes, camionero), depto(departamento)
{

}
// Constructor de copia
Simple::Simple(const Simple &otro):Camion(otro), depto(otro.depto)
{

}
// Devuelve el departamento donde opera el camión
String Simple :: getDepto()
{
    return depto;
}
// modifica el departamento donde opera el camión
void Simple :: setDepto(String Departamento)
{
    depto = Departamento;
}

// Destructor
Simple :: ~Simple ()
{

}

//devuelve el tipo de camion
String Simple :: getTipo()
{
    return "Simple";
}


// Método para calcular la capacidad anual de volumen
float Simple::calcularCapacidadAnualDeVolumen()
{

    return (*this).getCantViajesAnuales()*25; // Cada viaje tiene una capacidad fija de 25 unidades.

}



