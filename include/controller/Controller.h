#include <GLFW/glfw3.h>
#include "model/Modelo.h"
#include <iostream>


class Controller {
    public:
        Controller(GLFWwindow* window, Modelo* modelo);
        void procesarEntradas();

        Modelo* modelo;
        GLFWwindow* window;
};