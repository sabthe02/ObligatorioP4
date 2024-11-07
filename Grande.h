#ifndef GRANDE_H_INCLUDED
#define GRANDE_H_INCLUDED

#include "Camion.h"
#include "Str.h"
#include "Fecha.h"

class Grande:  Camion{

private:
    float Volumen;
    Fecha FechaAdquirido;

public:
    Grande();
    Grande(String, String, int, Camionero *, float, Fecha);
    Grande(String, String, int, float, Fecha);
    float getVolumen();
    Fecha getFechaAdquirida();
    void setVolumen(float);
    void setFechaAdquirido(Fecha);

    virtual ~Grande ();

    String getTipo();
};


#endif // GRANDE_H_INCLUDED
