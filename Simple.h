#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include "Camion.h"
#include "Str.h"

class Simple: public Camion{

private:
    String depto;

public:
    // Constructor por defecto
    Simple();

    // Constructor que inicializa un camión del tipo Simple con matrícula, marca, cantidad de viajes anuales y departamento.
    Simple(String, String, int, String);

    // Constructor que inicializa un camión del tipo Simple con matrícula, marca, cantidad de viajes anuales, 
    // un camionero asociado y un departamento.
    Simple(String, String, int, Camionero *, String);

    // Constructor de copia.
    Simple(const Simple&);

    // Retorna el departamento asociado al camión.
    String getDepto();

    // Establece el departamento asociado al camión.
    void setDepto(String);

    // Destructor virtual
    virtual ~Simple();

    // Devuelve el tipo de camión 
    String getTipo();

    // Calcula la capacidad anual de volumen que este camión puede transportar.
    float calcularCapacidadAnualDeVolumen();
};

#endif // SIMPLE_H_INCLUDED