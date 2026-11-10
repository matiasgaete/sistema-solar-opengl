#define GLM_ENABLE_EXPERIMENTAL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "Nodo.h"

const char* vertexShaderCode = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTextCoord;

uniform mat4 model;
out vec2 textCoord;

void main() {
    gl_Position = model * vec4(aPos, 1.0);
    textCoord = aTextCoord;
}
)";

const char* fragmentShaderCode = R"(
#version 330 core
in vec2 textCoord;
out vec4 FragColor;

uniform sampler2D miTextura;

void main() {
    FragColor = texture(miTextura, textCoord);
}
)";

void processInput(GLFWwindow* window, float& x, float& y) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) y += 0.01f;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) y -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) x -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) x += 0.01f;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Fallo al inicializar GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    float ancho = 650;
    float alto = 650;

    GLFWwindow* window = glfwCreateWindow(ancho, alto, "Primer OpenGL - Modularizado", NULL, NULL);
    if (!window) {
        std::cerr << "Fallo al crear la ventana de GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Fallo al inicializar GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, ancho, alto);

    // Creación de recursos
    Shader shader(vertexShaderCode, fragmentShaderCode);
    Texture texturaM("assets/textures/moon.jpg");
    Texture texturaS("assets/textures/sol.jpg");
    Texture texturaT("assets/textures/earth.jpg");
    
    Mesh sol = createCircleMesh(100, 0.3f, 0.5f);
    Mesh luna = createCircleMesh(100, 0.04f, 0.5f);
    Mesh tierra = createCircleMesh(100, 0.12f, 0.39f);

    Nodo nodoSol = Nodo(glm::mat4(1.0f), &sol, &texturaS);
    Nodo nodoTierra = Nodo(glm::mat4(1.0f), &tierra, &texturaT);
    Nodo nodoLuna = Nodo(glm::mat4(1.0f), &luna, &texturaM);

    nodoSol.agregarHijo(&nodoTierra);
    nodoTierra.agregarHijo(&nodoLuna);
    glm::mat4 globalPadre = glm::mat4(1.0f);

    shader.use();
    shader.setInt("miTextura", 0);

    float x = 0.0f, y = 0.0f, z = 0.0f;
    float horizontal = 0.0f, vertical = 0.0f;
    float time = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        processInput(window, horizontal, vertical);
        float time = glfwGetTime();

        std::cout<<x<<std::endl;

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        nodoSol.local = glm::translate(glm::mat4(1.0f), glm::vec3(horizontal, vertical,z));

        float velTierra = time * 1.0f;
        x = 0.72f * std::cos(velTierra);
        y = 0.72f * std::sin(velTierra);
        nodoTierra.local = glm::translate(glm::mat4(1.0f), glm::vec3(x,y,z));

        float velLuna = time * 13.0f;
        x = (0.22f * std::cos(velLuna));
        y = (0.22f * std::sin(velLuna));
        nodoLuna.local = glm::translate(glm::mat4(1.0f), glm::vec3(x,y,z));

        nodoSol.draw(&globalPadre, &shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}