
#ifndef BUTTON_LIST_ABSTRACTION_HEADER
#define BUTTON_LIST_ABSTRACTION_HEADER

#include "../Items/Buttons/ButtonAbstraction.hpp"
#include <deque>


namespace Menu
{

    // POINTER SAFETY : 'selectedButton()' must be null or safe when one of the public methods is called
    class ButtonListAbstraction : public ButtonAbstraction
    {
        public :

        explicit ButtonListAbstraction(bool isMenuVertical = true, bool doesMenuLoop = false);

        virtual void select();                                  // each method is applied to the
        virtual void deselect();                                // currently selected button
        virtual void press();                                   // if there is one

        virtual void left(bool big = false);
        virtual void right(bool big = false);
        virtual void up(bool big = false);
        virtual void down(bool big = false);

        virtual sf::Vector2f getSize() const = 0;


        protected :

        bool doesLoop() const;
        bool isVertical() const;

        virtual void setLoop(bool doesMenuLoop);
        virtual void setVertical(bool isMenuVertical);

        virtual void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const = 0;

        ButtonAbstraction* selectedButton();                    // can be nullptr
        const ButtonAbstraction* selectedButton() const;

        void setSelectedButton(size_t selectedButtonSlot = -1);
        void setButtonPointerList(std::deque<ButtonAbstraction*> buttonPointerList, size_t selectedButtonSlot = 0);
        void addButtonPointer(ButtonAbstraction* buttonPointer);

        void updateSelected();


        private :

        int m_selectedButton = -1;                              // if no button is selected, m_selectedButton equals -1
        std::deque<ButtonAbstraction*> m_buttonPointerList;     // use-a ; none of the pointers have any ownership

        void increment(bool big);
        void decrement(bool big);

        bool m_isVertical;
        bool m_doesLoop;
    };

}


#endif // BUTTON_LIST_HEADER
