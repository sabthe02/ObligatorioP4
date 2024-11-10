#include <stdio.h>

#include "Fachada.h"
#include "Iterador.h"

void imprimirMenu()
{
    printf(" *****  MENU PRINCIPAL **** \n\n");
    printf("\n 1 - Registrar un nuevo camion. ");
    printf("\n 2 - Listado basico de todos los camiones. ");
    printf("\n 3 - Listado detallado de un camion. ");
    printf("\n 4 - Registrar un nuevo camionero. ");
    printf("\n 5 - Listado de todos los camioneros registrados. ");
    printf("\n 6 - Cantidad de metros cœbicos anuales que se pueden transportar. ");
    printf("\n 7 - Modificar cantidad de viajes anuales que puede transportar un camion. ");
    printf("\n 8 - Cantidad de camiones por tipo. ");
    printf("\n 9 - Datos del camionero con mas tatuajes. ");
    printf("\n 10 - Cantidad de camiones grandes registrados posterior a una fecha. ");
    printf("\n\n 99 - Salir. ");


    printf("\n\n\nIngrese la opcion elegida: ");
}

void opcion1(Fachada fac)
{

}
void opcion2(Fachada fac)
{

}
void opcion3(Fachada fac)
{

}
void opcion4(Fachada fac)
{

}
void opcion5(Fachada fac)
{

}
void opcion6(Fachada fac)
{

}
void opcion7(Fachada fac)
{

}
void opcion8(Fachada fac)
{

}
void opcion9(Fachada fac)
{

}
void opcion10(Fachada fac)
{

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
            opcion1(fachada);
            break;
        }
        default:
            printf("La opcion ingresada no es valida. \n\n");
            break;
        }

    }
    while(opcionElegida != 99);
}
