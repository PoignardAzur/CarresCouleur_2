
#include "Label.h"


Menu::Label::Label(AbstractItem* item, const std::string& str, FontStyle f, bool horizontalAlignement, float gap)
{
    setItem(item);
    setLabel(str);
    setAlignement(horizontalAlignement, gap);
    setFont(f);
}

void Menu::Label::setItem(AbstractItem* item)
{
    m_item = std::shared_ptr<AbstractItem>(item);

    if (m_item)
    m_item->setParent(this);
    setOwnSize();
}

void Menu::Label::setLabel(const std::string& str)
{
    m_label.setString(str);
    setOwnSize();
}

void Menu::Label::setFontStyle(const FontStyle& f)
{
    m_label.setFont(f);
    setOwnSize();
}

void Menu::Label::setAlignement(bool horizontal, float gap)
{
    m_horizontalAlignement = horizontal;
    m_gap = gap;

    setOwnSize();
}

sf::Vector2f Menu::Label::getSize() const
{
    return m_size;
}

void Menu::Label::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    sf::FloatRect box(position.x, position.y, getSize().x, getSize().y);

    if (m_horizontalAlignement)
    {
        m_label.drawInBox(target, box, BottomLeftCorner, isHitboxDrawn);

        if (m_item)
        m_item->drawInBox(target, box, BottomRightCorner, isHitboxDrawn);
    }

    else
    {
        m_label.drawInBox(target, box, TopLeftCorner, isHitboxDrawn);

        if (m_item)
        m_item->drawInBox(target, box, BottomLeftCorner, isHitboxDrawn);
    }
}

void Menu::Label::setOwnSize()
{
    if (!m_item)
    m_size = m_label.getSize();

    else if (m_horizontalAlignement)
    {
        m_size.x = m_label.getSize().x + m_item->getSize().x + m_gap;
        m_size.y = m_label.getSize().y > m_item->getSize().y ? m_label.getSize().y : m_item->getSize().y;
    }

    else
    {
        m_size.x = m_label.getSize().x > m_item->getSize().x ? m_label.getSize().x : m_item->getSize().x;
        m_size.y = m_label.getSize().y + m_item->getSize().y + m_gap;
    }
}


