#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

#include <string.h>
#include <iostream>

//Implemente la clase String en C++ para representar cadenas de a lo sumo MAX caracteres.
//Internamente, la clase utilizar� char * como representaci�n, con uso de memoria din�mica.
//Se deben proveer los m�todos usuales
//(constructor por defecto, constructor com�n, constructor de copia, destructor y sobrecarga del operador de asignaci�n)
//en los cuales se debe manejar cuidadosamente la memoria din�mica evitando alias, y adem�s las siguientes operaciones:
//
//    == : String x String -> boolean
//    <  : String x String -> boolean  (comparaci�n alfab�tica)
//    +  : String x String -> String   (concatenaci�n)
//Tambi�n se deben programar las operaciones scan y print, que leen un string de teclado y muestran un string por pantalla respectivamente.
//b) Haga un programa de prueba (main) que pruebe los m�todos de la clase String.

const int MAX = 80;

class String
{
private:
    char * cadena;

public:
    String (); // Constructor por defecto
    String (char *); // Constructor comun
    String (const String&);
    ~String (); // Destructor
    String operator= (const String&);
    bool operator== (String);
    bool operator!= (String);
    bool operator< (String);
    String operator+ (String);
    void print();
    void scan();
    int sumarCaracteres();



    int largo() const;
};







#endif // STR_H_INCLUDED
