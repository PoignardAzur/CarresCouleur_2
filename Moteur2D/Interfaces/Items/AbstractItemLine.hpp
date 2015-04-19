
#ifndef ABSTRACT_ITEM_LINE_HEADER
#define ABSTRACT_ITEM_LINE_HEADER

#include <memory>

#include "AbstractItemGrid.hpp"
#include "ItemBox.hpp"


namespace Menu
{

    class AbstractItemLine : public AbstractItemGrid
    {
        public :

        using SharedItem = std::shared_ptr<AbstractItem>;

        AbstractItemLine();
        explicit AbstractItemLine(std::vector<SharedItem> items, float gaps);

        void setItemsCount(size_t n, SharedItem item = SharedItem());
        void setItems(std::vector<SharedItem> items, float gaps = 0);
        void setItem(size_t n, SharedItem item);
        void addItem(SharedItem item = SharedItem());

        size_t getItemsCount() const;

        void setGaps(float gaps);
        void expandToFill(float newSize, bool allowNegativeSizes = true);


        protected :

        size_t getRowsCount() const;
        size_t getColumnsCount() const;

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

        float getLineSize(size_t line, bool verticalLine) const;
        std::vector<float> getLineOffsets(bool verticalOffsets) const;

        void updateOwnSize();
        void setItemsParent();

        void updateSizeValue(sf::Vector2f newSize);
        */

        virtual bool isVertical() const = 0;


        private :

        std::vector<SharedItem> m_items;
        float m_gaps = 0;

        std::vector<float> m_offsets;
        float m_lineSize = 0;

        ItemBox m_voidBox;
    };

}


#endif // ABSTRACT_ITEM_LINE_HEADER
