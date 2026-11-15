#ifndef NODO_H
#define NODO_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "model/Object.h"
#include "view/Texture.h"

class Nodo {
    public:
        Nodo() = default;
        Nodo(
            glm::mat4 local,
            Object* obj,
            float razonVel,
            float distanciaX,
            float distanciaY,
            glm::vec3 color,
            float razon,
            bool raiz
        );
        glm::mat4 global = glm::mat4(1.0f);
        glm::mat4 local;
        Object* obj;
        std::vector<Nodo*> hijos;
        float razonVel;
        float distanciaX;
        float distanciaY;
        glm::vec3 color;
        float razon;
        bool raiz;
        Texture* textura;

        void agregarHijo(Nodo* hijo);
        void calcularPosicion(float* time, glm::mat4* globalPadre);
};

#endif