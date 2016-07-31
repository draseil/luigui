#ifndef GUIOBJECT
#define GUIOBJECT

#include <glm/glm.hpp>

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
        
    public:
        /** \brief Set the position of the current GUI object
         *  \param[in] position The new position of the current GUI object
         */
        void setPosition(glm::vec2 position);

        /** \brief Set the size of the current GUI object
         *  \param[in] size The new size of the current GUI object
         */
        void setSize(glm::vec2 size);

        /** \brief Get the position of the current GUI object
         *  \returns the position of the current GUI object
         */
        glm::vec2 getPosition();

        /** \brief Get the size of the current GUI object
         *  \returns the size of the current GUI object
         */
        glm::vec2 getSize();

        /** \brief Constructs a GUI object object with a position and size of
         *         (0, 0)
         */
        GUIObject();

        /** \brief Constructs a GUI object object with a specified position and
         *         a size of (0, 0)
         *  \param[in] position The position of the new GUI object object
         */
        GUIObject(glm::vec2 position);

        /** \brief Constructs a GUI object object with a specified position and size
         *  \param[in] position The position of the new GUI object object
         *  \param[in] size The size of the new GUI object object
         */
        GUIObject(glm::vec2 position, glm::vec2 size);

        /** \brief Destroys the current GUI object
         */
        ~GUIObject();
    };
}

#endif