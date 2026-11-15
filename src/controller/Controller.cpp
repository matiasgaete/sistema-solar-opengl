#include "controller/Controller.h"

Controller::Controller(GLFWwindow* window, Modelo* modelo) {
    this->window = window;
    this->modelo = modelo;
};

void printMat4(const glm::mat4& matrix) {
    std::cout<<"matriz"<<std::endl;
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            std::cout << matrix[col][row] << "\t"; // Nota: [col][row] para imprimir por filas
        }
        std::cout << '\n';
    }
}

void Controller::procesarEntradas() {
    float x = 0.0f;
    float y = 0.0f;

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) y -= 0.01f;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) y += 0.01f;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) x -= 0.01f;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) x += 0.01f;
    glm::mat4 localNodoRaiz = modelo->nodoSol.local;
    modelo->nodoSol.local = glm::translate(localNodoRaiz, glm::vec3(x, y, 0.0f));
};
