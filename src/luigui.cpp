#include <string>
#include "luigui.hpp"

GLuint vertex_shader, fragment_shader, shader_program;

std::string vertex_shader_source =
    "#version 150"
    "in vec2 position"
    "void main() {"
        "gl_Position = position"
    "}";

std::string fragment_shader_source =
    "#version 150"
    "in vec3 in_colour"
    "out vec4 out_colour"
    "void main() {"
        "out_colour = vec4(in_colour, 1.0)"
    "}";

int luiguiInit() {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return 1;
    }

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    const char *vertex_shader_source_char = vertex_shader_source.c_str();
    glShaderSource(vertex_shader, 1, &vertex_shader_source_char, NULL);
    glCompileShader(vertex_shader);
    
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fragment_shader_source_char = fragment_shader_source.c_str();
    glShaderSource(fragment_shader, 1, &fragment_shader_source_char, NULL);
    glCompileShader(fragment_shader);

    shader_program = glCreateProgram();
    glAttachShader(vertex_shader, shader_program);
    glAttachShader(fragment_shader, shader_program);
    glLinkProgram(shader_program);
    glUseProgram(shader_program);

    return 0;
}

void luiguiTerminate() {
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    glDeleteProgram(shader_program);
}