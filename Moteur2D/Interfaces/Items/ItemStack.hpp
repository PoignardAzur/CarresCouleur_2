
#ifndef MENU_ITEM_STACK_HEADER
#define MENU_ITEM_STACK_HEADER

#include "ItemAbstraction.hpp"
#include "up.hpp"

namespace Menu
{

    class ItemStack : public ItemAbstraction
    {
        public :

        using ItemAlignPair = std::pair<up_t<ItemAbstraction>, Alignement>;

        ItemStack();
        ItemStack(std::vector<ItemAlignPair> items, bool sizeIsMax = true);

        void setItems(std::vector<ItemAlignPair> items, bool sizeIsMax = true);
        void addItem(up_t<ItemAbstraction> item, Alignement align);

        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void updateOwnSize();


        private :

        std::vector<std::pair<up_t<ItemAbstraction>, Alignement>> m_items;
        sf::Vector2f m_size;    // if m_sizeIsMax is true, then m_size is worth the greatest Item's size
        bool m_sizeIsMax;       // else it's worth the smallest item's size
    };

}


#endif // MENU_ITEM_STACK_HEADER
