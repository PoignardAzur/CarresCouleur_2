
#include "SimpleSprite.hpp"
#include "DrawerAbstraction.hpp"


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
    m_sprite.setPosition(NULL_PT); // that way, the value of m_sprite does not depend on previous calls to the const method drawIn
    return m_sprite;
}

void SimpleSprite::drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const
{
    (void) limits;
    (void) dt;

    m_sprite.setPosition(pos - m_center);
    target.draw(m_sprite);
}

