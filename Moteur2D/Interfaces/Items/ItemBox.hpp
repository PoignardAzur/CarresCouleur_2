

#ifndef MENU_ITEM_BOX_HEADER
#define MENU_ITEM_BOX_HEADER

#include <memory>
#include "ItemAbstraction.hpp"


namespace Menu
{

    class ItemBox : public ItemAbstraction
    {
        public :

        explicit ItemBox(ItemAbstraction* item = nullptr, Alignement a = Center, float x_offset = 0, float y_offset = 0);

        std::unique_ptr<ItemAbstraction> setItem(ItemAbstraction* item);      // returns a pointer owning the previous item
        void setColor(sf::Color c);
        void setAlignement(Alignement a, float x_offset, float y_offset);
        void setSize(sf::Vector2f size, bool relative = false);

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        std::unique_ptr<ItemAbstraction> m_item;
        Alignement m_align;

        sf::Color m_boxColor = sf::Color(0, 0, 0, 0);

        sf::Vector2f m_size;
        sf::Vector2f m_gaps;        // if m_gaps are positive, the item is drawn in a box smaller than indicated by getSize()
        bool m_relative;            // if m_gaps are negative, the item is drawn in a box bigger than indicated by getSize()
    };

}


#endif // MENU_ITEM_BOX_HEADER

