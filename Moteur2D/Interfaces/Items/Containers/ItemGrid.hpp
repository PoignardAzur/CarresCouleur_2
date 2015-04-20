
#ifndef MENU_ITEM_GRID_HEADER
#define MENU_ITEM_GRID_HEADER

#include <memory>

#include "AbstractItemGrid.hpp"
#include "../Containers/ItemBox.hpp"


namespace Menu
{

    class ItemGrid : public AbstractItemGrid
    {
        public :

        using SharedItem = std::shared_ptr<AbstractItem>;

        ItemGrid();
        explicit ItemGrid(std::vector<std::vector<SharedItem>> items, sf::Vector2f gaps = sf::Vector2f(0,0));

        void set(std::vector<std::vector<SharedItem>> items, sf::Vector2f gaps = sf::Vector2f(0,0));
        void setAsLine(const std::vector<SharedItem>& items, bool vertical, float gaps = 0);

        void setGridSize(size_t x, size_t y, AbstractItem* item = nullptr);
        void setGridSize(size_t x, size_t y, SharedItem item);
        void setItem(size_t x, size_t y, AbstractItem* item);
        void setItem(size_t x, size_t y, SharedItem item);

        size_t getRowsCount() const;
        size_t getColumnsCount() const;

        void expandToFill(sf::Vector2f newSize, bool allowNegativeSizes = true);
        void setGaps(sf::Vector2f gaps);


        protected :

        const AbstractItem& getItem(size_t column, size_t row) const;
        AbstractItem& getItem(size_t column, size_t row);

        float getColumnWidth(size_t column) const;
        float getRowHeight(size_t row) const;

        float getColumnOffset(size_t column, bool addGaps) const;
        float getRowOffset(size_t row, bool addGaps) const;

        void updateLineSizes();
        void updateLineOffsets();

        /* INHERITED METHODS :

        void expandToFill(float& currentGaps, float newSize, bool vertical, bool allowNegativeSizes);

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void drawItemIn(size_t column, size_t row, DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;

        float getLineSize(size_t line, bool verticalLine) const;
        std::vector<float> getLineSizes(bool verticalLines) const;
        std::vector<float> getLineOffsets(bool verticalOffsets) const;

        void updateOwnSize();
        void setItemsParent();

        void updateSizeValue(sf::Vector2f newSize);
        */

        private :

        std::vector<std::vector<SharedItem>> m_itemRows;     // it's an array of lines, each one being an array of items
        sf::Vector2f m_gaps = sf::Vector2f();

        std::vector<float> m_rowHeights;
        std::vector<float> m_columnWidths;

        std::vector<float> m_rowOffsets;
        std::vector<float> m_columnOffsets;

        ItemBox m_voidBox;
    };

}


#endif // MENU_ITEM_GRID_HEADER
