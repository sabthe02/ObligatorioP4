#ifndef CAMION_H_INCLUDED
#define CAMION_H_INCLUDED

#include "Camionero.h"
#include "Str.h"
#include "Objeto.h"

class Camion: public Objeto{

private:

    String Matricula;
    String Marca;
    int CantViajesAnuales;
    Camionero * Cam;

public:

    Camion ();
    Camion (String, String, int);
    Camion (String, String, int, Camionero *);
    Camion (const Camion&);

    String getMatricula();
    String getMarca();
    int getCantViajesAnuales();
    Camionero * getCamionero();

    void setMarca (String);
    void setCantViajesAnuales(int);
    void setCamionero(Camionero *);

    virtual ~Camion ();

    virtual String getTipo() = 0;
    virtual float calcularCapacidadAnualDeVolumen() = 0;

};


#endif // CAMION_H_INCLUDED
