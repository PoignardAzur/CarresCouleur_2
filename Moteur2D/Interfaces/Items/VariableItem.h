

#ifndef VARIABLE_MENU_ITEM_HEADER
#define VARIABLE_MENU_ITEM_HEADER


#include "AbstractItem.h"
#include <vector>
#include <memory>


namespace Menu
{

    class VariableItem : public AbstractItem
    {
        public :

        enum ItemSize { MinimumOne, MaximumOne, Dynamic };

        VariableItem();
        explicit VariableItem(const std::vector<std::shared_ptr<AbstractItem>>& items, size_t selectedOne = 0, ItemSize s = MaximumOne);

        void addItem(AbstractItem* item);
        void setItems(const std::vector<std::shared_ptr<AbstractItem>>& items, size_t selectedOne = 0);
        const std::vector<std::shared_ptr<AbstractItem>>& getItems() const;

        void selectItem(size_t n);
        size_t itemSelected() const;

        sf::Vector2f getSize() const;
        void setSize(ItemSize s);


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        std::vector<std::shared_ptr<AbstractItem>> m_items;
        size_t m_drawnItem;

        sf::Vector2f m_sizeValue;
        ItemSize m_size;       // if true, the size given is the biggest frame's size; if false, the size given is the smallest frame's size
    };


}



#endif // VARIABLE_MENU_ITEM_HEADER



