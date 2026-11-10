#ifndef MODELO_H
#define MODELO_H


#include "model/Nodo.h"

class Modelo {
    public:
        Object sol;
        Object tierra;
        Object luna;
        Object moldeCirculo;

        Nodo nodoSol;
        Nodo nodoTierra;
        Nodo nodoLuna;

        Modelo();
        Object createCircle(int nVertices, float radio);
};

#endif