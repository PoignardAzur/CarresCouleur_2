

#include "AbstractEndCreditsScreen.h"


void AbstractEndCreditsScreen::setMargin(float margin)
{
    m_margin = margin;
}

void AbstractEndCreditsScreen::setGap(float gapBetweenItems)
{
    m_gap = gapBetweenItems;
}

void AbstractEndCreditsScreen::setSpeed(float verticalItemSpeed)
{
    m_speed = verticalItemSpeed;
}

void AbstractEndCreditsScreen::setTargetBounds(sf::FloatRect bounds)
{
    m_targetBounds = bounds;
}

sf::FloatRect AbstractEndCreditsScreen::getTargetBounds()
{
    return m_targetBounds;
}

void AbstractEndCreditsScreen::drawIn(AbstractDrawer& window, float dt)
{
    for (const auto& risingItem : m_risingItemFile)
    {
        sf::FloatRect box(m_targetBounds.left, m_targetBounds.height - (risingItem.height + dt * m_speed), m_targetBounds.width, 1);
        risingItem.item->drawInBox(window, box, Menu::MiddleTopSide);
    }
}

void AbstractEndCreditsScreen::update(const float& dt)
{
    for (auto& risingItem : m_risingItemFile)
    {
        risingItem.height += dt * m_speed;
    }

    while (!m_risingItemFile.empty() && m_risingItemFile.front().height - m_risingItemFile.front().item->getSize().y > m_targetBounds.height)
    {
        m_risingItemFile.pop_front();
    }

    if (m_risingItemFile.empty())
    {
        if (m_itemFile.empty())
        return;

        //else
        m_risingItemFile.push_back(RisingItem());
        m_risingItemFile.back().height = 0;
        m_risingItemFile.back().item = std::move(m_itemFile.front());
        m_itemFile.pop_front();
    }

    while (!m_itemFile.empty() && m_risingItemFile.back().height > -m_margin)
    {
        float height = m_risingItemFile.back().height - (m_gap + m_risingItemFile.back().item->getSize().y);
        m_risingItemFile.push_back(RisingItem());
        m_risingItemFile.back().height = height;
        m_risingItemFile.back().item = std::move(m_itemFile.front());
        m_itemFile.pop_front();
    }
}

void AbstractEndCreditsScreen::add_item(std::unique_ptr<Menu::AbstractItem> item)
{
    m_itemFile.push_back(std::move(item));
}

