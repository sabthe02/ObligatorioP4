#include <stdio.h>

#include "Fachada.h"
#include "Iterador.h"
#include "Simple.h"

int cantAgregado = 1;

void imprimirMenu()
{
    printf(" *****  MENU PRINCIPAL **** \n\n");
    printf("\n 1 - Registrar un nuevo camion. ");
    printf("\n 2 - Listado basico de todos los camiones. ");
    printf("\n 3 - Listado detallado de un camion. ");
    printf("\n 4 - Registrar un nuevo camionero. ");
    printf("\n 5 - Listado de todos los camioneros registrados. ");
    printf("\n 6 - Cantidad de metros c�bicos anuales que se pueden transportar. ");
    printf("\n 7 - Modificar cantidad de viajes anuales que puede transportar un camion. ");
    printf("\n 8 - Cantidad de camiones por tipo. ");
    printf("\n 9 - Datos del camionero con mas tatuajes. ");
    printf("\n 10 - Cantidad de camiones grandes registrados posterior a una fecha. ");
    printf("\n\n 99 - Salir. ");


    printf("\n\n\nIngrese la opcion elegida: ");
}

void opcion1(Fachada &fac)
{
    int CiCamionero = 1, cantViajesAnuales = 1;
    String matricula, marca;
    char opcion = 'm';
    Errores err;

    printf("Ingrese la matricula del camion: ");
    matricula.scan();

    printf("Ingrese la marca del camion: ");
    marca.scan();
    marca.print();

    printf("Ingrese la cantidad de viajes anuales: ");
    scanf("%d", &cantViajesAnuales);

    printf("Ingrese la CI del camionero: ");
    scanf("%d", &CiCamionero);

    do
    {
        printf("Ingrese 's' si el camionero es simple o 'g' si es grande: ");
        fflush(stdin);
        scanf("%c", &opcion);

        if(opcion != 's' && opcion != 'g')
        {
            printf("La opcion ingresada no es valida.");
        }
    }
    while(opcion != 's' && opcion != 'g');

    if(opcion == 's')
    {
        String depto;

        printf("Ingrese el departamento: ");
        depto.scan();

        Simple * camSimple = new Simple(matricula, marca, cantViajesAnuales, depto);
        fac.RegistroNuevoCamion(camSimple, CiCamionero, err);
    }
    else
    {
        int volumen, dia, mes, anio;

        Fecha fec;

        printf("Ingrese el volumen del camion: ");
        scanf("%d", &volumen);

        printf("Ingrese el dia de la fecha de adquirido: ");
        scanf("%d", &dia);
        printf("Ingrese el mes de la fecha de adquirido: ");
        scanf("%d", &mes);
        printf("Ingrese el anio de la fecha de adquirido: ");
        scanf("%d", &anio);

        fec = Fecha(dia, mes, anio);

        do
        {
            printf("Ingrese 'g' si el camionero es grande o 'r' si es Con Remolque: ");
            fflush(stdin);
            scanf("%c", &opcion);

            if(opcion != 'g' && opcion != 'r')
            {
                printf("La opcion ingresada no es valida.");
            }
        }
        while(opcion != 'g' && opcion != 'r');

        if(opcion == 'g')
        {
            Grande * gr = new Grande(matricula, marca, cantViajesAnuales, volumen, fec);
            fac.RegistroNuevoCamion(gr, CiCamionero, err);
        }else{

            int capRem;

            printf("Ingrese la capacidad del remolque: ");
            fflush(stdin);
            scanf("%d", &capRem);

            ConRemolque * cr = new ConRemolque(matricula, marca, cantViajesAnuales, volumen, fec, capRem);
            fac.RegistroNuevoCamion(cr, CiCamionero, err);
        }
    }

    switch(err)
    {
    case NINGUNO:
        printf("Se agrego el camion correctamente.");
        break;
    case CAMION_EXISTE:
        printf("Ya existe un camion registrado con esa matricula.");
        break;

    case CAMIONERO_NO_EXISTE:
        printf("No existe ningun camionero con la CI indicada.");
        break;
    }
}

void opcion1_automat(Fachada &fac)
{
    int CiCamionero = 1, cantViajesAnuales = 10;
    String matricula = "AAB1412", marca = "Volvo", depto = "Canelones";

    Simple * camSimp = new Simple(matricula, marca, cantViajesAnuales, depto);

    Errores err;

    fac.RegistroNuevoCamion(camSimp, CiCamionero, err);

    switch(err)
    {
    case NINGUNO:
        printf("Se agrego el camion correctamente.");
        break;
    case CAMION_EXISTE:
        printf("Ya existe un camion registrado con esa matricula.");
        break;

    case CAMIONERO_NO_EXISTE:
        printf("No existe ningun camionero con la CI indicada.");
        break;
    }
}

