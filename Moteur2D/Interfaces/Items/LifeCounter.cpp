

#include "LifeCounter.hpp"




Menu::LifeCounter::LifeCounter()
{
    setGaps(0);
    m_counter = std::shared_ptr<Counter>(new Counter());
    m_lifeSprite = std::shared_ptr<Sprite>(new Sprite());
    m_cross = std::shared_ptr<Text>(new Text());

    m_count = 0;
    m_maxDrawable = 0;
    m_cross->setString("x");
}


void Menu::LifeCounter::setValue(int n)
{
    m_count = n;
    updateGrid();
}

void Menu::LifeCounter::setBounds(int maxDrawable, int max)
{
    m_maxDrawable = maxDrawable;
    m_counter->setBounds(0, max);

    updateGrid();
}


void Menu::LifeCounter::setRightAligned(bool rightAligned)
{
    m_counter->setRightAligned(rightAligned);
    m_rightAligned = rightAligned;

    updateGrid();
}

void Menu::LifeCounter::setSprite(const sf::Sprite& spr)
{
    m_lifeSprite->set(spr);
}


void Menu::LifeCounter::setGaps(float gap)
{
    m_gap = gap;
    m_row.setInternPosition(MiddleBottomSide, gap);
}



void Menu::LifeCounter::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    sf::FloatRect box(position.x, position.y, getSize().x, getSize().y);

    m_row.drawInBox(target, box, m_rightAligned ? BottomRightCorner : BottomLeftCorner, isHitboxDrawn);
}


void Menu::LifeCounter::setFontStyle(const FontStyle& f)
{
    m_counter->setFont(f);
    m_cross->setFont(f);
}


sf::Vector2f Menu::LifeCounter::getSize() const
{
    float height = m_lifeSprite->getSize().y > m_counter->getSize().y ? m_lifeSprite->getSize().y : m_counter->getSize().y;
    float width1 = m_lifeSprite->getSize().x * m_maxDrawable + m_gap * (m_maxDrawable - 1);
    float width2 = m_lifeSprite->getSize().x + m_gap + m_counter->getSize().x;

    return sf::Vector2f(width1 > width2 ? width1 : width2, height);
}


void Menu::LifeCounter::updateGrid()
{
    if (m_count > m_maxDrawable)
    {
        m_row.setItemsCount(3);

        if (m_rightAligned)
        {
            m_row.setItem(0, m_counter);
            m_row.setItem(1, m_cross);
            m_row.setItem(2, m_lifeSprite);
        }

        else
        {
            m_row.setItem(2, m_counter);
            m_row.setItem(1, m_cross);
            m_row.setItem(0, m_lifeSprite);
        }

        m_counter->setValue(m_count);
    }

    else
    {
        m_row.setItemsCount(0);
        m_row.setItemsCount(m_count, m_lifeSprite);
    }

    updateParentSize();
}





