#ifndef VIEW_H
#define VIEW_H


#include <vector>
#include "view/Shader.h"
#include "model/Modelo.h"
#include "view/Mesh.h"
#include "model/Nodo.h"

class View {
    public:
        View(Modelo* modelo, Shader* shader); 
        void createTextures();
        void createMalla(
            std::vector<float>* vertices,
            std::vector<unsigned int>* indices
        );
        void draw(Nodo* nodo);
        
    private:
        int alto;
        int ancho;
        Shader* shader;
        Modelo* modelo;
        Mesh meshCirculo;
};


#endif