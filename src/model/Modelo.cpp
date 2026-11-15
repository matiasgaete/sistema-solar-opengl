#include "model/Modelo.h"

Modelo::Modelo() 
{
    sol = createCircle(100, 0.3f);
    tierra = createCircle(100, 0.12f);
    luna = createCircle(100, 0.04f);
    moldeCirculo = createCircle(100, 0.1f);

    nodoSol = Nodo(
        glm::mat4(1.0f), &sol,
        1.0f, 0.0f, 0.0f,
        glm::vec3(1.0f, 0.65f, 0.0f),
        3.0f, true
    );
    nodoTierra = Nodo(
        glm::mat4(1.0f), &tierra,
        1.0f, 0.72f, 0.72f,
        glm::vec3(0.0f, 0.0f, 1.0f),
        1.2f, false
    );
    nodoLuna = Nodo(
        glm::mat4(1.0f), &luna,
        13.0f, 0.22f, 0.22f,
        glm::vec3(1.0f, 1.0f, 1.0f),
        0.4f, false
    );

    nodoSol.agregarHijo(&nodoTierra);
    nodoTierra.agregarHijo(&nodoLuna);
};

Object Modelo::createCircle(int nVertices, float radio) {
    std::vector<float> vertices;
    std::vector<float> texturas;
    std::vector<unsigned int> indices;

    vertices.push_back(0.0f);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    texturas.push_back(0.5f);
    texturas.push_back(0.5f);

    float angulo = 0.0f;
    float paso = 2.0f * M_PI / static_cast<float>(nVertices);

    for (int i = 0; i < nVertices; i++) {
    
        float x = radio * std::cos(angulo);
        float y = radio * std::sin(angulo);

        float x_t = 0.5f + 0.5f * std::cos(angulo);
        float y_t = 0.5f + 0.5f * std::sin(angulo);

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0.0f);

        texturas.push_back(x_t);
        texturas.push_back(y_t);

        if (i != nVertices - 1) {
            indices.push_back(0);
            indices.push_back(i + 1);
            indices.push_back(i + 2);
        } else {
            indices.push_back(0);
            indices.push_back(i + 1);
            indices.push_back(1);
        }
        angulo += paso;
    };

    Object objeto;
    objeto.vertices = vertices;
    objeto.texturas = texturas;
    objeto.indices = indices;

    return objeto;
};