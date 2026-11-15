#ifndef VIEW_H
#define VIEW_H


#include <vector>
#include "view/Shader.h"
#include "model/Modelo.h"
#include "view/Mesh.h"
#include "view/Texture.h"

class View {
    public:
        View(Modelo* modelo, Shader* shader); 
        Texture createTexture(const char* filePath);
        void createMalla(
            std::vector<float>* vertices,
            std::vector<unsigned int>* indices
        );
        void draw(Nodo* nodo);
        
        int alto;
        int ancho;
        Shader* shader;
        Modelo* modelo;
        Mesh meshCirculo;
        Texture texturaSol;
        Texture texturaTierra;
        Texture texturaLuna;
};


#endif