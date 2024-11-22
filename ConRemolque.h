#ifndef CONREMOLQUE_H_INCLUDED
#define CONREMOLQUE_H_INCLUDED

#include "Grande.h"

class ConRemolque: public Grande{

private:
    float capRemolque;      // Capacidad adicional del remolque en metros cúbicos.

public:
    // Constructor por defecto.
    ConRemolque();

    // Constructor que inicializa los atributos del camión con remolque.
    ConRemolque(String matricula, String marca, int cantViajesAnuales, 
                float capacidadGrande, Fecha ultimaRevision, float capacidadRemolque);

    // Constructor que inicializa el camión con remolque y un camionero asignado.
    ConRemolque(String matricula, String marca, int cantViajesAnuales, 
                Camionero* camionero, float capacidadGrande, Fecha ultimaRevision, float capacidadRemolque);

    // Constructor de copia.
    ConRemolque(const ConRemolque&);

    // Obtiene la capacidad del remolque.
    float getCapRemolque();

    // Asigna un valor a la capacidad del remolque.
    void setCapRemolque(float capacidadRemolque);

    // Destructor.
    virtual ~ConRemolque();

    // Calcula la capacidad anual de volumen del camión con remolque.
    float calcularCapacidadAnualDeVolumen();

    // Devuelve el tipo del camión 
    String getTipo();
};

#endif // CONREMOLQUE_H_INCLUDED