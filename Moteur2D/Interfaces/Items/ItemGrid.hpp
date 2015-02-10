

#ifndef MENU_ITEM_GRID_HEADER
#define MENU_ITEM_GRID_HEADER

#include <vector>
#include <memory>

#include "AbstractItem.h"


namespace Menu
{

    class ItemGrid : public AbstractItem
    {
        public :

        ItemGrid();
        ItemGrid(const std::vector<std::vector< std::shared_ptr<AbstractItem> >>& items, sf::Vector2f gaps = sf::Vector2f(0,0));
        ItemGrid(const std::vector<std::shared_ptr<AbstractItem>>& items, bool is_a_row, float gaps = 0);

        void set(const std::vector<std::vector< std::shared_ptr<AbstractItem> >>& items, sf::Vector2f gaps = sf::Vector2f(0,0));
        void setAsLine(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps = 0);
        void setAsColumn(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps = 0);

        void setInternPosition(Alignement align, sf::Vector2f gaps);
        void expandToFill(sf::Vector2f nSize, bool allowNegativeSizes = true);

        void setGridSize(size_t x, size_t y, AbstractItem* item = nullptr);
        void setGridSize(size_t x, size_t y, std::shared_ptr<AbstractItem> item);
        void setItem(size_t x, size_t y, AbstractItem* item);
        void setItem(size_t x, size_t y, std::shared_ptr<AbstractItem> item);

        sf::Vector2f getSize() const;

        size_t lines() const;
        size_t columns() const;


        protected :

        void drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void updateCellSizes();
        void updateOwnSize();
        void setItemsParent();


        private :

        std::vector<std::vector< std::shared_ptr<AbstractItem> >> m_itemLines;     // it's an array of lines, each one being an array of item
        sf::Vector2f m_gaps;
        Alignement m_align;

        std::vector<float> m_lineOffsets;
        std::vector<float> m_columnOffsets;
        sf::Vector2f m_size;
        std::vector<float> m_lineHeights;
        std::vector<float> m_columnWidths;
    };

}


#endif // MENU_ITEM_GRID_HEADER
