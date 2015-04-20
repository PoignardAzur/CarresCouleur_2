
#include "ItemGrid.hpp"


Menu::ItemGrid::ItemGrid()
{

}

Menu::ItemGrid::ItemGrid(std::vector<std::vector<SharedItem>> items, sf::Vector2f gaps)
{
    set(std::move(items), gaps);
}

void Menu::ItemGrid::set(std::vector<std::vector<SharedItem>> items, sf::Vector2f gaps)
{
    m_itemRows = std::move(items);
    m_gaps = gaps;

    updateOwnSize();
    setItemsParent();
}

void Menu::ItemGrid::setAsLine(const std::vector<SharedItem>& items, bool vertical, float gaps)
{
    if (vertical)
    {
        m_itemRows.resize(items.size());

        for (size_t i = 0; i < items.size(); ++i)
        {
            m_itemRows[i].resize(1, items[i]);
        }

        m_gaps = sf::Vector2f(0, gaps);
    }

    else
    {
        m_itemRows.resize(1);
        m_itemRows[0] = items;

        m_gaps = sf::Vector2f(gaps, 0);
    }

    updateOwnSize();
    setItemsParent();
}


void Menu::ItemGrid::setGridSize(size_t x, size_t y, AbstractItem* item)
{
    setGridSize(x, y, std::shared_ptr<AbstractItem>(item));
}

void Menu::ItemGrid::setGridSize(size_t x, size_t y, SharedItem item)
{
    if (item)
    item->setParent(this);

    m_itemRows.resize(y);

    for (auto& itemRow : m_itemRows)
    {
        itemRow.resize(x, item);
    }

    updateOwnSize();
}


void Menu::ItemGrid::setItem(size_t x, size_t y, AbstractItem* item)
{
    setItem(x, y, std::shared_ptr<AbstractItem>(item));
}

void Menu::ItemGrid::setItem(size_t x, size_t y, SharedItem item)
{
    m_itemRows[y][x] = item;

    if (item)
    item->setParent(this);

    updateOwnSize();
}


size_t Menu::ItemGrid::getRowsCount() const
{
    return m_itemRows.size();
}

size_t Menu::ItemGrid::getColumnsCount() const
{
    return m_itemRows.empty() ? 0 : m_itemRows.front().size();
}


void Menu::ItemGrid::expandToFill(sf::Vector2f newSize, bool allowNegativeSizes)
{
    Menu::AbstractItemGrid::expandToFill(m_gaps.x, newSize.x, false, allowNegativeSizes);
    Menu::AbstractItemGrid::expandToFill(m_gaps.y, newSize.y, true, allowNegativeSizes);
}

void Menu::ItemGrid::setGaps(sf::Vector2f gaps)
{
    sf::Vector2f deltaSize;
    deltaSize.x = (gaps.x - m_gaps.x) * (std::max<size_t>(getColumnsCount(), 1) - 1);
    deltaSize.y = (gaps.y - m_gaps.y) * (std::max<size_t>(getRowsCount(), 1) - 1);

    updateSizeValue(getSize() + deltaSize);
    m_gaps = gaps;
}


const Menu::AbstractItem& Menu::ItemGrid::getItem(size_t column, size_t row) const
{
    return const_cast<ItemGrid*>(this)->getItem(column, row);
}

Menu::AbstractItem& Menu::ItemGrid::getItem(size_t column, size_t row)
{
    SharedItem item = (m_itemRows.empty() || m_itemRows[row].empty()) ? nullptr : m_itemRows[row][column];

    if (item)
    return *item;

    else
    return m_voidBox;
}


float Menu::ItemGrid::getColumnWidth(size_t column) const
{
    return m_columnWidths[column];
}

float Menu::ItemGrid::getRowHeight(size_t row) const
{
    return m_rowHeights[row];
}

float Menu::ItemGrid::getColumnOffset(size_t column, bool addGaps) const
{
    return m_columnOffsets[column] + (addGaps ? column * m_gaps.x : 0);
}

float Menu::ItemGrid::getRowOffset(size_t row, bool addGaps) const
{
    return m_rowOffsets[row] + (addGaps ? row * m_gaps.y : 0);
}


void Menu::ItemGrid::updateLineSizes()
{
    m_rowHeights = getLineSizes(false);
    m_columnWidths = getLineSizes(true);
}

void Menu::ItemGrid::updateLineOffsets()
{
    m_rowOffsets = getLineOffsets(false);
    m_columnOffsets = getLineOffsets(true);
}

