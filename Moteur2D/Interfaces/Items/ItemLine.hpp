

#ifndef ITEM_LINE_HEADER
#define ITEM_LINE_HEADER

#include "ItemGrid.hpp"


namespace Menu
{

    class ItemRow : public ItemAbstraction
    {
        public :

        ItemRow();
        ItemRow(const std::vector<std::shared_ptr<ItemAbstraction>>& items, float gaps = 0);

        void setItemsCount(size_t n, ItemAbstraction* item = nullptr);
        void setItemsCount(size_t n, std::shared_ptr<ItemAbstraction> item);
        void setItems(const std::vector<std::shared_ptr<ItemAbstraction>>& items, float gaps = 0);
        void setItem(size_t n, ItemAbstraction* item);
        void setItem(size_t n, std::shared_ptr<ItemAbstraction> item);
        void addItem(ItemAbstraction* item);
        void addItem(std::shared_ptr<ItemAbstraction> item);

        void setInternPosition(Alignement align, float gaps);
        void expandToFill(float nSize, bool allowNegativeSizes = true);

        void setParent(ItemAbstraction* parent);

        sf::Vector2f getSize() const;
        size_t getItemsCount() const;


        protected :

        virtual void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        ItemGrid m_grid;
    };


    class ItemColumn : public ItemAbstraction
    {
        public :

        ItemColumn();
        ItemColumn(const std::vector<std::shared_ptr<ItemAbstraction>>& items, float gaps = 0);

        void setItemsCount(size_t n, ItemAbstraction* item = nullptr);
        void setItemsCount(size_t n, std::shared_ptr<ItemAbstraction> item);
        void setItems(const std::vector<std::shared_ptr<ItemAbstraction>>& items, float gaps = 0);
        void setItem(size_t n, ItemAbstraction* item);
        void setItem(size_t n, std::shared_ptr<ItemAbstraction> item);
        void addItem(ItemAbstraction* item);
        void addItem(std::shared_ptr<ItemAbstraction> item);

        void setInternPosition(Alignement align, float gaps);
        void expandToFill(float nSize, bool allowNegativeSizes = true);

        void setParent(ItemAbstraction* parent);

        sf::Vector2f getSize() const;
        size_t getItemsCount() const;


        protected :

        virtual void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        ItemGrid m_grid;
    };

}

#endif // ITEM_LINE_HEADER
