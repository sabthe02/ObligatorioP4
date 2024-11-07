#ifndef CONREMOLQUE_H_INCLUDED
#define CONREMOLQUE_H_INCLUDED

#include "Grande.h"

class ConRemolque: Grande{

private:
    float capRemolque;
public:

    ConRemolque();
    ConRemolque (String, String, int, float, Fecha, float);
    ConRemolque (String, String, int, Camionero *, float, Fecha, float);
    float getCapRemolque();
    void setCapRemolque(float);

    virtual ~ConRemolque ();


    String getTipo();

};


#endif // CONREMOLQUE_H_INCLUDED
