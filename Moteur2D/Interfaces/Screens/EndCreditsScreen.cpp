
#include "EndCreditsScreen.hpp"

const int DEFAULT_CREDITS_SPEED = 60;


void EndCreditsScreen::setMargin(float margin)
{
    m_margin = margin;
}

void EndCreditsScreen::setGap(float gapBetweenItems)
{
    m_gap = gapBetweenItems;
}

void EndCreditsScreen::setSpeed(float verticalItemSpeed)
{
    m_speed = verticalItemSpeed;
}

void EndCreditsScreen::setTargetBounds(sf::FloatRect bounds)
{
    m_targetBounds = bounds;
}

sf::FloatRect EndCreditsScreen::getTargetBounds()
{
    return m_targetBounds;
}

void EndCreditsScreen::drawIn(DrawerAbstraction& window, float dt) const
{
    drawCreditsIn(window, dt);
}

void EndCreditsScreen::drawCreditsIn(DrawerAbstraction& window, float dt) const
{
    for (const auto& risingItem : m_risingItemFile)
    {
        sf::FloatRect box(m_targetBounds.left, m_targetBounds.height - (risingItem.height + dt * m_speed), m_targetBounds.width, m_targetBounds.top);
        risingItem.item->drawInBox(window, box, Menu::MiddleTopSide);
    }
}

void EndCreditsScreen::update(float dt)
{
    // Rise items
    for (auto& risingItem : m_risingItemFile)
    {
        risingItem.height += dt * m_speed;
    }

    // Delete items that are no longer visible
    while (!m_risingItemFile.empty() && m_risingItemFile.front().height - m_risingItemFile.front().item->getSize().y > m_targetBounds.height)
    {
        m_risingItemFile.pop_front();
    }

    // Add items to the bottom of the screen
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

    // Is this done ?
    if (areCreditsDone() && endAfterLastCredits())
    {
        closeLater(loadNextScreen());
    }
}

void EndCreditsScreen::pushItem(float height)
{
    if (m_itemFile.empty())
    return;

    m_risingItemFile.push_back(RisingItem());
    m_risingItemFile.back().height = height;
    m_risingItemFile.back().item = std::move(m_itemFile.front());
    m_itemFile.pop_front();
}

float EndCreditsScreen::lastItemHeight()
{
    return m_risingItemFile.back().height;
}

void EndCreditsScreen::add_item(std::unique_ptr<Menu::AbstractItem> item)
{
    m_itemFile.push_back(move(item));
}


bool EndCreditsScreen::areCreditsDone() const
{
    return (m_itemFile.empty() && m_risingItemFile.empty());
}

bool EndCreditsScreen::endAfterLastCredits() const
{
    return true;
}


std::set<sf::Keyboard::Key> EndCreditsScreen::getKeysToContinue()
{
    return {sf::Keyboard::Return, sf::Keyboard::Escape};
}

