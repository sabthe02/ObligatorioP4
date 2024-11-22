#include <stdio.h>

#include "Fachada.h"
#include "Iterador.h"
#include <stdlib.h> // para usar colores

#define GREEN "\033[32m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define BLUE "\033[1;34m"
#define RESET "\x1b[0m"

int cantAgregado = 1;

void mostrarMensajeError(Errores err) // Muestra mensaje de error correspondiente al error (enum)
{
    switch (err)
    {
    case NINGUNO:
        printf(GREEN "Operacion realizada correctamente.\n" RESET);
        break;

    case CAMION_EXISTE:
        printf(RED "Ya existe un camion registrado con esa matricula.\n" RESET);
        break;

    case CAMION_NO_EXISTE:
        printf(RED "El camion indicado no existe.\n" RESET);
        break;

    case CAMIONERO_NO_EXISTE:
        printf(RED "No existe ningun camionero con la CI indicada.\n" RESET);
        break;

    case CAMIONERO_EXISTE:
        printf(RED "Ya existe un camionero con esa CI.\n" RESET);
        break;

    case CAMIONES_NO_REGISTRADOS:
        printf(RED "No hay camiones registrados en el sistema.\n" RESET);
        break;

    case CAMIONEROS_NO_REGISTRADOS:
        printf(RED "No hay camioneros registrados en el sistema.\n" RESET);
        break;

    case CAMIONEROS_VACIO:
        printf(RED "No hay camioneros registrados.\n" RESET);
        break;

    default:
        printf(RED "Ha ocurrido un error desconocido.\n" RESET);
        break;
    }
}


void imprimirMenu() // Muestra el menú
{
    printf(MAGENTA "\n *****  MENU PRINCIPAL **** \n\n " RESET);
    printf( "\n 1 - Registrar un nuevo camion. ");
    printf( "\n 2 - Listado basico de todos los camiones. ");
    printf( "\n 3 - Listado detallado de un camion. ");
    printf( "\n 4 - Registrar un nuevo camionero. ");
    printf( "\n 5 - Listado de todos los camioneros registrados. ");
    printf( "\n 6 - Cantidad de metros cubicos anuales que se pueden transportar. ");
    printf( "\n 7 - Modificar cantidad de viajes anuales que puede transportar un camion. ");
    printf( "\n 8 - Cantidad de camiones por tipo. ");
    printf( "\n 9 - Datos del camionero con mas tatuajes. ");
    printf( "\n 10 - Cantidad de camiones grandes registrados posterior a una fecha. ");
    printf( "\n 11 - Cargar datos de prueba. ");

    printf( "\n\n 99 - Salir. ");

    printf(MAGENTA "\n\n\nIngrese la opcion elegida, por favor solo ingresar numeros: " RESET);
}

