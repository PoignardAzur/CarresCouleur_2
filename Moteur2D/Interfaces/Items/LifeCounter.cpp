

#include "LifeCounter.h"




Menu::LifeCounter::LifeCounter()
{
    m_grid.setInternPosition(MiddleBottomSide, sf::Vector2f(0,0));
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
    m_grid.setInternPosition(MiddleBottomSide, sf::Vector2f(m_gap, 0));
}



void Menu::LifeCounter::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    sf::FloatRect box(position.x, position.y, getSize().x, getSize().y);

    m_grid.drawInBox(target, box, m_rightAligned ? BottomRightCorner : BottomLeftCorner, isHitboxDrawn);
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
        m_grid.setGridSize(3, 1);

        if (m_rightAligned)
        {
            m_grid.setItem(0, 0, m_counter);
            m_grid.setItem(1, 0, m_cross);
            m_grid.setItem(2, 0, m_lifeSprite);
        }

        else
        {
            m_grid.setItem(2, 0, m_counter);
            m_grid.setItem(1, 0, m_cross);
            m_grid.setItem(0, 0, m_lifeSprite);
        }

        m_counter->setValue(m_count);
    }

    else
    {
        m_grid.setGridSize(0, 0);
        m_grid.setGridSize(m_count, 1, m_lifeSprite);
    }

    updateParentSize();
}