void opcion2(Fachada &fac)
{
    printf("\n\n *** Listado Basico de Camiones *** \n\n");

    iterador it = fac.ListadoBasicoCamiones();

    while(it.hayMasObjetos())
    {
        Objeto* o = it.proximoObjeto();
        printf("\nMatricula: ");
        ((Camion *)o)->getMatricula().print();
        printf(" Marca: ");
        ((Camion *)o)->getMarca().print();
        printf(" Cantidad Viajes Anuales: %d", ((Camion *)o)->getCantViajesAnuales());
        printf(" Tipo de Camion: ");
        ((Camion *)o)->getTipo().print();
    }

    printf("\n\n\n");
}
void opcion3(Fachada &fac)
{

    ///Listado detallado de un camión. Dada la matrícula del camión, listar todos sus datos.
    ///También se deben listar los datos del camionero que lo maneja y la cantidad de metros cúbicos
    ///anuales que es capaz de transportar. En caso de que el camión no exista, se debe emitir un mensaje de error.


    printf("\n\n *** Listado Detallado de Camiones *** \n\n");

    iterador it = fac.ListadoBasicoCamiones();

    while(it.hayMasObjetos())
    {
        Objeto* o = it.proximoObjeto();
        printf("\nMatricula: ");
        ((Camion *)o)->getMatricula().print();
        printf("\n  Marca: ");
        ((Camion *)o)->getMarca().print();
        printf("\n  Cantidad Viajes Anuales: %d", ((Camion *)o)->getCantViajesAnuales());
        printf("\n  Tipo de Camion: ");
        ((Camion *)o)->getTipo().print();
        printf("\n  Cantidad m3 anuales: %f", ((Camion *)o)->calcularCapacidadAnualDeVolumen());


        if(((Camion *)o)->getTipo() == "Simple")
        {
            printf("\n  Departamento: ");
            ((Simple *)o)->getDepto().print();
        }else
        {
            printf("\n  Volumen: %d", ((Grande *)o)->getVolumen());
            printf("\n  Fecha Adquirido: %d/%d/%d", ((Grande *)o)->getFechaAdquirida().getDia(), ((Grande *)o)->getFechaAdquirida().getMes(), ((Grande *)o)->getFechaAdquirida().getAnio());

            if(((Camion *)o)->getTipo() == "ConRemolque")
            {
                printf("\n  Capacidad Remolque: %d", ((ConRemolque *)o)->getCapRemolque());

            }
        }

        printf("\n  Datos Conductor: ");

        printf("\n    CI: %d", ((Camion *)o)->getCamionero()->getCedula());
        printf("\n    Nombre: ");
        ((Camion *)o)->getCamionero()->getNombre().print();
        printf("\n    Cantidad tatuajes: %d", ((Camion *)o)->getCamionero()->getCantTatuajes());
        printf("\n    Fecha Nacimiento: %d/%d/%d", ((Camion *)o)->getCamionero()->getFechaNacimiento().getDia(), ((Camion *)o)->getCamionero()->getFechaNacimiento().getMes(), ((Camion *)o)->getCamionero()->getFechaNacimiento().getAnio());


        printf("\n\n");
    }

    printf("\n\n\n");
}
void opcion4(Fachada &fac)
{
    int CI, cantTatuajes, dia, mes, anio;
    String nombre;
    Fecha fec_nac;

    printf("Ingrese la CI: ");
    scanf("%d", &CI);

    printf("Ingrese el nombre: ");
    nombre.scan();

    printf("Ingrese la cantidad de tatuajes: ");
    scanf("%d", &cantTatuajes);

    printf("Ingrese el dia de nacimiento: ");
    scanf("%d", &dia);
    printf("Ingrese el mes de nacimiento: ");
    scanf("%d", &mes);
    printf("Ingrese el anio de nacimiento: ");
    scanf("%d", &anio);

    Fecha f(dia, mes, anio);
    Camionero cam(CI, nombre, cantTatuajes, f);
    Errores e;

    fac.AgregarCamionero(cam, e);

    if(e == NINGUNO)
    {
        printf("Se agrego el camionero con exito.");
    }
    else if(e == CAMIONERO_EXISTE)
    {
        printf("Ya existe un camionero con esa CI.");
    }

}

