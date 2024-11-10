#include "Fachada.h"


Fachada :: Fachada()
{

}
//
//void Fachada :: RegistroNuevoCamion(Camion, int, Errores&)
//{
//
//}
//iterador Fachada :: ListadoBasicoCamiones ()
//{
//
//}
//Camion Fachada :: ListadoDetalladoCamion(String, Errores&)
//{
//
//}
void Fachada :: AgregarCamionero(Camionero c, Errores& err)
{
    if(!dicA.Member(c.getCedula()))
    {
        dicA.Insert(c);

        err = NINGUNO;

    }else
    {
        err = CAMIONERO_EXISTE;
    }
}

iterador Fachada :: ListarCamioneros()
{
    iterador it;



    dicA.listarCamioneros(it);

    return it;
}
//float Fachada :: CantidadCubicosAnuales()
//{
//
//}
//void Fachada :: ModificarCantidadViajesAnuales(String, int&, Errores&)
//{
//
//}
//void Fachada :: ObtenerCantidadDeCadaTipoDeCamion(int&, int&, int&)
//{
//
//}
//Camionero Fachada :: ListarCamioneroConMasTatuajes(Errores&)
//{
//
//}
//int Fachada :: RegistradosGrandesPosteriorAFecha(Fecha, Errores&)
//{
//
//}
