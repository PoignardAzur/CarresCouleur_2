
#ifndef MENU_ABSTRACTION_HEADER
#define MENU_ABSTRACTION_HEADER

#include "ButtonAbstraction.hpp"
#include <vector>
#include <cstdlib>


namespace Menu
{

    // POINTER SAFETY : 'selectedButton()' must be null or safe when 'press()' is called
    class MenuAbstraction : public ButtonAbstraction
    {
        public :

        explicit MenuAbstraction(bool isVertical = true, bool doesLoop = false);

        virtual void select();                                  // each method is applied to the
        virtual void deselect();                                // currently selected button
        virtual void press();                                   // if there is one

        virtual void left(bool big = false);
        virtual void right(bool big = false);
        virtual void up(bool big = false);
        virtual void down(bool big = false);


        protected :

        ButtonAbstraction* selectedButton();                    // can be nullptr
        const ButtonAbstraction* selectedButton() const;
        void setSelectedButton(size_t selectedButtonSlot);
        void setButtonList(std::vector<ButtonAbstraction*> buttonList, size_t selectedButtonSlot = 0);
        void addButton(ButtonAbstraction* b);

        void updateSelected();


        private :

        int m_selectedButton = -1;                              // if no button is selected, m_selectedButton equals -1
        std::vector<ButtonAbstraction*> m_buttonList;           // use-a ; none of the pointers have any ownership
        bool m_isVertical;
        bool m_doesLoop;

        void increment(bool big);
        void decrement(bool big);
    };

}


#endif // MENU_ABSTRACTION_HEADER
