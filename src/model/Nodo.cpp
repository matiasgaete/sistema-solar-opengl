#include "model/Nodo.h"


Nodo::Nodo(
    glm::mat4 local,
    Object* obj,
    float razonVel,
    float distanciaX,
    float distanciaY,
    glm::vec3 color,
    float razon
) {
    this->local = local;
    this->obj = obj;
    this->razonVel = razonVel;
    this->distanciaX = distanciaX;
    this->distanciaY = distanciaY;
    this->color = color;
    this->razon = razon;
};

void Nodo::agregarHijo(Nodo* hijo) {
    this->hijos.push_back(hijo);
}

void Nodo::calcularPosicion(float* time, glm::mat4* globalPadre) {
    float x = distanciaX * std::cos((*time) * razonVel);
    float y = distanciaY * std::sin((*time) * razonVel);

    local = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
    global = (*globalPadre) * local;
    
    for (int i = 0; i < hijos.size(); i++) {
        hijos[i]->calcularPosicion(time, &global);
    }
}
