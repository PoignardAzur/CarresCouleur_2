

#ifndef ABSTRACT_MENU_HEADER
#define ABSTRACT_MENU_HEADER

#include "AbstractButton.h"
#include <vector>
#include <cstdlib>


namespace Menu
{

    class AbstractMenu : public AbstractButton
    {
        public :

        AbstractMenu(bool isVertical = true, bool doesLoop = false);

        virtual void select();
        virtual void deselect();
        virtual void press();

        virtual void left(bool big = false);
        virtual void right(bool big = false);
        virtual void up(bool big = false);
        virtual void down(bool big = false);


        protected :

        AbstractButton* selectedButton();
        const AbstractButton* selectedButton() const;
        void setButtonList(std::vector<AbstractButton*> buttonList, size_t selectedButtonSlot = 0);
        void addButton(AbstractButton* b);

        void updateSelected();


        private :

        size_t m_selectedButton = 0;
        std::vector<AbstractButton*> m_buttonList;      // use-a ; none of the pointers have any ownership
        bool m_isVertical;
        bool m_doesLoop;

        void increment(bool big);
        void decrement(bool big);
    };

}


#endif // ABSTRACT_MENU_HEADER

