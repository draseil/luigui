#ifndef GUIOBJECT
#define GUIOBJECT

#include <glm/glm.hpp>
#include <array>

namespace luigui {
    /** \brief A base class that contains basic attributes of any GUI object
     */
    class GUIObject {
    private:
        /** \brief The position of the current GUI object
         */
        glm::vec2 m_position;

        /** \brief The size of the current GUI object
         */
        glm::vec2 m_size;

        /** \brief The colour of the current GUI object
         */
        glm::vec3 m_colour;

        /** \brief The set of vertices used by OpenGL to draw the current GUI
         *         object
         */
        std::array<float, 20> m_vertices;
        
    public:
        /** \brief Set the position of the current GUI object
         *  \param[in] position The new position of the current GUI object
         */
        void setPosition(glm::vec2 position);

        /** \brief Set the size of the current GUI object
         *  \param[in] size The new size of the current GUI object
         */
        void setSize(glm::vec2 size);

        /** \brief Set the colour of the current GUI object
         *  \param[in] colour The new colour of the current GUI object
         */
        void setColour(glm::vec3 colour);

        /** \brief Get the position of the current GUI object
         *  \returns the position of the current GUI object
         */
        glm::vec2 getPosition();

        /** \brief Get the size of the current GUI object
         *  \returns the size of the current GUI object
         */
        glm::vec2 getSize();

        /** \brief Get the colour of the current GUI object
         *  \returns the colour of the current GUI object
         */
        glm::vec3 getColour();

        /** \brief Get the set of vertices used by OpenGL to draw the current
         *         GUI object
         *  \returns The set of vertices used by OpenGL to draw the current GUI
         *           object
         */

        std::array<float, 20> getVertices();

        /** \brief Constructs a GUI object object with a position and size of
         *         (0, 0)
         */
        GUIObject();

        /** \brief Constructs a GUI object object with a specified position and
         *         a size of (0, 0) and a black colour
         *  \param[in] position The position of the new GUI object object
         */
        GUIObject(glm::vec2 position);

        /** \brief Constructs a GUI object object with a specified position and
         *         size, and a black colour
         *  \param[in] position The position of the new GUI object object
         *  \param[in] size The size of the new GUI object object
         */
        GUIObject(glm::vec2 position, glm::vec2 size);

        /** \brief Constructs a GUI object object with a specified position,
         *         size and colour
         *  \param[in] position The position of the new GUI object object
         *  \param[in] size The size of the new GUI object object
         *  \param[in] colour The colour of the new GUI object object
         */
        GUIObject(glm::vec2 position, glm::vec2 size, glm::vec3 colour);

        /** \brief Destroys the current GUI object
         */
        ~GUIObject();
    };
}

#endif
