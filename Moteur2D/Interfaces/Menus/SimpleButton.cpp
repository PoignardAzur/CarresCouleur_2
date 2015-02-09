

#include "SimpleButton.h"
#include "../Items/ItemBox.h"
#include "../Items/Text.h"


Menu::SimpleButton::SimpleButton(AbstractItem* unselected, AbstractItem* selected)
{
    setSprites(unselected, selected);
}

void Menu::SimpleButton::setSprites(AbstractItem* unselected, AbstractItem* selected)
{
    m_unselected_sprite.reset(unselected);
    m_selected_sprite.reset(selected);
}


void Menu::SimpleButton::setFunction(std::function<void(void)> triggeredFunction)
{
    m_triggeredFunction = triggeredFunction;
}


void Menu::SimpleButton::select()
{
    m_selected = true;
}

void Menu::SimpleButton::deselect()
{
    m_selected = false;
    m_pressed = false;
}

void Menu::SimpleButton::press()
{
    m_pressed = true;
    trigger();
}

void Menu::SimpleButton::trigger()
{
    if (m_triggeredFunction)
    m_triggeredFunction();
}


sf::Vector2f Menu::SimpleButton::getSize() const
{
    if (currentSprite())
    return currentSprite()->getSize();

/// else
    return sf::Vector2f(0,0);
}


void Menu::SimpleButton::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    if (currentSprite())
    currentSprite()->drawIn(target, position, isHitboxDrawn);
}

const Menu::AbstractItem* Menu::SimpleButton::currentSprite() const
{
    return const_cast<SimpleButton*>(this)->currentSprite();
}

Menu::AbstractItem* Menu::SimpleButton::currentSprite()
{
    if (m_selected && m_selected_sprite)
    return m_selected_sprite.get();

    ///else
    return m_unselected_sprite.get();
}

