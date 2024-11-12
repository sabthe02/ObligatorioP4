#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

#include <string.h>
#include <iostream>

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