void opcion1(Fachada &fac) // Agrega un camión
{
    printf(BLUE " \n\n *** Registrar un nuevo camion *** \n\n" RESET);

    int CiCamionero = 1, cantViajesAnuales = 1;
    String matricula, marca;
    char opcion = 'm';
    Errores err;

    do
    {
        printf("Ingrese la matricula del camion: ");
        matricula.scan();
        if (matricula.largo() < 4) //Valida que la matrícula tengo al menos 4 caracteres
        {
            printf(RED "La matricula debe tener al menos 4 caracteres.\n" RESET);
        }
    } while (matricula.largo() < 4);


    printf("Ingrese la marca del camion: ");
    marca.scan();

    printf("Ingrese la cantidad de viajes anuales: ");
    scanf("%d", &cantViajesAnuales);
     do {
        printf("Ingrese la CI del camionero - solo ingresar numeros: ");
        scanf("%d", &CiCamionero);

            if (CiCamionero < 100000) // valida que la cédula tenga al menos 6 dígitos
            {
                printf(RED "La cedula debe tener al menos 6 digitos.\n" RESET);
            }
        } while (CiCamionero < 100000);

    do
    {
        printf("Ingrese 's' si el camion es simple o 'g' si es grande: ");
        fflush(stdin);
        scanf("%c", &opcion);

        if(opcion != 's' && opcion != 'g') // valida que se ingrese "s" o "g"
        {
            printf(RED "La opcion ingresada no es valida.\n" RESET);
        }
    }
    while(opcion != 's' && opcion != 'g');

    if(opcion == 's')
    {
        String depto;


        do
    {
        printf("Ingrese el departamento: ");
        depto.scan();
        if (depto.largo() < 3) // Valida que el departamento ingresado tenga al menos 3 caracteres
        {
            printf(RED "El departamento debe tener al menos 3 caracteres.\n" RESET);
        }
    } while (depto.largo() < 3);


        Simple * camSimple = new Simple(matricula, marca, cantViajesAnuales, depto);
        fac.RegistroNuevoCamion(camSimple, CiCamionero, err);

    }
    else
    {
        int volumen, dia, mes, anio;

        Fecha fec;

  do
    {
        printf("Ingrese el volumen del camion: ");
        scanf("%d", &volumen);

        // Validación volumen mayor a 25
        if (volumen <= 25)
        {
            printf(RED "\nEl volumen del camion grande debe ser mayor a 25.\n\n" RESET);
        }
    }
    while (volumen <= 25);

        do
        {
            printf("Ingrese el dia de la fecha de adquirido: ");
            scanf("%d", &dia);
            printf("Ingrese el mes de la fecha de adquirido: ");
            scanf("%d", &mes);
            printf("Ingrese el anio de la fecha de adquirido: ");
            scanf("%d", &anio);

            fec = Fecha(dia, mes, anio);
            if(!fec.esValida()) // Valida que la fecha sea válida
            {
                printf(RED "La fecha ingresada no es valida. Ingresar nuevamente \n" RESET);
            }
        }
        while(!fec.esValida());

        do
        {
            printf("Ingrese 'g' si el camion es grande o 'r' si es Con Remolque: ");
            fflush(stdin);
            scanf("%c", &opcion);

            if(opcion != 'g' && opcion != 'r') // valida que se ingrese "g" o "r"
            {
                printf(RED "La opcion ingresada no es valida." RESET);
            }
        }
        while(opcion != 'g' && opcion != 'r');

        if(opcion == 'g')
        {
            Grande * gr = new Grande(matricula, marca, cantViajesAnuales, volumen, fec);
            fac.RegistroNuevoCamion(gr, CiCamionero, err);
        }
        else
        {
            int capRem;

            printf("Ingrese la capacidad del remolque: ");
            fflush(stdin);
            scanf("%d", &capRem);

            ConRemolque * cr = new ConRemolque(matricula, marca, cantViajesAnuales, volumen, fec, capRem);
            fac.RegistroNuevoCamion(cr, CiCamionero, err);
        }
    }

    if(err == NINGUNO)
    {
        printf(GREEN "\n Se agrego el camion correctamente" RESET "\n");
    }
    else
    {
        mostrarMensajeError(err);
    }

}

void opcion1_automat(Fachada &fac) // Procedimiento para carga automática de 4 nuevos camiones
{

    int CiCamionero = 1, cantViajesAnuales = 10;
    String matricula = "AAB1412", marca = "Volvo", depto = "Canelones";

    Simple * camSimp = new Simple(matricula, marca, cantViajesAnuales, depto);

    Errores err;

    fac.RegistroNuevoCamion(camSimp, CiCamionero, err);

    Fecha f =Fecha(1,1,2010);
    Grande * gr = new Grande("AABGr", "Mercedes", 12, 10.4, f);
    fac.RegistroNuevoCamion(gr, CiCamionero, err);


    Fecha f1 =Fecha(1,1,2020);
    Grande * gr1 = new Grande("AABGr1", "Mercedes", 12, 10.4, f1);
    fac.RegistroNuevoCamion(gr1, CiCamionero, err);


    Fecha f2 =Fecha(1,1,2030);
    Grande * gr2 = new Grande("AABGr2", "Mercedes", 12, 10.4, f2);
    fac.RegistroNuevoCamion(gr2, CiCamionero, err);

    mostrarMensajeError(err);
}

