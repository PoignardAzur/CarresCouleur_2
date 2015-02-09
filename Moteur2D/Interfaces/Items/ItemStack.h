


#ifndef MENU_ITEM_STACK_HEADER
#define MENU_ITEM_STACK_HEADER

#include "AbstractItem.h"
#include <memory>

namespace Menu
{

    class ItemStack : public AbstractItem
    {
        public :

        using AbsItemPtr = std::unique_ptr<AbstractItem>;

        ItemStack();
        ItemStack(std::vector<std::pair<AbsItemPtr, Alignement>> items, bool sizeIsMax = true);

        void setItems(std::vector<std::pair<AbsItemPtr, Alignement>> items, bool sizeIsMax = true);
        void addItem(AbstractItem* item, Alignement align);
        sf::Vector2f getSize() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        std::vector<std::pair<AbsItemPtr, Alignement>> m_items;
        sf::Vector2f m_size;
        void updateOwnSize();
        bool m_sizeIsMax;
    };

}



#endif // MENU_ITEM_STACK_HEADER



