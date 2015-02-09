

#include "ItemBox.h"


Menu::ItemBox::ItemBox(AbstractItem* item, Alignement a, float x_offset, float y_offset)
{
    setSize(sf::Vector2f(0,0), true);
    setItem(item);
    setAlignement(a, x_offset, y_offset);
}


std::unique_ptr<Menu::AbstractItem> Menu::ItemBox::setItem(AbstractItem* item)
{
    std::unique_ptr<AbstractItem> item_(item);
    std::swap(m_item, item_);

    if (m_item)
    m_item->setParent(this);

    updateParentSize();

    return item_;
}

void Menu::ItemBox::setColor(sf::Color c)
{
    m_boxColor = c;
}

void Menu::ItemBox::setAlignement(Alignement a, float x_offset, float y_offset)
{
    m_align = a;
    m_gaps = sf::Vector2f(x_offset, y_offset);
}

void Menu::ItemBox::setSize(sf::Vector2f size, bool relative)
{
    m_size = size;
    m_relative = relative;

    updateParentSize();
}


void Menu::ItemBox::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    if (m_item)
    {
        if (!isHitboxDrawn && m_boxColor.a != 0)
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




