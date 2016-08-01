#include <iostream>
#include <luigui.hpp>
#include <GLFW/glfw3.h>

constexpr int WIDTH = 640, HEIGHT = 480;

GLFWwindow *createWindow() {
    GLFWwindow *window = NULL;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "luigui example", NULL, NULL);
    glfwMakeContextCurrent(window);

    return window;
}

int main() {
    glfwInit();
    GLFWwindow *window = createWindow();
    luigui::init();

    luigui::GUIObject e({1, 2}, {3, 4});
    luigui::GUIObject f({5, 6});
    luigui::GUIObject g;
    luigui::GUIObject h({7, 8}, {9, 10}, {11, 12, 13});

    for (auto i : e.getVertices()) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    for (auto i : f.getVertices()) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    for (auto i : g.getVertices()) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    for (auto i : h.getVertices()) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}