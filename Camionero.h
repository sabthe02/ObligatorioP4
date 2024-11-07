#ifndef CAMIONERO_H_INCLUDED
#define CAMIONERO_H_INCLUDED

#include "Str.h"
#include "Fecha.h"
#include "Objeto.h"

class Camionero: Objeto{

private:
    int cedula;
    String nombre;
    int cantTatuajes;
    Fecha fechaNacimiento;
public:
     Camionero();
     Camionero (int, String, int, Fecha);
     Camionero (const Camionero&);
     ~Camionero();
     int getCedula();
     String getNombre();
     int getCantTatuajes();
     Fecha getFechaNacimiento();
     void setNombre(String);
     void setCantTatuajes(int);
     void setFechaNacimiento(Fecha);
     String getTipo();

};

#endif // CAMIONERO_H_INCLUDED
