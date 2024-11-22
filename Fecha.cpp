#include "Fecha.h"


void Fecha :: incrementar ()

{

    switch (mes)

    {

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:

        if (dia == 31)

        {

            dia = 1;

            if (mes == 12)

            {

                anio++;

                mes = 1;

            }

            else

            {

                mes++;

            }

        }

        else

        {

            dia++;

        }

        break;

    case 4:
    case 6:
    case 9:
    case 11:

        if (dia == 30)

        {

            dia = 1;

            mes++;

        }

        else

        {

            dia++;

        }

        break;

    case 2:

        if (((anio % 4 == 0) && (anio % 100 != 0)) || (anio % 400 == 0))

        {

            if (dia == 29)

            {

                dia = 1;

                mes++;

            }

            else

                dia++;

        }

        else if (dia == 28)

        {

            dia = 1;

            mes++;

        }

        else

        {

            dia++;

        }

    }

}



Fecha :: Fecha()

{

    dia = 1;

    mes = 1;

    anio = 1900;

}



Fecha :: Fecha (int d, int m, int a)

{

    dia = d;

    mes = m;

    anio = a;

}





Fecha :: Fecha (const Fecha &otra)
{

    dia = otra.dia;
    mes = otra.mes;
    anio = otra.anio;

}





Fecha :: ~Fecha()

{



}



int Fecha :: getDia()

{

    return dia;

}



int Fecha :: getMes()

{

    return mes;

}



int Fecha :: getAnio()

{

    return anio;

}







bool Fecha :: operator< (Fecha fec)
{



    bool esMenor = false;

    if (anio < fec.anio)
    {
        esMenor = true;
    }
    else
    {
        if (anio >fec.anio)
        {
            esMenor = false;
        }
        else
        {
            if (mes <fec.mes)
            {
                esMenor = true;
            }
            else
            {
                if (mes > fec.mes)
                {
                    esMenor = false;
                }
                else
                {
                    if (dia < fec.dia)
                    {
                        esMenor = true;
                    }
                    else
                    {
                        esMenor = false;
                    }
                }

            }

        }

    }

    return esMenor;



}

bool Fecha :: operator<= (Fecha fec)
{



    bool esMenorOIgual = false;

    if (anio <= fec.anio)
    {
        esMenorOIgual = true;
    }
    else
    {
        if (anio >fec.anio)
        {
            esMenorOIgual = false;
        }
        else
        {
            if (mes <=fec.mes)
            {
                esMenorOIgual = true;
            }
            else
            {
                if (mes > fec.mes)
                {
                    esMenorOIgual = false;
                }
                else
                {
                    if (dia <= fec.dia)
                    {
                        esMenorOIgual = true;
                    }
                    else
                    {
                        esMenorOIgual = false;
                    }
                }

            }
        }
    }

    return esMenorOIgual;



}



bool Fecha :: operator== (Fecha fec)
{



    bool aux = false;



    if (fec.anio == anio)
    {

        if (fec.mes == mes)
        {

            if (fec.dia == dia)
            {

                aux = true;

            }

        }

    }

    return aux;



}

Fecha Fecha :: operator++ ()

{

    incrementar ();

    return (*this);

}



Fecha Fecha :: operator++ (int i)

{

    Fecha resu = (*this);

    incrementar ();

    return resu;

}


Fecha Fecha :: operator+ (int d)

{

    Fecha resu = (*this);

    int cont;

    for (cont=1; cont <= d; cont++)

    {

        resu.incrementar ();

    }

    return (resu);



}



int Fecha:: operator-(Fecha f)
{
    Fecha aux;

    int signo = 1;
    int cont = 0;

    if (*this < f)
    {
        for (aux = *this; aux < f; aux++)
        {
            cont++;
        }

    }
    else
    {
        signo = -1;

        for (aux = f; aux < *this; aux++)
        {
            cont++;
        }
    }

    return (signo*cont);
}



bool Fecha :: esValida()
{


    bool es = true;

    if (anio < 1900 || anio > 2099) {
        es = false;
    }
    else
    {
        switch (mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dia < 1 || dia > 31) {
                es = false;
            }
                 break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia < 1 || dia > 30) {
                es = false;
            }
                 break;
        case 2:
            if (((anio % 4 == 0) && (anio % 100 != 0) ) || (anio % 400 == 0)) {
               if (dia < 1 || dia > 29) {
                es = false;
               }
            }
            else {
                if (dia < 1 || dia > 28) {
                    es = false;
                }
            }
            break;

        default:
            es = false;
            break;
        }
    }
    return es;

}

