
#include "AbstractItemLine.hpp"


Menu::AbstractItemLine::AbstractItemLine()
{

}

Menu::AbstractItemLine::AbstractItemLine(std::vector<SharedItem> items, float gaps)
{
    setItems(std::move(items), gaps);
}

void Menu::AbstractItemLine::setItemsCount(size_t n, SharedItem item)
{
    m_items.resize(n, item);

    if (item)
    item->setParent(this);

    updateOwnSize();
}

void Menu::AbstractItemLine::setItems(std::vector<SharedItem> items, float gaps)
{
    m_items = std::move(items);
    m_gaps = gaps;

    updateOwnSize();
    setItemsParent();
}

void Menu::AbstractItemLine::setItem(size_t n, SharedItem item)
{
    m_items[n] = std::move(item);

    if (item)
    item->setParent(this);

    updateOwnSize();
}

void Menu::AbstractItemLine::addItem(SharedItem item)
{
    m_items.push_back(item);

    if (item)
    item->setParent(this);

    updateOwnSize();
}

size_t Menu::AbstractItemLine::getItemsCount() const
{
    return m_items.size();
}


void Menu::AbstractItemLine::setGaps(float gaps)
{
    sf::Vector2f deltaSize(0,0);

    if (isVertical())
    {
        deltaSize.y = (gaps - m_gaps) * (std::max<size_t>(getRowsCount(), 1) - 1);
    }

    else
    {
        deltaSize.x = (gaps - m_gaps) * (std::max<size_t>(getColumnsCount(), 1) - 1);
    }

    updateSizeValue(getSize() + deltaSize);
    m_gaps = gaps;
}

void Menu::AbstractItemLine::expandToFill(float newSize, bool allowNegativeGaps)
{
    Menu::AbstractItemGrid::expandToFill(m_gaps, newSize, isVertical(), allowNegativeGaps);
}


size_t Menu::AbstractItemLine::getRowsCount() const
{
    return isVertical() ? getItemsCount() : 1;
}

size_t Menu::AbstractItemLine::getColumnsCount() const
{
    return isVertical() ? 1 : getItemsCount();
}

const Menu::AbstractItem& Menu::AbstractItemLine::getItem(size_t column, size_t row) const
{
    return const_cast<AbstractItemLine*>(this)->getItem(column, row);
}

Menu::AbstractItem& Menu::AbstractItemLine::getItem(size_t column, size_t row)
{
    SharedItem item = m_items.empty() ? nullptr : (isVertical() ? m_items[row] : m_items[column]);

    if (item)
    return *item;

    else
    return m_voidBox;
}


float Menu::AbstractItemLine::getColumnWidth(size_t column) const
{
    return isVertical() ? m_lineSize : m_items[column]->getSize().x;
}

float Menu::AbstractItemLine::getRowHeight(size_t row) const
{
    return isVertical() ? m_items[row]->getSize().y : m_lineSize;
}

float Menu::AbstractItemLine::getColumnOffset(size_t column, bool addGaps) const
{
    return isVertical() ? 0 : m_offsets[column] + (addGaps ? m_gaps * column : 0);
}

float Menu::AbstractItemLine::getRowOffset(size_t row, bool addGaps) const
{
    return isVertical() ? m_offsets[row] + (addGaps ? m_gaps * row : 0) : 0;
}


void Menu::AbstractItemLine::updateLineSizes()
{
    m_lineSize = getLineSize(0, isVertical());
}

void Menu::AbstractItemLine::updateLineOffsets()
{
    m_offsets = getLineOffsets(isVertical());
}

