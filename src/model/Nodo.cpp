#include "model/Nodo.h"


Nodo::Nodo(
    glm::mat4 local,
    Object* obj,
    float razonVel,
    float distanciaX,
    float distanciaY,
    glm::vec3 color,
    float razon,
    bool raiz
) {
    this->local = local;
    this->obj = obj;
    this->razonVel = razonVel;
    this->distanciaX = distanciaX;
    this->distanciaY = distanciaY;
    this->color = color;
    this->razon = razon;
    this->raiz = raiz;
};

void Nodo::agregarHijo(Nodo* hijo) {
    this->hijos.push_back(hijo);
}

void Nodo::calcularPosicion(float* time, glm::mat4* globalPadre) {
    glm::mat4 origen;

    if (this->raiz) {
        origen = local;
    } else {
        origen = glm::mat4(1.0f);
    }

    float x = distanciaX * std::cos((*time) * razonVel);
    float y = distanciaY * std::sin((*time) * razonVel);

    local = glm::translate(origen, glm::vec3(x, y, 0.0f));
    global = (*globalPadre) * local;
    
    for (int i = 0; i < hijos.size(); i++) {
        hijos[i]->calcularPosicion(time, &global);
    }
}
