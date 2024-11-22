#ifndef ERRORES_H_INCLUDED
#define ERRORES_H_INCLUDED

typedef enum {
     NINGUNO,                 // No hubo errores.
    CAMIONERO_EXISTE,         // Error: ya existe un camionero con la cédula indicada.
    CAMIONERO_NO_EXISTE,      // Error: no se encontró un camionero con la cédula indicada.
    CAMION_EXISTE,            // Error: ya existe un camión con la matrícula indicada.
    CAMION_NO_EXISTE,         // Error: no se encontró un camión con la matrícula indicada.
    CAMIONES_NO_REGISTRADOS,  // Error: no hay camiones registrados en el sistema.
    CAMIONEROS_NO_REGISTRADOS,// Error: no hay camioneros registrados en el sistema.
    CAMIONEROS_VACIO          // Error: la lista de camioneros está vacía.
    }Errores;


#endif // ERRORES_H_INCLUDED
