
#ifndef MENU_ITEM_BOX_HEADER
#define MENU_ITEM_BOX_HEADER

#include "up.hpp"
#include "../AbstractItem.hpp"


namespace Menu
{

    class ItemBox : public AbstractItem
    {
        public :

        explicit ItemBox(uptrt<AbstractItem> item = nullptr, Alignement a = Center, sf::Vector2f gaps = sf::Vector2f(0,0));

        uptrt<AbstractItem> setItem(uptrt<AbstractItem> item);          // returns a pointer owning the previous item
        void setColor(sf::Color c);                                         // makes the box not transparent even when !isHitboxDrawn

        void setAlignement(Alignement a, sf::Vector2f gaps);                // see the code of drawImageIn() for how these
        void setSize(sf::Vector2f size, bool relative = false);             // two functions interact with each other
        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        uptrt<AbstractItem> m_item;
        Alignement m_align;

        sf::Color m_boxColor = sf::Color(0,0,0, 0);
        sf::Vector2f m_size = sf::Vector2f(0, 0);
        bool m_relative;

        sf::Vector2f m_gaps;        // if m_gaps are positive, the item is drawn in a box smaller than indicated by getSize()
    };                              // if m_gaps are negative, the item is drawn in a box bigger than indicated by getSize()

}


#endif // MENU_ITEM_BOX_HEADER