void opcion2(Fachada &fac) // Listado básico de camiones
{
    printf(BLUE " \n\n *** Listado Basico de Camiones *** \n\n" RESET);

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
void opcion3(Fachada &fac) // Listado detallado de un camión, dada su matricula
{

    ///Listado detallado de un camión. Dada la matrícula del camión, listar todos sus datos.
    ///También se deben listar los datos del camionero que lo maneja y la cantidad de metros cúbicos
    ///anuales que es capaz de transportar. En caso de que el camión no exista, se debe emitir un mensaje de error.


    printf(BLUE "\n\n *** Listado Detallado de un camion *** \n\n" RESET);

    String matricula;

    Errores err;

    printf("Ingrese la matricula a buscar: ");
    matricula.scan();

    Camion * o = fac.ListadoDetalladoCamion(matricula, err);


    if(err == NINGUNO)
    {
        printf("\nMatricula: ");
        o->getMatricula().print();
        printf("\n  Marca: ");
        o->getMarca().print();
        printf("\n  Cantidad Viajes Anuales: %d", ((Camion *)o)->getCantViajesAnuales());
        printf("\n  Tipo de Camion: ");
        o->getTipo().print();
        printf("\n  Cantidad m3 anuales: %f", ((Camion *)o)->calcularCapacidadAnualDeVolumen());


        if(((Camion *)o)->getTipo() == "Simple")
        {
            printf("\n  Departamento: ");
            ((Simple *)o)->getDepto().print();
        }
        else
        {
            printf("\n  Volumen: %f", ((Grande *)o)->getVolumen());
            printf("\n  Fecha Adquirido: %d/%d/%d", ((Grande *)o)->getFechaAdquirida().getDia(), ((Grande *)o)->getFechaAdquirida().getMes(), ((Grande *)o)->getFechaAdquirida().getAnio());

            if(o->getTipo() == "ConRemolque")
            {
                printf("\n  Capacidad Remolque: %f", ((ConRemolque *)o)->getCapRemolque());

            }
        }

        printf("\n  Datos Conductor: ");

        printf("\n    CI: %d", ((Camion *)o)->getCamionero()->getCedula());
        printf("\n    Nombre: ");
        o->getCamionero()->getNombre().print();
        printf("\n    Cantidad tatuajes: %d", o->getCamionero()->getCantTatuajes());
        printf("\n    Fecha Nacimiento: %d/%d/%d", o->getCamionero()->getFechaNacimiento().getDia(), o->getCamionero()->getFechaNacimiento().getMes(), o->getCamionero()->getFechaNacimiento().getAnio());


        printf("\n\n");

        delete o->getCamionero();
        delete o;

    }
    else
    {
        mostrarMensajeError(err);
    }

    printf("\n\n\n");
}

void opcion4(Fachada &fac)
{
    printf(BLUE " \n\n *** Registrar un nuevo camionero *** \n\n" RESET);

    int CI, cantTatuajes, dia, mes, anio;
    String nombre;
    Fecha f;

     // Validación de la cédula (debe tener al menos 6 dígitos)
    do {
        printf("Ingrese la CI - solo ingresar numeros: ");
        scanf("%d", &CI);

        if (CI < 100000)
        {
            printf(RED "La cedula debe tener al menos 6 digitos.\n" RESET);
        }
    } while (CI < 100000);

    // Validación del nombre (debe tener al menos 3 caracteres)
    do {
        printf("Ingrese el nombre: ");
        nombre.scan();

        if (nombre.largo() < 3)
        {
            printf(RED "El nombre debe tener al menos 3 caracteres.\n" RESET);
        }
    } while (nombre.largo() < 3);


    printf("Ingrese la cantidad de tatuajes: ");
    scanf("%d", &cantTatuajes);

    do {
        printf("Ingrese el dia de nacimiento: ");
        scanf("%d", &dia);
        printf("Ingrese el mes de nacimiento: ");
        scanf("%d", &mes);
        printf("Ingrese el anio de nacimiento: ");
        scanf("%d", &anio);

        f = Fecha(dia, mes, anio);

        if (!f.esValida()) { // Validación de fecha
            printf(RED "La fecha ingresada no es valida. Ingresar nuevamente \n" RESET);
        }

    }  while(!f.esValida());

    Camionero cam(CI, nombre, cantTatuajes, f);
    Errores e;

    fac.AgregarCamionero(cam, e);

   if(e == NINGUNO)
    {
        printf(GREEN "\n Se agrego el camionero con exito. \n\n" RESET);
    }
    else
    {
        mostrarMensajeError(e);
    }
}

void opcion4_automat(Fachada &fac) // Procedimiento para carga automática del camionero
{
    int ci;
    String nombre;
    Fecha f;

    ci = cantAgregado;
    cantAgregado++;

    f = Fecha(1, 1, 1999);
    Camionero cam(ci, "usr", 10+ci, f);
    Errores e;

    fac.AgregarCamionero(cam, e);

    if(e == NINGUNO)
    {
        printf(GREEN "Se agrego el camionero con exito.\n\n" RESET);

    }
    else
    {
        mostrarMensajeError(e);
    }

}
void opcion5(Fachada &fac) // Listado de todos los camioneros
{
    printf(BLUE "\n\n *** Listado de Camioneros *** \n\n" RESET);

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
void opcion6(Fachada &fac) // Muestra la cantidad de metros cúbicos anuales de toda la flota
{
    printf(BLUE " \n\n *** Cantidad de metros cubicos anuales que se pueden transportar *** \n\n" RESET);

    float volumenTotal = fac.CantidadCubicosAnuales();
    printf("\n La cantidad de metros cubicos anuales que se pueden transportar es: %.2f\n", volumenTotal);
}

void opcion7(Fachada &fac) // Modificar la cantidad de viajes anuales de un camión dada su matrícula
{
    printf(BLUE " \n\n *** Modificar cantidad de viajes anuales que puede transportar un camion *** \n\n" RESET);

    String matricula;
    int nuevosViajes;
    Errores err;

    printf("Ingrese la matricula del camion: ");
    matricula.scan();

    printf("Ingrese la nueva cantidad de viajes anuales: ");
    scanf("%d", &nuevosViajes);

    fac.ModificarCantidadViajesAnuales(matricula, nuevosViajes, err);

    if (err == NINGUNO)
    {
        printf(GREEN "Cantidad de viajes modificada correctamente.\n" RESET);
    }
    else
    {
        mostrarMensajeError(err);
    }


}
void opcion8(Fachada &fac) // Mostrar cantidad de camiones por tipo (simple, grande, con remolque)
{
    printf(BLUE " \n\n *** Cantidad de camiones por tipo *** \n\n" RESET);

    int cantidadSimples = 0, cantidadGrandes = 0, cantidadTotal = 0;

    fac.ObtenerCantidadDeCadaTipoDeCamion(cantidadSimples, cantidadGrandes, cantidadTotal);

    printf("Cantidad de camiones simples: %d\n", cantidadSimples);
    printf("Cantidad de camiones grandes: %d\n", cantidadGrandes);
    printf("Cantidad de camiones con remolque: %d\n", cantidadTotal);

}

void opcion9(Fachada &fac) // Mostrar datos del camionero con más tatuajes
{
    printf(BLUE "\n\n ***** Camionero con mas tatuajes **** \n\n" RESET);

    Errores err;
    Camionero * camionero;
    fac.ListarCamioneroConMasTatuajes(camionero, err);

    if (err == NINGUNO)
    {
        printf("CI: %d\n", camionero->getCedula());
        printf("Nombre: ");
        camionero->getNombre().print();
        printf("\nCantidad de tatuajes: %d\n", camionero->getCantTatuajes());
        Fecha f = camionero->getFechaNacimiento();
        printf("Fecha de nacimiento: %d/%d/%d\n", f.getDia(), f.getMes(), f.getAnio());

        delete camionero;
    }
    else
    {
        mostrarMensajeError(err);
    }

}
void opcion10(Fachada &fac) //Muestra cantidad de camiones grandes registrados posterior a una fecha dada (no contando la fecha dada)
{
    printf(BLUE "\n\n ***** Cantidad de camiones grandes registrados posterior a una fecha **** \n\n" RESET);
    int dia, mes, anio;
    Errores err;
    Fecha fecha;

    do {
        printf("Ingrese el dia: ");
        scanf("%d", &dia);
        printf("Ingrese el mes: ");
        scanf("%d", &mes);
        printf("Ingrese el anio: ");
        scanf("%d", &anio);

        fecha = Fecha(dia, mes, anio);

        if (!fecha.esValida()) {
                printf(RED "La fecha ingresada no es valida. Ingresar nuevamente \n" RESET);
            }

    } while (!fecha.esValida());

    int cantidad = fac.RegistradosGrandesPosteriorAFecha(fecha, err);

    if (err == NINGUNO)
    {
        printf("\nCantidad de camiones grandes registrados despues de la fecha ingresada: %d\n", cantidad);
    }
    else
    {
        mostrarMensajeError(err);

    }

}

void opcion11(Fachada &fac) // Agregado a efectos de prueba para cargar rápido camionero y camión
{
    ///A efectos de prueba
    printf(BLUE " \n\n *** Carga datos de prueba - 10 camioneros y 4 camiones *** \n\n" RESET);

    for(int i = 0; i<10; i++) // para cargar 10 camioneros
    {
        opcion4_automat(fac); // ejecuta carga de camionero
    }
    opcion1_automat(fac); // ejecuta carga de 3 camiones
}

int main()
{

    Fachada fachada;

    int opcionElegida = 0;




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
            opcion10(fachada);
            break;
        }
        case 11:
            {
                opcion11(fachada);
                break;
            }
        case 99:

            printf(BLUE "Saliendo del sistema..." RESET);
            break;

        default:
            printf(RED "La opcion ingresada no es valida. \n\n" RESET);
            break;

        }

    }
    while(opcionElegida != 99);

}


