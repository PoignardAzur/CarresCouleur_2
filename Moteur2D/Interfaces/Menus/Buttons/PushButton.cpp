
#include "PushButton.hpp"


void Menu::PushButton::setFunction(std::function<void(void)> triggeredFunction)
{
    m_triggeredFunction = triggeredFunction;
}


void Menu::PushButton::select()
{
    m_selected = true;
}

void Menu::PushButton::deselect()
{
    m_selected = false;
    m_pressed = false;
}

void Menu::PushButton::press()
{
    m_pressed = true;
    trigger();
}

void Menu::PushButton::trigger()
{
    if (m_triggeredFunction)
    m_triggeredFunction();
}


sf::Vector2f Menu::PushButton::getSize() const
{
    return currentSprite(m_selected).getSize();
}


void Menu::PushButton::drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    currentSprite(m_selected).drawIn(target, position, isHitboxDrawn);
}



