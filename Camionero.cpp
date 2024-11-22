#include "Camionero.h"

// Constructor por defecto
Camionero::Camionero ():nombre(), fechaNacimiento()
{

    cedula = 0;
    cantTatuajes = 0;

}

// Constructor comun
Camionero::Camionero (int ced, String nom, int canTat, Fecha fecNac): nombre(nom), fechaNacimiento(fecNac)
{

    cedula = ced;
    cantTatuajes = canTat;

}

// Constructor de copia
Camionero::Camionero (const Camionero &otro):nombre(otro.nombre), fechaNacimiento(otro.fechaNacimiento)
{

    cedula = otro.cedula;
    cantTatuajes = otro.cantTatuajes;

}
// Destructor
Camionero::~Camionero()
{

}

// Devuelve la cédula del camionero.
int Camionero::getCedula()
{

    return cedula;

}

// Devuelve el nombre del camionero.
String Camionero::getNombre()
{

    return nombre;

}

// Devuelve la cantidad de tatuajes del camionero.
int Camionero:: getCantTatuajes()
{

    return cantTatuajes;

}

// Devuelve la fecha de nacimiento del camionero.
Fecha Camionero:: getFechaNacimiento()
{

    return fechaNacimiento;

}

// Modifica el nombre del camionero.
void Camionero:: setNombre(String nom)
{

    nombre = nom;

}

// Modifica la cantidad de tatuajes del camionero.
void Camionero::setCantTatuajes(int cant)
{

    cantTatuajes = cant;

}

// Modifica la fecha de nacimiento del camionero.
void Camionero::setFechaNacimiento(Fecha fec)
{

    fechaNacimiento = fec;

}

// Devuelve el tipo como un string
String Camionero::getTipo()
{

    return "Camionero";

}
