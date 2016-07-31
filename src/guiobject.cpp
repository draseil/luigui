#include "guiobject.hpp"

const std::array<float, 20> calcVerts(glm::vec2 p, glm::vec2 s, glm::vec3 c) {
    return {{
        p.x, p.y, c.r, c.g, c.b,
        p.x + s.x, p.y, c.r, c.g, c.b,
        p.x + s.x, p.y + s.y, c.r, c.g, c.b,
        p.x, p.y + s.y, c.r, c.g, c.b
    }};
}

namespace luigui {
    void GUIObject::setPosition(glm::vec2 position) {
        m_position = position;
        m_vertices = calcVerts(m_position, m_size, m_colour);
    }

    void GUIObject::setSize(glm::vec2 size) {
        m_size = size;
        m_vertices = calcVerts(m_position, m_size, m_colour);
    }

    void GUIObject::setColour(glm::vec3 colour) {
        m_colour = colour;
        m_vertices = calcVerts(m_position, m_size, m_colour);
    }

    glm::vec2 GUIObject::getPosition() {
        return m_position;
    }

    glm::vec2 GUIObject::getSize() {
        return m_size;
    }

    glm::vec3 GUIObject::getColour() {
        return m_colour;
    }

    std::array<float, 20> GUIObject::getVertices() {
        return m_vertices;
    }

    GUIObject::GUIObject() :
                        m_position({0, 0}),
                        m_size({0, 0}),
                        m_colour({0, 0, 0}) {
        m_vertices = calcVerts(m_position, m_size, m_colour);
    }

    GUIObject::GUIObject(glm::vec2 position) :
                        m_position(position),
                        m_size({0, 0}),
                        m_colour({0, 0, 0}) {
        m_vertices = calcVerts(m_position, m_size, m_colour);
    }

    GUIObject::GUIObject(glm::vec2 position, glm::vec2 size) :
                        m_position(position),
                        m_size(size),
                        m_colour({0, 0, 0}) {
        m_vertices = calcVerts(m_position, m_size, m_colour);
    }

    GUIObject::GUIObject(glm::vec2 position, glm::vec2 size, glm::vec3 colour) :
                        m_position(position),
                        m_size(size),
                        m_colour(colour) {
        m_vertices = calcVerts(m_position, m_size, m_colour);
    }

    GUIObject::~GUIObject() {}
}
