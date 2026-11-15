#ifndef MESH_H
#define MESH_H

#include <vector>

class Mesh {
    public:
        unsigned int VAO, EBO, VBO[2];

        Mesh(std::vector<float>* vertices,
            std::vector<unsigned int>* indices,
            std::vector<float>* texturas
        );

        ~Mesh();
};

#endif