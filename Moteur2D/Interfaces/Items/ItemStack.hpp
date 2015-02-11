


#ifndef MENU_ITEM_STACK_HEADER
#define MENU_ITEM_STACK_HEADER

#include "ItemAbstraction.hpp"
#include <memory>

namespace Menu
{

    class ItemStack : public ItemAbstraction
    {
        public :

        using AbsItemPtr = std::unique_ptr<ItemAbstraction>;

        ItemStack();
        ItemStack(std::vector<std::pair<AbsItemPtr, Alignement>> items, bool sizeIsMax = true);

        void setItems(std::vector<std::pair<AbsItemPtr, Alignement>> items, bool sizeIsMax = true);
        void addItem(ItemAbstraction* item, Alignement align);
        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        std::vector<std::pair<AbsItemPtr, Alignement>> m_items;
        sf::Vector2f m_size;
        void updateOwnSize();
        bool m_sizeIsMax;
    };

}



#endif // MENU_ITEM_STACK_HEADER



