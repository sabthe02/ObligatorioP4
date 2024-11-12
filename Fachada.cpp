#include "Fachada.h"


Fachada :: Fachada()
{

}

void Fachada :: RegistroNuevoCamion(Camion * camion, int ciCamionero, Errores& err)
{

    if(dicA.Member(ciCamionero))
    {
        if(!dicH.Member(camion->getMatricula()))
        {
            camion -> setCamionero(dicA.Find(ciCamionero));
            dicH.Insert(camion);
            err = NINGUNO;
        }else{
            err = CAMION_EXISTE;
        }
    }else{
        err = CAMIONERO_NO_EXISTE;
    }

}
iterador Fachada :: ListadoBasicoCamiones ()
{
    iterador it;

    dicH.listarCamiones(it);

    return it;
}
Camion * Fachada :: ListadoDetalladoCamion(String, Errores&)
{

}
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
float Fachada :: CantidadCubicosAnuales()
{
    return dicH.capacidadAnualFlota();
}
void Fachada :: ModificarCantidadViajesAnuales(String, int&, Errores&)
{

}
void Fachada :: ObtenerCantidadDeCadaTipoDeCamion(int&, int&, int&)
{

}
Camionero Fachada :: ListarCamioneroConMasTatuajes(Errores&)
{

}
int Fachada :: RegistradosGrandesPosteriorAFecha(Fecha, Errores&)
{

}
