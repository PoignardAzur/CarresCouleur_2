
#include "ItemBox.hpp"


Menu::ItemBox::ItemBox(uptrt<AbstractItem> item, Alignement a, sf::Vector2f gaps)
{
    setItem(move(item));
    setAlignement(a, gaps);
}


uptrt<Menu::AbstractItem> Menu::ItemBox::setItem(uptrt<AbstractItem> item)
{
    std::swap(m_item, item);

    if (m_item)
    m_item->setParent(this);

    updateParentSize();

    return item;
}

void Menu::ItemBox::setColor(sf::Color c)
{
    m_boxColor = c;
}

void Menu::ItemBox::setAlignement(Alignement a, sf::Vector2f gaps)
{
    m_align = a;
    m_gaps = gaps;
}

void Menu::ItemBox::setSize(sf::Vector2f size, bool relative)
{
    m_size = size;
    m_relative = relative;

    updateParentSize();
}


void Menu::ItemBox::drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    if (m_item)
    {
        if (!isHitboxDrawn && m_boxColor.a != 0) // if the hitbox is drawn, the ItemBox isn't to avoid masking it
        {
            sf::RectangleShape rect(getSize());
            rect.setPosition(position);
            rect.setFillColor(m_boxColor);
            target.draw(rect);
        }

        sf::FloatRect box(position.x + m_gaps.x, position.y + m_gaps.y, getSize().x - 2 * m_gaps.x, getSize().y - 2 * m_gaps.y);
        m_item->drawInBox(target, box, m_align, isHitboxDrawn);
    }
}

sf::Vector2f Menu::ItemBox::getSize() const
{
    if (m_relative && m_item)
    return m_size + m_item->getSize();

    else
    return m_size;
}

