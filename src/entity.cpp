#include "entity.hpp"

namespace luigui {
    void Entity::setPosition(glm::vec2 position) {
        m_position = position;
    }

    void Entity::setSize(glm::vec2 size) {
        m_size = size;
    }

    glm::vec2 Entity::getPosition() {
        return m_position;
    }

    glm::vec2 Entity::getSize() {
        return m_size;
    }

    Entity::Entity() {
        m_position = {0, 0};
        m_size = {0, 0};
    }

    Entity::Entity(glm::vec2 position) {
        m_position = position;
        m_size = {0, 0};
    }

    Entity::Entity(glm::vec2 position, glm::vec2 size) {
        m_position = position;
        m_size = size;
    }

    Entity::~Entity() {}
}
