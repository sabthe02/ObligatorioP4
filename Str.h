#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

#include <string.h>

const int MAX = 80;

class String
{
private:
    char * cadena;

public:
    String ();
    String (char *);
    String (const String&);
    ~String ();
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
