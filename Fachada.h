#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED

#include "Camioneros.h"
#include "Camiones.h"
#include "Errores.h"
#include "Iterador.h"

class Fachada{

private:

   private:
    Camioneros dicA; // ABB que contiene los camioneros registrados.
    Camiones dicH;   // Tabla hash que contiene los camiones registrados.

public:

    // Constructor
    Fachada();

    // Registra un nuevo camión en el sistema.
    void RegistroNuevoCamion(Camion *, int, Errores&);

    // Devuelve un iterador con la lista básica de todos los camiones registrados.
    iterador ListadoBasicoCamiones();

    // Obtiene el detalle de un camión específico.
    Camion * ListadoDetalladoCamion(String, Errores&);

    // Agrega un nuevo camionero al sistema.
    void AgregarCamionero(Camionero, Errores&);

    // Devuelve un iterador con la lista de todos los camioneros registrados.
    iterador ListarCamioneros();

    // Calcula la capacidad total anual de volumen de carga de todos los camiones.
    // Retorna la capacidad total en metros cúbicos.
    float CantidadCubicosAnuales();

    // Modifica la cantidad de viajes anuales que puede realizar un camión.
    void ModificarCantidadViajesAnuales(String, int&, Errores&);

    // Obtiene la cantidad de camiones de cada tipo.
    void ObtenerCantidadDeCadaTipoDeCamion(int&, int&, int&);

    // Encuentra el camionero con más tatuajes.
    void ListarCamioneroConMasTatuajes(Camionero *& camioneroConMasTatuajes, Errores&);

    // Cuenta la cantidad de camiones grandes registrados después de una fecha específica.
    int RegistradosGrandesPosteriorAFecha(Fecha, Errores&);
};

#endif // FACHADA_H_INCLUDED