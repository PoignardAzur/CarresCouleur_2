

#ifndef ITEM_LINE_HEADER
#define ITEM_LINE_HEADER

#include "ItemGrid.hpp"


namespace Menu
{

    class ItemRow : public AbstractItem
    {
        public :

        ItemRow();
        ItemRow(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps = 0);

        void setItemsCount(size_t n, AbstractItem* item = nullptr);
        void setItemsCount(size_t n, std::shared_ptr<AbstractItem> item);
        void setItems(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps = 0);
        void setItem(size_t n, AbstractItem* item);
        void setItem(size_t n, std::shared_ptr<AbstractItem> item);

        void setInternPosition(Alignement align, float gaps);
        void expandToFill(float nSize, bool allowNegativeSizes = true);

        void setParent(AbstractItem* parent);

        sf::Vector2f getSize() const;
        size_t getItemsCount() const;


        protected :

        virtual void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        ItemGrid m_grid;
    };


    class ItemColumn : public AbstractItem
    {
        public :

        ItemColumn();
        ItemColumn(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps = 0);

        void setItemsCount(size_t n, AbstractItem* item = nullptr);
        void setItemsCount(size_t n, std::shared_ptr<AbstractItem> item);
        void setItems(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps = 0);
        void setItem(size_t n, AbstractItem* item);
        void setItem(size_t n, std::shared_ptr<AbstractItem> item);

        void setInternPosition(Alignement align, float gaps);
        void expandToFill(float nSize, bool allowNegativeSizes = true);

        void setParent(AbstractItem* parent);

        sf::Vector2f getSize() const;
        size_t getItemsCount() const;


        protected :

        virtual void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;


        private :

        ItemGrid m_grid;
    };

}

#endif // ITEM_LINE_HEADER
