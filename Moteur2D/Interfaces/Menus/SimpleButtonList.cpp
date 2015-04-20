
#include "SimpleButtonList.hpp"


Menu::SimpleButtonList::SimpleButtonList(bool isMenuVertical, bool doesMenuLoop) : ButtonListAbstraction(isMenuVertical, doesMenuLoop)
{
    setVertical(isMenuVertical);
}


void Menu::SimpleButtonList::addItem(uptrt<Menu::AbstractItem> item)
{
    m_itemLine.addItem(move(item));
}

void Menu::SimpleButtonList::addButton(uptrt<Menu::ButtonAbstraction> button)
{
    Menu::ButtonListAbstraction::addButtonPointer(button.get());
    m_itemLine.addItem(move(button));
}


void Menu::SimpleButtonList::setVertical(bool isMenuVertical)
{
    Menu::ButtonListAbstraction::setVertical(isMenuVertical);
    m_itemLine.setVertical(isMenuVertical);
}

sf::Vector2f Menu::SimpleButtonList::getSize() const
{
    return m_itemLine.getSize();
}

void Menu::SimpleButtonList::setParent(AbstractItem* parent)
{
    m_itemLine.setParent(parent);
}


void Menu::SimpleButtonList::setGapsBetweenButtons(float gaps)
{
    m_itemLine.setGaps(gaps);
}

void Menu::SimpleButtonList::drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    m_itemLine.drawIn(target, position, isHitboxDrawn);
}

