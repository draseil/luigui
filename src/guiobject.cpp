#include "guiobject.hpp"

namespace luigui {
    void GUIObject::setPosition(glm::vec2 position) {
        m_position = position;
    }

    void GUIObject::setSize(glm::vec2 size) {
        m_size = size;
    }

    void GUIObject::setColour(glm::vec3 colour) {
        m_colour = colour;
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

    GUIObject::GUIObject() :
                        m_position({0, 0}),
                        m_size({0, 0}),
                        m_colour({0, 0, 0}) {}

    GUIObject::GUIObject(glm::vec2 position) :
                        m_position(position),
                        m_size({0, 0}),
                        m_colour({0, 0, 0}) {}

    GUIObject::GUIObject(glm::vec2 position, glm::vec2 size) :
                        m_position(position),
                        m_size(size),
                        m_colour({0, 0, 0}) {}

    GUIObject::GUIObject(glm::vec2 position, glm::vec2 size, glm::vec3 colour) :
                        m_position(position),
                        m_size(size),
                        m_colour(colour) {}

    GUIObject::~GUIObject() {}
}
