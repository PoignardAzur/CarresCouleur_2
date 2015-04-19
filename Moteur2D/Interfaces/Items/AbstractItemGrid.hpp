
#ifndef ABSTRACT_MENU_ITEM_GRID_HEADER
#define ABSTRACT_MENU_ITEM_GRID_HEADER

#include <vector>

#include "AbstractItem.hpp"


namespace Menu
{

    class AbstractItemGrid : public AbstractItem
    {
        public :

        void setInternAlignement(Alignement align);

        sf::Vector2f getSize() const;


        protected :

        virtual size_t getRowsCount() const = 0;
        virtual size_t getColumnsCount() const = 0;

        size_t getLinesCount(bool verticalLines) const;

        void expandToFill(float& currentGaps, float newSize, bool vertical, bool allowNegativeGaps);

        virtual const AbstractItem& getItem(size_t column, size_t row) const = 0;
        virtual AbstractItem& getItem(size_t column, size_t row) = 0;

        void drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const;
        void drawItemIn(size_t column, size_t row, DrawerAbstraction& target, sf::Vector2f gridPosition, bool isHitboxDrawn) const;

        virtual float getColumnWidth(size_t column) const = 0;
        virtual float getRowHeight(size_t row) const = 0;

        virtual float getColumnOffset(size_t column, bool addGaps) const = 0;
        virtual float getRowOffset(size_t row, bool addGaps) const = 0;

        float getLineSize(size_t line, bool verticalLine) const;
        std::vector<float> getLineSizes(bool verticalLines) const;
        std::vector<float> getLineOffsets(bool verticalOffsets) const;

        virtual void updateLineSizes() = 0;
        virtual void updateLineOffsets() = 0;

        void updateOwnSize();
        void setItemsParent();

        void updateSizeValue(sf::Vector2f newSize);


        private :

        sf::Vector2f m_size;
        Alignement m_align;
    };

}


#endif // ABSTRACT_MENU_ITEM_GRID_HEADER
