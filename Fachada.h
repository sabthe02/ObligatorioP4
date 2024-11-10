#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED

#include "Camioneros.h"
#include "Camiones.h"
#include "Iterador.h"
#include "Errores.h"

class Fachada{

private:

    Camioneros dicA;
    Camiones dicH;
public:

    Fachada();

//    void RegistroNuevoCamion(Camion, int, Errores&);
//    iterador ListadoBasicoCamiones ();
//    Camion ListadoDetalladoCamion(String, Errores&);
    void AgregarCamionero(Camionero, Errores&);
    iterador ListarCamioneros();
//    float CantidadCubicosAnuales();
//    void ModificarCantidadViajesAnuales(String, int&, Errores&);
//    void ObtenerCantidadDeCadaTipoDeCamion(int&, int&, int&);
//    Camionero ListarCamioneroConMasTatuajes(Errores&);
//    int RegistradosGrandesPosteriorAFecha(Fecha, Errores&);


};


#endif // FACHADA_H_INCLUDED
