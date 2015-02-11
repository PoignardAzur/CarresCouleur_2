
#ifndef MENU_ABSTRACTION_HEADER
#define MENU_ABSTRACTION_HEADER

#include "ButtonAbstraction.hpp"
#include <vector>
#include <cstdlib>


namespace Menu
{

    class MenuAbstraction : public ButtonAbstraction
    {
        public :

        MenuAbstraction(bool isVertical = true, bool doesLoop = false);

        virtual void select();
        virtual void deselect();
        virtual void press();

        virtual void left(bool big = false);
        virtual void right(bool big = false);
        virtual void up(bool big = false);
        virtual void down(bool big = false);


        protected :

        ButtonAbstraction* selectedButton();
        const ButtonAbstraction* selectedButton() const;
        void setButtonList(std::vector<ButtonAbstraction*> buttonList, size_t selectedButtonSlot = 0);
        void addButton(ButtonAbstraction* b);

        void updateSelected();


        private :

        size_t m_selectedButton = 0;
        std::vector<ButtonAbstraction*> m_buttonList;      // use-a ; none of the pointers have any ownership
        bool m_isVertical;
        bool m_doesLoop;

        void increment(bool big);
        void decrement(bool big);
    };

}


#endif // MENU_ABSTRACTION_HEADER
