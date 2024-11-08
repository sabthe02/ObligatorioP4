#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

#include <string.h>

//Implemente la clase String en C++ para representar cadenas de a lo sumo MAX caracteres.
//Internamente, la clase utilizará char * como representación, con uso de memoria dinámica.
//Se deben proveer los métodos usuales
//(constructor por defecto, constructor común, constructor de copia, destructor y sobrecarga del operador de asignación)
//en los cuales se debe manejar cuidadosamente la memoria dinámica evitando alias, y además las siguientes operaciones:
//
//    == : String x String -> boolean
//    <  : String x String -> boolean  (comparación alfabética)
//    +  : String x String -> String   (concatenación)
//También se deben programar las operaciones scan y print, que leen un string de teclado y muestran un string por pantalla respectivamente.
//b) Haga un programa de prueba (main) que pruebe los métodos de la clase String.

const int MAX = 80;

class String
{
private:
    char * cadena;

public:
    String (); // Constructor por defecto
    String (char *); // Constructor común
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
};

#endif // STR_H_INCLUDED
