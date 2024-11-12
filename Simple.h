#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include "Camion.h"
#include "Str.h"

class Simple: public Camion{

private:
    String depto;

public:

    Simple();
    Simple(String, String, int, String);
    Simple(String, String, int, Camionero *, String);
    Simple (const Simple&);

    String getDepto();
    void setDepto(String);

    virtual ~Simple ();

    String getTipo();
    float calcularCapacidadAnualDeVolumen();

};


#endif // SIMPLE_H_INCLUDED