void opcion4_automat(Fachada &fac)
{
    int ci, cantTatuajes, dia, mes, anio;
    String nombre;
    Fecha fec_nac;

    ci = cantAgregado;
    cantAgregado++;

    Fecha f(1, 1, 1);
    Camionero cam(ci, "usr", 10+ci, f);
    Errores e;

    fac.AgregarCamionero(cam, e);

    if(e == NINGUNO)
    {
        printf("Se agrego el camionero con exito.\n\n");
    }
    else if(e == CAMIONERO_EXISTE)
    {
        printf("Ya existe un camionero con esa CI.\n\n");
    }

}
void opcion5(Fachada &fac)
{
    printf("\n\n *** Listado de Camioneros *** \n\n");

    iterador it = fac.ListarCamioneros();

    while(it.hayMasObjetos())
    {
        Objeto* o = it.proximoObjeto();
        printf("\nCI: %d", ((Camionero *)o)->getCedula());
        printf(" Nombre: ");
        ((Camionero *)o)->getNombre().print();
        printf(" Cantidad de Tatuajes: %d", ((Camionero *)o)->getCantTatuajes());
        Fecha f = ((Camionero *)o)->getFechaNacimiento();
        printf(" Fecha de Nacimiento: %d/%d/%d", f.getDia(), f.getMes(), f.getAnio());
    }

    printf("\n\n\n");

}
void opcion6(Fachada &fac)
{
    float volumenTotal = fac.CantidadCubicosAnuales();
    printf("La cantidad de metros cúbicos anuales que se pueden transportar es: %.2f\n", volumenTotal);
}
void opcion7(Fachada &fac)
{

    String matricula;
    int nuevosViajes;
    Errores err;

    printf("Ingrese la matrícula del camión: ");
    matricula.scan();

    printf("Ingrese la nueva cantidad de viajes anuales: ");
    scanf("%d", &nuevosViajes);

    fac.ModificarCantidadViajesAnuales(matricula, nuevosViajes, err);

    if (err == NINGUNO)
    {
        printf("Cantidad de viajes modificada correctamente.\n");
    }
    else if (err == CAMION_NO_EXISTE)
    {
        printf("No existe un camión con esa matrícula.\n");
    }


}
void opcion8(Fachada &fac)
{
    int cantidadSimples = 0, cantidadGrandes = 0, cantidadTotal = 0;

    fac.ObtenerCantidadDeCadaTipoDeCamion(cantidadSimples, cantidadGrandes, cantidadTotal);

    printf("Cantidad de camiones simples: %d\n", cantidadSimples);
    printf("Cantidad de camiones grandes: %d\n", cantidadGrandes);
    printf("Cantidad total de camiones: %d\n", cantidadTotal);

}
void opcion9(Fachada &fac)
{
    Errores err;
    Camionero camionero = fac.ListarCamioneroConMasTatuajes(err);

    if (err == NINGUNO)
    {
        printf("CI: %d\n", camionero.getCedula());
        printf("Nombre: ");
        camionero.getNombre().print();
        printf("Cantidad de tatuajes: %d\n", camionero.getCantTatuajes());
        Fecha f = camionero.getFechaNacimiento();
        printf("Fecha de nacimiento: %d/%d/%d\n", f.getDia(), f.getMes(), f.getAnio());
    }
    else
    {
        printf("No se encontró ningún camionero.\n");
    }

}
void opcion10(Fachada &fac)
{
    int dia, mes, anio;
    Errores err;

    printf("Ingrese el día: ");
    scanf("%d", &dia);
    printf("Ingrese el mes: ");
    scanf("%d", &mes);
    printf("Ingrese el año: ");
    scanf("%d", &anio);

    Fecha fecha(dia, mes, anio);
    int cantidad = fac.RegistradosGrandesPosteriorAFecha(fecha, err);

    if (err == NINGUNO)
    {
        printf("Cantidad de camiones grandes registrados después de la fecha ingresada: %d\n", cantidad);
    }
    else
    {
        printf("Error al realizar la consulta.\n");
    }

}

int main()
{

    Fachada fachada;

    int opcionElegida = 0;


    ///A efectos de prueba
    for(int i = 0; i<10; i++)
    {
        opcion4_automat(fachada);
        opcion1_automat(fachada);
    }

    do
    {
        imprimirMenu();
        scanf("%d", &opcionElegida);

        switch(opcionElegida)
        {

        case 1:
        {
            opcion1(fachada);
            break;
        }
        case 2:
        {
            opcion2(fachada);
            break;
        }

        case 3:
        {
            opcion3(fachada);
            break;
        }
        case 4:
        {
            opcion4(fachada);
            break;
        }
        case 5:
        {
            opcion5(fachada);
            break;
        }
        case 6:
        {
            opcion6(fachada);
            break;
        }
        case 7:
        {
            opcion7(fachada);
            break;
        }
        case 8:
        {
            opcion8(fachada);
            break;
        }
        case 9:
        {
            opcion9(fachada);
            break;
        }
        case 10:
        {
            opcion1(fachada);
            break;
        }
        case 99:
            printf("\nSaliendo...");
            break;
        default:
            printf("La opcion ingresada no es valida. \n\n");
            break;

        }

    }
    while(opcionElegida != 99);
}
