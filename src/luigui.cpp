#include "luigui.hpp"

int luiguiInit() {
    glewExperimental = GL_TRUE;
    return glewInit() == GLEW_OK;
}