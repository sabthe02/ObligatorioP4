#include "Fachada.h"

// Constructor por defecto de la clase Fachada
// Inicializa los diccionarios de camiones (dicH) y camioneros (dicA).
Fachada :: Fachada() : dicA (), dicH ()
{

}
// Requerimiento 1:
// Registro de un nuevo camión dados sus datos y la cédula del camionero que lo maneja.
// Se debe chequear que no exista otro camión con la misma matrícula.
// También se verifica que el camionero con la cédula proporcionada esté registrado.
// Si todo es correcto, se asocia el camionero al camión y se registra.
void Fachada :: RegistroNuevoCamion(Camion * camion, int ciCamionero, Errores& err)
{

    if(!dicA.Empty())
    {
        if (dicA.Member(ciCamionero)) {
            Camionero * cam = dicA.Find(ciCamionero);
                if(!dicH.Member(camion->getMatricula()))
                {
                    camion -> setCamionero(cam);
                    dicH.Insert(camion);
                    err = NINGUNO;
                }
                else
                {
                    err = CAMION_EXISTE;
                }
            }
            else {
                err = CAMIONERO_NO_EXISTE;

            }
    }else{
        err = CAMIONEROS_VACIO;
    }



}

// Requerimiento 2:
// Listado básico de todos los camiones que esan registrados.
// lo que hace es devolver un iterador con los datos de los camiones
iterador Fachada :: ListadoBasicoCamiones ()
{
    iterador it;

    dicH.listarCamiones(it); // Llama al método para listar camiones.

    return it;
}

// Requerimiento 3:
// Listado detallado de un camión
// También lista los datos del camionero asociado y la cantidad de metros cúbicos anuales transportados.
// Si el camión no existe, emite un mensaje de error.
Camion * Fachada :: ListadoDetalladoCamion(String matricula, Errores &err)
{
    Camion * cam;

    if(dicH.Member(matricula))
    {
        Camion * aux  = dicH.Find(matricula);

        if((aux)->getTipo() == "Simple")
        {
            cam = new Simple(*((Simple *)aux));

        }
        else if ((aux)->getTipo() == "ConRemolque")
        {
            cam = new ConRemolque(*((ConRemolque *)aux));
        }
        else
        {
            cam = new Grande(*((Grande *)aux));
        }
        cam->setCamionero(new Camionero(*(aux->getCamionero())));

        err = NINGUNO;
    }
    else
    {
        err = CAMION_NO_EXISTE;
    }

    return cam;
}

// Requerimiento 4:
// Registro de un nuevo camionero 
// Se debe chequear que no exista otro camionero con la misma cédula.
// En caso de error, emite un mensaje indicando que ya existe.
void Fachada :: AgregarCamionero(Camionero c, Errores& err)
{
    if(!dicA.Member(c.getCedula()))
    {
        dicA.Insert(c);

        err = NINGUNO;

    }
    else
    {
        err = CAMIONERO_EXISTE;
    }
}

// Requerimiento 5:
// Listado de todos los camioneros registrados ordenados por cédula de menor a mayor.
// O sea devuelve un iterador con los datos
iterador Fachada :: ListarCamioneros()
{
    iterador it;

    dicA.listarCamioneros(it);

    return it; // Retorna el iterador que ahora contiene la lista de camioneros.
}

// Requerimiento 6:
// Calcular la cantidad de metros cúbicos anuales que la flota es capaz de transportar.
// Lo que hace es retornar la suma de todas las capacidades anuales de los camiones registrados.
float Fachada :: CantidadCubicosAnuales()
{
    return dicH.capacidadAnualFlota();
}

/// Requerimiento 7:
// Modificar la cantidad de viajes anuales de un camión dada su matrícula.
// Si el camión no existe, se asigna un error.
void Fachada :: ModificarCantidadViajesAnuales(String matricula, int &nuevosViajes, Errores&err)
{
    err = NINGUNO;
    if (!dicH.Member(matricula))
        err = CAMION_NO_EXISTE;
    else
    {
        Camion * c = dicH.Find(matricula);
        c->setCantViajesAnuales(nuevosViajes);
    }
}

// Requerimiento 8:
// Obtener la cantidad de camiones por tipo 
// Lo que hace es retornar las cantidades separadas por tipo.
void Fachada :: ObtenerCantidadDeCadaTipoDeCamion(int &cantidadSimples, int &cantidadGrandes, int &cantidadConRemolque)
{
    cantidadSimples = 0;
    cantidadGrandes = 0;
    cantidadConRemolque = 0;
    dicH.cantidadEnFlota(cantidadSimples, cantidadGrandes, cantidadConRemolque);
}

// Requerimiento 9:
// Listar los datos del camionero con mayor cantidad de tatuajes registrados.
void Fachada::ListarCamioneroConMasTatuajes(Camionero * &camioneroConMasTatuajes, Errores &err)
{
    err = NINGUNO;
    camioneroConMasTatuajes = NULL;

    if (dicA.Empty())
    {
        err = CAMIONEROS_NO_REGISTRADOS;
    }
    else
    {
        camioneroConMasTatuajes = new Camionero(dicA.MayorCantTatuajes());
    }
}

// Requerimiento 10:
// Contar cuántos camiones grandes hay registrados donde la fecha de adquisición es posterior a una fecha dada.
// Si no hay camiones registrados, emite un mensaje de error.
int Fachada :: RegistradosGrandesPosteriorAFecha(Fecha fecha, Errores &err)
{
    int cantidad = 0;

    // Verifica si NO hay camiones registrados
    if (dicH.Empty())
    {
        err = CAMIONES_NO_REGISTRADOS;
    }
    else
    {
        // Si hay camiones, cuenta cuántos grandes hay después de la fecha
        err = NINGUNO;
        cantidad = dicH.contarCamionesGrandesPostFecha(fecha);
    }

    return cantidad;
}
