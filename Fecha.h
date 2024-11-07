#ifndef FECHA_H_INCLUDED

#define FECHA_H_INCLUDED


#include <stdio.h>
class Fecha

{

  private:

	int dia, mes, anio;

    void incrementar ();// m�todo auxiliar, incrementa 1 d�a la fecha



  public:

	Fecha(); // Constructor por defecto

	Fecha (int, int, int); // Constructor com�n

	Fecha (const Fecha &); // Constructor de copia

	~Fecha();

	// Selectoras del tipo fecha

	int getDia();

	int getMes();

	int getAnio();

	bool operator<(Fecha); // compara por menos dos fechas

	bool operator<=(Fecha); // compara por menos o igual dos fechas

	bool operator==(Fecha); // compara por igualdad dos fechas

	Fecha operator++(); //Operador prefijo de incremento

	Fecha operator++(int); //Operador prefijo de incremento

	Fecha operator+(int); //Devuelve la fecha incrementada en n dias

	int operator-(Fecha); //Devuelve la diferencia en d�as entre 2 fechas

	bool esValida(); //Validacion de la fecha



};





#endif  // FECHA_H_INCLUDED

