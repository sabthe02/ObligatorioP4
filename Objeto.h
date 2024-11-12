#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED

#include "Str.h"

class Objeto{

private:

public:
    Objeto();
    virtual ~Objeto();
    virtual String getTipo() = 0;

};


#endif // OBJETO_H_INCLUDED
