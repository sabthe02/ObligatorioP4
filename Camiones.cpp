#include "Camiones.h"

// FUNCION DE DISPERSION
// Convierte la matrícula en un número sumando los valores ASCII de sus caracteres 
// y luego calcula el módulo de esa suma respecto al tamaño de la tabla (B).
int Camiones::h(String x)
{

    int y = x.sumarCaracteres();

    return (y % B); // Devuelve el índice en la tabla hash.
}

// Inicializa la lista enlazada como vacía.
void Camiones :: crearLista (Nodo * &L)
{
    L = NULL;
}
// Destruye la lista enlazada, liberando la memoria de todos los nodos.
void Camiones :: destruirLista (Nodo * &L)
{
    Nodo * aux = L;
    while (aux != NULL)
    {
        L = aux->sig;
        delete (aux);
        aux = L;
    }
    L = aux;
}
// Verifica si un camion con la matrícula dada pertenece a la lista.
bool Camiones :: perteneceLista (Nodo * L, String mat)
{
    bool existe = false;
    while (!existe && L != NULL)
        if (L->info->getMatricula() == mat)
            existe = true;
        else
            L = L->sig;
    return existe;
}
// Inserta un nuevo camion al frente de la lista 
void Camiones :: insFrontEnLista (Nodo * &L, Camion * c)
{
    Nodo * aux = new Nodo;
    aux->info = c;
    aux->sig = L;
    L = aux;
}
// Devuelve un puntero al camión con la matrícula dada
Camion * Camiones :: obtenerEnLista (Nodo * L, String mat)
{
    while (L->info->getMatricula() != mat)
        L = L->sig;
    return (L->info);
}
// Lista todos los camiones de la lista
void Camiones :: listarTodosEnLista (Nodo * L, iterador &iter)
{
    while (L != NULL)
    {
        if(L->info->getTipo() == "Simple")
        {
            Simple * simp = new Simple(*(Simple *)L->info);
            iter.insertar(simp);
        }else if(L->info->getTipo() == "Grande")
        {
            Grande * simp = new Grande(*(Grande *)L->info);
            iter.insertar(simp);
        }else
        {
            ConRemolque * simp = new ConRemolque(*(ConRemolque *)L->info);
            iter.insertar(simp);
        }

        L = L->sig;
    }
}
// Calcula el volumen anual total de los camiones en la lista.
float Camiones :: volumenPorLista (Nodo * L)
{
    int volumenLista = 0;
    while (L != NULL)
    {
        volumenLista = L->info->calcularCapacidadAnualDeVolumen()+volumenLista;
        L = L->sig;
    }
    return volumenLista;
}
// Calcula la cantidad de camiones por tipo en la lista.
void Camiones::cantidadEnFlotaLista(Nodo *L, int &simples, int &grandes, int &conremolque)
{

    while (L != NULL)
    {
        if(L->info->getTipo() =="Simple")
        {
            simples++;
        }
        else
        {
            if ((L->info->getTipo() =="Grande"))
            {
                grandes++;
            }
            else
            {
                conremolque++;
            }
        }
        L = L->sig;
    }

}
// Cuenta los camiones grandes adquiridos después de una fecha determinada
int Camiones::contarCamionesGrandesPostFechaLista (Nodo *L, Fecha f)
{

    int contador = 0;
    while (L != NULL)
    {
        // Verifica si el camión en el nodo actual es de tipo "Grande".
        if (L->info->getTipo() == "Grande")
        {
            Grande* d = ((Grande*)L->info);
             // Compara si la fecha de adquisición del camión es posterior a la fecha dada 'f'.
            if (f < d->getFechaAdquirida())
            {
                contador++;
            }
        }
        L = L->sig; // Avanza al siguiente nodo en la lista.
    }
    return contador;

}
// Constructor
Camiones::Camiones()
{

    for (int i=0; i <B; i++)
    {
        crearLista(Hash[i]); // Inicializa cada cubeta como lista vacía.
    }

}
// Destructor
Camiones::~Camiones()
{
    for (int i=0; i<B; i++)
    {
        destruirLista(Hash[i]);
    }
}

// Verifica si un camión con una matrícula específica pertenece al hash.
bool Camiones::Member(String mat)
{

    int cubeta = h(mat);
    return (perteneceLista (Hash[cubeta], mat));
}

// Inserta un camión en la tabla hash.
void Camiones::Insert(Camion *c)
{

    String mat = c->getMatricula();
    int cubeta = h(mat); // Calcula la cubeta donde debe insertarse el camión.
    insFrontEnLista (Hash[cubeta], c);


}

// Busca y devuelve un puntero al camión con una matrícula específica en la tabla hash.
Camion* Camiones::Find(String mat)
{
    int cubeta = h(mat); // Calcula la cubeta donde debe estar el camión.
    return obtenerEnLista(Hash[cubeta], mat); // Busca y devuelve el camión en esa cubeta.
}

// Lista todos los camiones en la tabla hash, usando un iterador.
void Camiones:: listarCamiones (iterador &iter)
{

    for (int i=0; i < B; i++)
        listarTodosEnLista (Hash[i], iter);  // Inserta todos los camiones de cada cubeta en el iterador.

}

// Calcula la capacidad anual total de la flota de camiones.
float Camiones:: capacidadAnualFlota()
{

    float capacidad;
    for (int i=0; i < B; i++)
    {
        capacidad += volumenPorLista(Hash[i]); // va sumando  el volumen de la cubeta actual a la capacidad total. 
    }
    return capacidad;
}
// Calcula la cantidad de camiones por tipo en toda la tabla hash.
void Camiones::cantidadEnFlota(int &simple, int &grande, int &conremolque)
{

    simple = 0;
    grande = 0;
    conremolque = 0;

    for (int i=0; i < B; i++)
    {
        cantidadEnFlotaLista(Hash[i],simple, grande, conremolque);
    }

}
// Cuenta los camiones grandes adquiridos después de una fecha específica en la tabla hash.
int Camiones::contarCamionesGrandesPostFecha(Fecha f)
{

    int contador = 0;

    for (int i = 0; i < B; i++) // Recorre todas las cubetas
    {
        contador = contador + contarCamionesGrandesPostFechaLista(Hash[i], f); // Cuenta los camiones grandes en cada cubeta.
    }

    return contador;
}

bool Camiones::Empty()
{
    bool hay = false;
    int i = 0;

    while (!hay && i<B)
    {
        hay = Hash[i] == NULL;
        i++;
    }

    return !hay;
}
