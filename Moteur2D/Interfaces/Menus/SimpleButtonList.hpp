
#ifndef SIMPLE_BUTTON_LIST_HEADER
#define SIMPLE_BUTTON_LIST_HEADER

#include "ButtonListAbstraction.hpp"
#include "../Items/Containers/ItemLine.hpp"


namespace Menu
{

    class SimpleButtonList : public ButtonListAbstraction
    {
        public :

        SimpleButtonList(bool isMenuVertical = true, bool doesMenuLoop = false);

        void addItem(uptrt<Menu::AbstractItem> item);
        void addButton(uptrt<Menu::ButtonAbstraction> button);

        void setVertical(bool isMenuVertical);
        void setGapsBetweenButtons(float gaps);

        sf::Vector2f getSize() const;
        void setParent(AbstractItem* parent);


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        Menu::ItemLine m_itemLine;
    };

}


#endif // SIMPLE_BUTTON_LIST_HEADER
