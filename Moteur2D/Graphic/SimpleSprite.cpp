

#include "SimpleSprite.h"
#include "AbstractDrawer.h"


SimpleSprite::SimpleSprite()
{

}

SimpleSprite::SimpleSprite(const sf::Sprite& sprite, sf::Vector2f center)
{
    set(sprite, center);
}

void SimpleSprite::set(const sf::Sprite& sprite, sf::Vector2f center)
{
    m_sprite.setTexture(* sprite.getTexture());
    m_sprite.setTextureRect(sprite.getTextureRect());
    m_center = center;
}


sf::Sprite& SimpleSprite::getSprite() const
{
    return m_sprite;
}

void SimpleSprite::drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const
{
    (void) limits;
    (void) dt;

    m_sprite.setPosition(pos - m_center);
    target.draw(m_sprite);
}

