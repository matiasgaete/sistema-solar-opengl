#ifndef MESH_H
#define MESH_H

#include <vector>

class Mesh {
    public:
        unsigned int VAO, EBO, VBO;

        Mesh(std::vector<float>* vertices,
            std::vector<unsigned int>* indices);

        ~Mesh();
};

#endif