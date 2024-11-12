#ifndef GRANDE_H_INCLUDED
#define GRANDE_H_INCLUDED

#include "Camion.h"
#include "Str.h"
#include "Fecha.h"

class Grande:  public Camion{

private:
    float Volumen;
    Fecha FechaAdquirido;

public:
    Grande();
    Grande(String, String, int, Camionero *, float, Fecha);
    Grande(String, String, int, float, Fecha);
    Grande(const Grande&);

    float getVolumen();
    Fecha getFechaAdquirida();
    void setVolumen(float);
    void setFechaAdquirido(Fecha);

    virtual ~Grande ();

    String getTipo();
    float calcularCapacidadAnualDeVolumen();
};


#endif // GRANDE_H_INCLUDED
