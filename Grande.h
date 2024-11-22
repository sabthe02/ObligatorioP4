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
    // Constructor por defecto
    Grande();

    // Constructor que inicializa un camión grande con un camionero asignado.
    Grande(String, String, int, Camionero *, float, Fecha);

    // Constructor que inicializa un camión grande sin un camionero asignado.
    Grande(String, String, int, float, Fecha);

    // Constructor de copia
    Grande(const Grande&);

    // Devuelve el volumen de carga del camión.
    float getVolumen();

    // Devuelve la fecha de adquisición del camión.
    Fecha getFechaAdquirida();

    // Establece el volumen de carga del camión.
    void setVolumen(float);

    // Establece la fecha de adquisición del camión.
    void setFechaAdquirido(Fecha);

    // Destructor
    virtual ~Grande();

    // Devuelve el tipo de camión
    String getTipo();

    // Calcula la capacidad total anual de volumen de carga del camión.
    // Retorna el volumen total transportable en un año.
    float calcularCapacidadAnualDeVolumen();
};

#endif // GRANDE_H_INCLUDED