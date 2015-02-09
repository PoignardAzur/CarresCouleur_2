

#include "Sprite.h"


Menu::Sprite::Sprite()
{

}

Menu::Sprite::Sprite(const sf::Sprite& spr)
{
    set(spr);
}

void Menu::Sprite::set(const sf::Sprite& spr)
{
    m_sprite = spr;
    updateParentSize();
}


void Menu::Sprite::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    const_cast<Sprite*>(this)->m_sprite.setPosition(position);
    target.draw(m_sprite);
}

sf::Vector2f Menu::Sprite::getSize() const
{
    return sf::Vector2f(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}

