#ifndef CAMIONERO_H_INCLUDED
#define CAMIONERO_H_INCLUDED

#include "Str.h"
#include "Fecha.h"
#include "Objeto.h"

class Camionero: public Objeto{

private:
    int cedula;
    String nombre;
    int cantTatuajes;
    Fecha fechaNacimiento;

public:
    // Constructor por defecto.
    Camionero();

    // Constructor que inicializa el camionero con cédula, nombre, cantidad de tatuajes y fecha de nacimiento.
    Camionero(int, String, int, Fecha);

    // Constructor de copia.
    Camionero(const Camionero&);

    // Destructor.
    ~Camionero();

    // Retorna la cédula de identidad del camionero.
    int getCedula();

    // Retorna el nombre del camionero.
    String getNombre();

    // Retorna la cantidad de tatuajes del camionero.
    int getCantTatuajes();

    // Retorna la fecha de nacimiento del camionero.
    Fecha getFechaNacimiento();

    // Asigna un nuevo nombre al camionero.
    void setNombre(String);

    // Asigna la cantidad de tatuajes al camionero.
    void setCantTatuajes(int);

    // Asigna una nueva fecha de nacimiento al camionero.
    void setFechaNacimiento(Fecha);

    // Retorna el tipo de objeto.
    String getTipo();
};

#endif // CAMIONERO_H_INCLUDED