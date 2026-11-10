#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <iostream>
#include "view/Shader.h"
#include "view/Mesh.h"
#include "controller/Controller.h"
#include "model/Object.h"
#include "model/Nodo.h"
#include "model/Modelo.h"
#include "view/View.h"

const char* vertexShaderCode = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 model;
uniform vec3 bColor;
out vec3 color;

void main() {
    gl_Position = model * vec4(aPos, 1.0);
    color = bColor;
}
)";

const char* fragmentShaderCode = R"(
#version 330 core
in vec3 color;
out vec4 FragColor;

uniform sampler2D miTextura;

void main() {
    FragColor = vec4(color, 1.0f);
}
)";

int main() {
    if (!glfwInit()) {
        std::cerr << "Error al inicializar GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(650, 650, "VENTANA", NULL, NULL);
    if (window == nullptr) {
        std::cerr << "Error al crear la ventana GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Error al inicializar GLAD" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 650, 650);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    Shader shaders = Shader(vertexShaderCode, fragmentShaderCode);
    Modelo modelo = Modelo();
    View view = View(&modelo, &shaders);
    Controller controller = Controller(window, &modelo);
    glm::mat4 matriz = glm::mat4(1.0f);

    while (!glfwWindowShouldClose(window)) {
        float time = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT);
        modelo.nodoSol.calcularPosicion(&time, &matriz);
        view.draw(&modelo.nodoSol);
        controller.procesarEntradas();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}