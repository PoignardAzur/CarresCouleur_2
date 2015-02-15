
#include "AbstractEndCreditsScreen.hpp"

const int DEFAULT_CREDITS_SPEED = 60;


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

void AbstractEndCreditsScreen::drawIn(DrawerAbstraction& window, float dt) const
{
    for (const auto& risingItem : m_risingItemFile)
    {
        sf::FloatRect box(m_targetBounds.left, m_targetBounds.height - (risingItem.height + dt * m_speed), m_targetBounds.width, m_targetBounds.top);
        risingItem.item->drawInBox(window, box, Menu::MiddleTopSide);
    }
}

void AbstractEndCreditsScreen::update(float dt)
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

        pushItem(0);
    }

    while (!m_itemFile.empty() && lastItemHeight() > -m_margin)
    {
        pushItem(lastItemHeight() - (m_gap + m_risingItemFile.back().item->getSize().y));
    }
}

bool AbstractEndCreditsScreen::isDone() const
{
    return (m_itemFile.empty() && m_risingItemFile.empty()) || AbstractGameInterface::isDone();
}

void AbstractEndCreditsScreen::pushItem(float height)
{
    if (m_itemFile.empty())
    return;

    m_risingItemFile.push_back(RisingItem());
    m_risingItemFile.back().height = height;
    m_risingItemFile.back().item = std::move(m_itemFile.front());
    m_itemFile.pop_front();
}

float AbstractEndCreditsScreen::lastItemHeight()
{
    return m_risingItemFile.back().height;
}

void AbstractEndCreditsScreen::add_item(std::unique_ptr<Menu::ItemAbstraction> item)
{
    m_itemFile.push_back(mv(item));
}

