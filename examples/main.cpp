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

    std::cout << e.getPosition().x << ", " << e.getPosition().y << std::endl
              << e.getSize().x     << ", " << e.getSize().y     << std::endl;

    std::cout << f.getPosition().x << ", " << f.getPosition().y << std::endl
              << f.getSize().x     << ", " << f.getSize().y     << std::endl;

    std::cout << g.getPosition().x << ", " << g.getPosition().y << std::endl
              << g.getSize().x     << ", " << g.getSize().y     << std::endl;

    std::cout << h.getPosition().x << ", " << h.getPosition().y << std::endl
              << h.getSize().x     << ", " << h.getSize().y     << std::endl
              << h.getColour().r   << ", " << h.getColour().g   << ", "
              << h.getColour().b << std::endl;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}