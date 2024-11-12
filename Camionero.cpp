#include "Camionero.h"

Camionero::Camionero ():nombre(), fechaNacimiento()
{

    cedula = 0;
    cantTatuajes = 0;

}

Camionero::Camionero (int ced, String nom, int canTat, Fecha fecNac): nombre(nom), fechaNacimiento(fecNac)
{

    cedula = ced;
    cantTatuajes = canTat;

}

Camionero::Camionero (const Camionero &otro):nombre(otro.nombre), fechaNacimiento(otro.fechaNacimiento)
{

    cedula = otro.cedula;
    cantTatuajes = otro.cantTatuajes;

}
Camionero::~Camionero()
{

}

int Camionero::getCedula()
{

    return cedula;

}

String Camionero::getNombre()
{

    return nombre;

}

int Camionero:: getCantTatuajes()
{

    return cantTatuajes;

}

Fecha Camionero:: getFechaNacimiento()
{

    return fechaNacimiento;

}

void Camionero:: setNombre(String nom)
{

    nombre = nom;

}

void Camionero::setCantTatuajes(int cant)
{

    cantTatuajes = cant;

}

void Camionero::setFechaNacimiento(Fecha fec)
{

    fechaNacimiento = fec;

}

String Camionero::getTipo()
{

    return "Camionero";

}
