#ifndef CAMION_H_INCLUDED
#define CAMION_H_INCLUDED

#include "Camionero.h"
#include "Str.h"
#include "Objeto.h"

class Camion: public Objeto{

private:
    String Matricula;          // Matricula del camión.
    String Marca;              // Marca del camión.
    int CantViajesAnuales;     // Cantidad de viajes anuales realizados por el camión.
    Camionero * Cam;           // Puntero al camionero asignado.

public:
    // Constructor por defecto.
    Camion();

    // Constructor que inicializa el camión con matrícula, marca y cantidad de viajes anuales.
    Camion(String, String, int);

    // Constructor que inicializa el camión con matrícula, marca, cantidad de viajes y camionero asignado.
    Camion(String, String, int, Camionero*);

    // Constructor de copia.
    Camion(const Camion&);

    // Devuelve la matrícula del camión.
    String getMatricula();

    // Devuelve la marca del camión.
    String getMarca();

    // Devuelve la cantidad de viajes anuales realizados por el camión.
    int getCantViajesAnuales();

    // Devuelve el camionero asignado al camión.
    Camionero* getCamionero();

    // Asigna la marca del camión.
    void setMarca(String);

    // Asigna la cantidad de viajes anuales realizados por el camión.
    void setCantViajesAnuales(int);

    // Asigna un camionero al camión.
    void setCamionero(Camionero*);

    // Destructor.
    virtual ~Camion();

    // Método virtual para obtener el tipo de camión.
    virtual String getTipo() = 0;

    // Método virtual  para calcular la capacidad anual de volumen que puede transportar.
    virtual float calcularCapacidadAnualDeVolumen() = 0;
};

#endif // CAMION_H_INCLUDED