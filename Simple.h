#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include "Camion.h"
#include "Str.h"

class Simple: Camion{

public:
    String depto;

private:

    Simple();
    Simple(String, String, int, String);
    Simple(String, String, int, Camionero *, String);
    String getDepto();
    void setDepto(String);

    virtual ~Simple ();

    String getTipo();

};


#endif // SIMPLE_H_INCLUDED
