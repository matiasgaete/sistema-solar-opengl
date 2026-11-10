#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

struct Object {
    std::vector<float> vertices;
    std::vector<float> colores;
    std::vector<unsigned int> indices;
    std::vector<float> texturas;
};

#endif