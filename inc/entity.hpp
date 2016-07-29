#ifndef ENTITY
#define ENTITY

#include <glm/glm.hpp>

/** \brief A base class that contains basic attributes of any GUI object
 */
class Entity {
private:
    /** \brief The position of the current entity
     */
    glm::vec2 m_position;

    /** \brief The size of the current entity
     */
    glm::vec2 m_size;
    
public:
    /** \brief Set the position of the current entity
     *  \param[in] position The new position of the current entity
     */
    void setPosition(glm::vec2 position);

    /** \brief Set the size of the current entity
     *  \param[in] size The new size of the current entity
     */
    void setSize(glm::vec2 size);

    /** \brief Get the position of the current entity
     *  \returns the position of the current entity
     */
    glm::vec2 getPosition();

    /** \brief Get the size of the current entity
     *  \returns the size of the current entity
     */
    glm::vec2 getSize();

    /** \brief Constructs an entity object with a position and size of (0, 0)
     */
    Entity();

    /** \brief Constructs an entity object with a specified position and a size
     *         of (0, 0)
     *  \param[in] position The position of the new entity object
     */
    Entity(glm::vec2 position);

    /** \brief Constructs an entity object with a specified position and size
     *  \param[in] position The position of the new entity object
     *  \param[in] size The size of the new entity object
     */
    Entity(glm::vec2 position, glm::vec2 size);

    /** \brief Destroys the current entity
     */
    ~Entity();
};

#endif
