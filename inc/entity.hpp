#ifndef ENTITY
#define ENTITY

#include <glm/glm.hpp>

class Entity {
private:
    glm::vec2 m_position;
    glm::vec2 m_size;
    
public:
    void setPosition(glm::vec2 position);
    void setSize(glm::vec2 size);

    glm::vec2 getPosition();
    glm::vec2 getSize();

    Entity();
    Entity(glm::vec2 position);
    Entity(glm::vec2 position, glm::vec2 size);
    ~Entity();
};

#endif
