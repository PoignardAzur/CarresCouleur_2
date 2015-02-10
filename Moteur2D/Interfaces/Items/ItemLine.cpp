
#include "ItemLine.hpp"


// ITEM ROW
Menu::ItemRow::ItemRow()
{

}

Menu::ItemRow::ItemRow(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps)
{
    setItems(items, gaps);
}

void Menu::ItemRow::setItemsCount(size_t n, AbstractItem* item)
{
    m_grid.setGridSize(n, 1, item);
}

void Menu::ItemRow::setItemsCount(size_t n, std::shared_ptr<AbstractItem> item)
{
    m_grid.setGridSize(n, 1, item);
}

void Menu::ItemRow::setItems(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps)
{
    m_grid.setAsLine(items, gaps);
}

void Menu::ItemRow::setItem(size_t n, AbstractItem* item)
{
    m_grid.setItem(n, 0, item);
}

void Menu::ItemRow::setItem(size_t n, std::shared_ptr<AbstractItem> item)
{
    m_grid.setItem(n, 0, item);
}

void Menu::ItemRow::setInternPosition(Alignement align, float gaps)
{
    m_grid.setInternPosition(align, sf::Vector2f(gaps, 0));
}

void Menu::ItemRow::expandToFill(float nSize, bool allowNegativeSizes)
{
    m_grid.expandToFill(sf::Vector2f(nSize, 0), allowNegativeSizes);
}

void Menu::ItemRow::setParent(AbstractItem* parent)
{
    m_grid.setParent(parent);
}

sf::Vector2f Menu::ItemRow::getSize() const
{
    return m_grid.getSize();
}

size_t Menu::ItemRow::getItemsCount() const
{
    return m_grid.columns();
}

void Menu::ItemRow::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    m_grid.drawIn(target, position, isHitboxDrawn);
}


// ITEM COLUMN
Menu::ItemColumn::ItemColumn()
{

}

Menu::ItemColumn::ItemColumn(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps)
{
    setItems(items, gaps);
}

void Menu::ItemColumn::setItemsCount(size_t n, AbstractItem* item)
{
    m_grid.setGridSize(1, n, item);
}

void Menu::ItemColumn::setItemsCount(size_t n, std::shared_ptr<AbstractItem> item)
{
    m_grid.setGridSize(1, n, item);
}

void Menu::ItemColumn::setItems(const std::vector<std::shared_ptr<AbstractItem>>& items, float gaps)
{
    m_grid.setAsColumn(items, gaps);
}

void Menu::ItemColumn::setItem(size_t n, AbstractItem* item)
{
    m_grid.setItem(0, n, item);
}

void Menu::ItemColumn::setItem(size_t n, std::shared_ptr<AbstractItem> item)
{
    m_grid.setItem(0, n, item);
}

void Menu::ItemColumn::setInternPosition(Alignement align, float gaps)
{
    m_grid.setInternPosition(align, sf::Vector2f(0, gaps));
}

void Menu::ItemColumn::expandToFill(float nSize, bool allowNegativeSizes)
{
    m_grid.expandToFill(sf::Vector2f(0, nSize), allowNegativeSizes);
}

void Menu::ItemColumn::setParent(AbstractItem* parent)
{
    m_grid.setParent(parent);
}

sf::Vector2f Menu::ItemColumn::getSize() const
{
    return m_grid.getSize();
}

size_t Menu::ItemColumn::getItemsCount() const
{
    return m_grid.lines();
}

void Menu::ItemColumn::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    m_grid.drawIn(target, position, isHitboxDrawn);
}

