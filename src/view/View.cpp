#include "view/View.h"

View::View(Modelo* modelo, Shader* shader)
    : shader(shader),
      modelo(modelo),
      meshCirculo(
          &modelo->moldeCirculo.vertices,
          &modelo->moldeCirculo.indices,
          &modelo->moldeCirculo.texturas
      ),
      texturaSol("assets/sol.jpg"),
      texturaTierra("assets/earth.jpg"),
      texturaLuna("assets/moon.jpg")
      {
        modelo->nodoSol.textura = &texturaSol;
        modelo->nodoTierra.textura = &texturaTierra;
        modelo->nodoLuna.textura = &texturaLuna;
      }

void View::draw(Nodo* nodo) {

    (*shader).use();
    glBindVertexArray(meshCirculo.VAO);
    glm::mat4 matrizDibujo = glm::scale(nodo->global, glm::vec3(nodo->razon, nodo->razon, 1.0f));
    shader->setMat4("model", matrizDibujo);
    nodo->textura->bind();
    shader->setInt("miTextura", 0);
    glDrawElements(GL_TRIANGLES, (nodo->obj->indices).size(), GL_UNSIGNED_INT, 0);

    size_t n = nodo->hijos.size();
    for (size_t i = 0; i < n; i++){
        draw(nodo->hijos[i]);
    };
};

Texture View::createTexture(const char* filePath) {
    Texture textura = Texture(filePath);
    return textura;
};
