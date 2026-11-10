#include "view/View.h"

View::View(Modelo* modelo, Shader* shader)
    : shader(shader),
      modelo(modelo),
      meshCirculo(
          &modelo->moldeCirculo.vertices,
          &modelo->moldeCirculo.indices
      ) {}

void View::draw(Nodo* nodo) {

    (*shader).use();
    glBindVertexArray(meshCirculo.VAO);
    glm::mat4 matrizDibujo = glm::scale(nodo->global, glm::vec3(nodo->razon, nodo->razon, 1.0f));
    shader->setMat4("model", matrizDibujo);
    shader->setVec3("bColor", nodo->color);
    glDrawElements(GL_TRIANGLES, (nodo->obj->indices).size(), GL_UNSIGNED_INT, 0);

    size_t n = nodo->hijos.size();
    for (size_t i = 0; i < n; i++){
        draw(nodo->hijos[i]);
    };
};
