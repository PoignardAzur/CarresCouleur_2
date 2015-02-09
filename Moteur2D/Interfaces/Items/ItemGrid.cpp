

#include "ItemGrid.h"


Menu::ItemGrid::ItemGrid()
{

}

Menu::ItemGrid::ItemGrid(const std::vector<std::vector< std::shared_ptr<AbstractItem> >>& items, sf::Vector2f gaps)
{
    set(items, gaps);
}

Menu::ItemGrid::ItemGrid(const std::vector<std::shared_ptr<AbstractItem>>& items, bool is_a_row, float gaps)
{
    if (is_a_row)
    setAsLine(items, gaps);

    else
    setAsColumn(items, gaps);
}


void Menu::ItemGrid::set(const std::vector<std::vector< std::shared_ptr<AbstractItem> >>& items, sf::Vector2f gaps)
{
    m_itemLines = items;
    m_gaps = gaps;

    updateOwnSize();
    setItemsParent();
}


void Menu::ItemGrid::setAsLine(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps)
{
    m_itemLines.resize(1);
    m_itemLines[0] = items;

    m_gaps = sf::Vector2f(gaps, 0);

    updateOwnSize();
    setItemsParent();
}

void Menu::ItemGrid::setAsColumn(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps)
{
    m_itemLines.resize(items.size());

    for (size_t i = 0; i < items.size(); ++i)
    {
        m_itemLines[i].resize(1, items[i]);
    }

    m_gaps = sf::Vector2f(0, gaps);

    updateOwnSize();
    setItemsParent();
}

void Menu::ItemGrid::setItemsParent()
{
    for (auto& itemLine : m_itemLines)
    {
        for (auto& item : itemLine)
        {
            if (item)
            item->setParent(this);
        }
    }
}

void Menu::ItemGrid::setGridSize(size_t x, size_t y, std::shared_ptr<AbstractItem> item)
{
    if (item)
    item->setParent(this);

    if (x > 0)
    m_itemLines.resize(y);

    else
    m_itemLines.resize(0);


    for (auto& itemLine : m_itemLines)
    {
        itemLine.resize(x, item);
    }

    updateOwnSize();
}

void Menu::ItemGrid::setGridSize(size_t x, size_t y, AbstractItem* item)
{
    setGridSize(x, y, std::shared_ptr<AbstractItem>(item));
}


void Menu::ItemGrid::setItem(size_t x, size_t y, std::shared_ptr<AbstractItem> item)
{
    m_itemLines[y][x] = item;

    if (item)
    item->setParent(this);

    updateOwnSize();
}

void Menu::ItemGrid::setItem(size_t x, size_t y, AbstractItem* item)
{
    setItem(x, y, std::shared_ptr<AbstractItem>(item));
}




void Menu::ItemGrid::setInternPosition(Alignement align, sf::Vector2f gaps)
{
    m_gaps = gaps;
    m_align = align;
    updateCellSizes();
}

void Menu::ItemGrid::expandToFill(sf::Vector2f nSize, bool allowNegativeSizes)
{
    if (!allowNegativeSizes)
    {
        if (nSize.x < m_size.x - m_gaps.x * (columns() - 1))
        nSize.x = m_size.x - m_gaps.x * (columns() - 1);

        if (nSize.y < m_size.y - m_gaps.y * (lines() - 1))
        nSize.y = m_size.y - m_gaps.y * (lines() - 1);
    }

    if (nSize.x < 0)
    nSize.x = 0;

    if (nSize.y < 0)
    nSize.y = 0;

    m_gaps.x += (nSize - m_size).x / (columns() - 1);
    m_gaps.y += (nSize - m_size).y / (lines() - 1);

    updateCellSizes();
}



sf::Vector2f Menu::ItemGrid::getSize() const
{
    return m_size;
}

size_t Menu::ItemGrid::lines() const
{
    return m_itemLines.size();
}

size_t Menu::ItemGrid::columns() const
{
    if (m_itemLines.size())
    return m_itemLines[0].size();

/// else
    return 0;
}



void Menu::ItemGrid::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    for (size_t l = 0; l < lines(); l++)
    {
        for (size_t c = 0; c < columns(); c++)
        {
            sf::FloatRect rect(position.x + m_columnOffsets[c], position.y + m_lineOffsets[l], m_columnWidths[c], m_lineHeights[l]);

            if (isHitboxDrawn)
            {
                sf::RectangleShape hitbox(sf::Vector2f(rect.width, rect.height));
                hitbox.setPosition(rect.left, rect.top);
                hitbox.setFillColor(sf::Color( hashToColor(position.x + 128), hashToColor(position.y + 128), hashToColor(rect.width + rect.height) ));

                target.draw(hitbox);
            }

            m_itemLines[l][c]->drawInBox(target, rect, m_align, isHitboxDrawn);
        }
    }
}


void Menu::ItemGrid::updateOwnSize()
{
    // Finds the maximum height of each line
    m_lineHeights.resize(lines());
    m_lineOffsets.resize(lines());

    for (size_t l = 0; l < lines(); l++)
    {
        float maxHeight = 0;

        for (auto& item : m_itemLines[l])
        {
            if (item && item->getSize().y > maxHeight)
            maxHeight = item->getSize().y;
        }

        m_lineHeights[l] = maxHeight;
    }

    // Finds the maximm width of each column
    m_columnWidths.resize(columns());
    m_columnOffsets.resize(columns());

    for (size_t c = 0; c < columns(); c++)
    {
        float maxWidth = 0;

        for (auto& itemLine : m_itemLines)
        {
            if (itemLine[c] && itemLine[c]->getSize().x > maxWidth)
            maxWidth = itemLine[c]->getSize().x;
        }

        m_columnWidths[c] = maxWidth;
    }


    updateCellSizes();
}


void Menu::ItemGrid::updateCellSizes()
{
    if (!lines() || !columns())
    {
        m_size = sf::Vector2f(0,0);
        return;
    }

/// else
    m_lineOffsets[0] = 0;
    m_columnOffsets[0] = 0;

    for (size_t l = 1; l < lines(); l++)
    {
        m_lineOffsets[l] = m_lineOffsets[l - 1] + m_lineHeights[l - 1] + m_gaps.y;
    }

    for (size_t c = 1; c < columns(); c++)
    {
        m_columnOffsets[c] = m_columnOffsets[c - 1] + m_columnWidths[c - 1] + m_gaps.x;
    }

    m_size.y = m_lineOffsets[lines()-1] + m_lineHeights[lines()-1];
    m_size.x = m_columnOffsets[columns()-1] + m_columnWidths[columns()-1];

    updateParentSize();
}








