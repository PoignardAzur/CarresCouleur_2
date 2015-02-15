
#include "ItemLine.hpp"


// ITEM ROW
Menu::ItemRow::ItemRow()
{

}

Menu::ItemRow::ItemRow(const std::vector<std::shared_ptr<ItemAbstraction>>& items, float gaps)
{
    setItems(items, gaps);
}

void Menu::ItemRow::setItemsCount(size_t n, ItemAbstraction* item)
{
    m_grid.setGridSize(n, 1, item);
}

void Menu::ItemRow::setItemsCount(size_t n, std::shared_ptr<ItemAbstraction> item)
{
    m_grid.setGridSize(n, 1, item);
}

void Menu::ItemRow::setItems(const std::vector<std::shared_ptr<ItemAbstraction>>& items, float gaps)
{
    m_grid.setAsRow(items, gaps);
}

void Menu::ItemRow::setItem(size_t n, ItemAbstraction* item)
{
    m_grid.setItem(n, 0, item);
}

void Menu::ItemRow::setItem(size_t n, std::shared_ptr<ItemAbstraction> item)
{
    m_grid.setItem(n, 0, item);
}

void Menu::ItemRow::addItem(ItemAbstraction* item)
{
    setItemsCount(getItemsCount() + 1, item);
}

void Menu::ItemRow::addItem(std::shared_ptr<ItemAbstraction> item)
{
    setItemsCount(getItemsCount() + 1, item);
}

void Menu::ItemRow::setInternPosition(Alignement align, float gaps)
{
    m_grid.setInternPosition(align, sf::Vector2f(gaps, 0));
}

void Menu::ItemRow::expandToFill(float nSize, bool allowNegativeSizes)
{
    m_grid.expandToFill(sf::Vector2f(nSize, 0), allowNegativeSizes);
}

void Menu::ItemRow::setParent(ItemAbstraction* parent)
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

void Menu::ItemRow::drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    m_grid.drawIn(target, position, isHitboxDrawn);
}


// ITEM COLUMN
Menu::ItemColumn::ItemColumn()
{

}

Menu::ItemColumn::ItemColumn(const std::vector<std::shared_ptr<ItemAbstraction>>& items, float gaps)
{
    setItems(items, gaps);
}

void Menu::ItemColumn::setItemsCount(size_t n, ItemAbstraction* item)
{
    m_grid.setGridSize(1, n, item);
}

void Menu::ItemColumn::setItemsCount(size_t n, std::shared_ptr<ItemAbstraction> item)
{
    m_grid.setGridSize(1, n, item);
}

void Menu::ItemColumn::setItems(const std::vector<std::shared_ptr<ItemAbstraction>>& items, float gaps)
{
    m_grid.setAsColumn(items, gaps);
}

void Menu::ItemColumn::setItem(size_t n, ItemAbstraction* item)
{
    m_grid.setItem(0, n, item);
}

void Menu::ItemColumn::setItem(size_t n, std::shared_ptr<ItemAbstraction> item)
{
    m_grid.setItem(0, n, item);
}

void Menu::ItemColumn::addItem(ItemAbstraction* item)
{
    setItemsCount(getItemsCount() + 1, item);
}

void Menu::ItemColumn::addItem(std::shared_ptr<ItemAbstraction> item)
{
    setItemsCount(getItemsCount() + 1, item);
}

void Menu::ItemColumn::setInternPosition(Alignement align, float gaps)
{
    m_grid.setInternPosition(align, sf::Vector2f(0, gaps));
}

void Menu::ItemColumn::expandToFill(float nSize, bool allowNegativeSizes)
{
    m_grid.expandToFill(sf::Vector2f(0, nSize), allowNegativeSizes);
}

void Menu::ItemColumn::setParent(ItemAbstraction* parent)
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

void Menu::ItemColumn::drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    m_grid.drawIn(target, position, isHitboxDrawn);
}

