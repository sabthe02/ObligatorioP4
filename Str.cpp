#include "Str.h"
#include <stdio.h>

String :: String ()
{
    cadena = new char [1];
    cadena[0] = '\0';
}

String :: String (char * cad)
{
    int largo = strlen(cad);
    cadena = new char [largo + 1];
    strcpy (cadena, cad);
}

String :: String (const String &otro)
{
    int largo = strlen(otro.cadena);
    cadena = new char [largo + 1];
    strcpy (cadena, otro.cadena);
}

String :: ~String()
{
    delete [] cadena;
}

String String :: operator= (const String &otro)
{
    if (this != &otro)
    {
        delete [] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char [largo + 1];
        strcpy (cadena, otro.cadena);
    }
    return (*this);
}

bool String::operator== (String s) {
    bool es = true;
    if (strcmp(s.cadena, cadena) != 0) {
        es = false;
    }
    return es;
}

bool String::operator!= (String s) {
    bool es = false;
    if (strcmp(s.cadena, cadena) == 0) {
        es = false;
    }
    return es;
}

bool String:: operator< (String s) {
    bool es = true;

    if (strcmp(s.cadena,cadena) == 0) {
        es = false;
}
    else {
        if (strcmp(s.cadena, cadena) <0) {
            es = false;
        }
}
return es;

}


String String:: operator+ (String s) {
    String aux;
    int largo1 = strlen(cadena);
    int largo2 = strlen(s.cadena);
    aux.cadena = new char [largo1 + largo2 + 1];
    strcpy(aux.cadena,cadena);
    strcat(aux.cadena,s.cadena);
    return aux;

}

void String:: print()
{
    int i = 0;
    while (cadena[i]!= '\0' && i <MAX)
    {
        printf ("%c", cadena[i]);
        i++;
    }
}

void String:: scan()
{
    char aux[MAX];
    int i = 0;
    char c;
    scanf ("%c",&c);
    while (c != '\n' && i<MAX-1)
    {
        cadena[i] = c;
        i++;
        scanf("%c",&c);
    }
    cadena[i] = '\0';
    cadena = new char[i+1];
    strcpy(cadena, aux);
}

int String::sumarCaracteres() {

    int i = 0;
    int contador = 0;
    while (cadena[i]!= '\0' && i <MAX)
    {
        contador = cadena[i]+contador;
        i++;
    }
    return contador;


}
