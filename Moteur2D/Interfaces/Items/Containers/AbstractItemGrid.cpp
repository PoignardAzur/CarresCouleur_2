
#include "AbstractItemGrid.hpp"


void Menu::AbstractItemGrid::setInternAlignement(Alignement align)
{
    m_align = align;
}

sf::Vector2f Menu::AbstractItemGrid::getSize() const
{
    return m_size;
}

size_t Menu::AbstractItemGrid::getLinesCount(bool verticalLines) const
{
    return verticalLines ? getColumnsCount() : getRowsCount();
}

void Menu::AbstractItemGrid::expandToFill(float& currentGaps, float newSize, bool vertical, bool allowNegativeGaps)
{
    float& currentSize = vertical ? m_size.y : m_size.x;
    size_t itemsCount = getLinesCount(!vertical);

    if (!allowNegativeGaps)
    {
        float minSize = currentSize - currentGaps * (itemsCount - 1);

        if (newSize < minSize)
        newSize = minSize;
    }

    if (newSize < 0)
    newSize = 0;

    currentGaps += (newSize - currentSize) / (itemsCount - 1);
    currentSize = newSize;
}


void Menu::AbstractItemGrid::drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    for (size_t c = 0; c < getColumnsCount(); ++c)
    {
        for (size_t r = 0; r < getRowsCount(); ++r)
        {
            drawItemIn(c, r, target, position, isHitboxDrawn);
        }
    }
}

void Menu::AbstractItemGrid::drawItemIn(size_t column, size_t row, DrawerAbstraction& target, sf::Vector2f gridPosition, bool isHitboxDrawn) const
{
    sf::FloatRect rect(gridPosition.x + getColumnOffset(column, true), gridPosition.y + getRowOffset(row, true),
                       getColumnWidth(column), getRowHeight(row));

    if (isHitboxDrawn)
    {
        sf::RectangleShape hitbox(sf::Vector2f(rect.width, rect.height));
        hitbox.setPosition(rect.left, rect.top);
        hitbox.setFillColor(sf::Color( hashToColor(gridPosition.x + 128), hashToColor(gridPosition.y + 128), hashToColor(rect.width + rect.height) ));

        target.draw(hitbox);
    }

    getItem(column, row).drawInBox(target, rect, m_align, isHitboxDrawn);
}


float Menu::AbstractItemGrid::getLineSize(size_t line, bool verticalLine) const
{
    size_t itemsCount = getLinesCount(!verticalLine);
    float maxSize = 0;

    for (size_t i = 0; i < itemsCount; ++i)
    {
        float itemSize = verticalLine ? getItem(line, i).getSize().x : getItem(i, line).getSize().y;

        if (maxSize < itemSize)
        maxSize = itemSize;
    }

    return maxSize;
}

std::vector<float> Menu::AbstractItemGrid::getLineSizes(bool verticalLines) const
{
    size_t linesCount = getLinesCount(verticalLines);
    std::vector<float> lineSizes(linesCount);

    for (size_t i = 0; i < linesCount; ++i)
    {
        lineSizes[i] = getLineSize(i, verticalLines);
    }

    return lineSizes;
}

std::vector<float> Menu::AbstractItemGrid::getLineOffsets(bool verticalOffsets) const
{
    size_t linesCount = getLinesCount(!verticalOffsets);
    std::vector<float> offsets(linesCount, 0);

    for (size_t i = 1; i < linesCount; ++i)
    {
        float nextOffset = offsets[i-1];
        nextOffset += verticalOffsets ? getRowHeight(i-1) : getColumnWidth(i-1);
        offsets[i] = nextOffset;
    }

    return offsets;
}


void Menu::AbstractItemGrid::updateOwnSize()
{
    updateLineSizes();
    updateLineOffsets();

    size_t lastColumn = getColumnsCount() - 1;
    size_t lastRow = getRowsCount() - 1;

    m_size.x = getColumnsCount() ? (getColumnOffset(lastColumn, true) + getColumnWidth(lastColumn)) : 0;
    m_size.y = getRowsCount() ? (getRowOffset(lastRow, true) + getRowHeight(lastRow)) : 0;

    updateParentSize();
}

void Menu::AbstractItemGrid::setItemsParent()
{
    for (size_t c = 0; c < getColumnsCount(); ++c)
    {
        for (size_t r = 0; r < getRowsCount(); ++r)
        {
            getItem(c, r).setParent(this);
        }
    }
}


void Menu::AbstractItemGrid::updateSizeValue(sf::Vector2f newSize)
{
    m_size = newSize;
    updateParentSize();
}

