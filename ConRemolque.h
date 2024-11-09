#ifndef CONREMOLQUE_H_INCLUDED
#define CONREMOLQUE_H_INCLUDED

#include "Grande.h"

class ConRemolque: public Grande{

private:
    float capRemolque;

public:
    ConRemolque();
    ConRemolque (String, String, int, float, Fecha, float);
    ConRemolque (String, String, int, Camionero *, float, Fecha, float);
    ConRemolque(const ConRemolque&);

    float getCapRemolque();
    void setCapRemolque(float);

    virtual ~ConRemolque ();
    float calcularCapacidadAnualDeVolumen();

    String getTipo();

};


#endif // CONREMOLQUE_H_INCLUDED
