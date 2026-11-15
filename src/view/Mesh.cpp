#include "view/Mesh.h"
#include <glad/glad.h>

Mesh::Mesh(
    std::vector<float>* vertices,
    std::vector<unsigned int>* indices,
    std::vector<float>* texturas
) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    // VERTICES
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(
        GL_ARRAY_BUFFER,
        (*vertices).size() * sizeof(float),
        (*vertices).data(),
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // TEXTURA
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(
        GL_ARRAY_BUFFER,
        (*texturas).size() * sizeof(float),
        (*texturas).data(),
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        (*indices).size() * sizeof(unsigned int),
        (*indices).data(),
        GL_STATIC_DRAW
    );
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(2, VBO);
    glDeleteBuffers(1, &EBO);
}
