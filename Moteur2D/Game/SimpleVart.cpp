
#include "SimpleVart.hpp"
#include "../Graphic/SimpleSprite.hpp"
#include <utility>

bool DRAW_VART_SPRITE = true;
bool DRAW_VART_HITBOX = false;


SimpleVart::SimpleVart()
{

}

SimpleVart::SimpleVart(sf::Sprite sprite, sf::Vector2f center)
{
    setSprite(sprite, center);
}

SimpleVart::SimpleVart(uptrt<DrawableObject> sprite)
{
    setSprite(move(sprite));
}

SimpleVart::SimpleVart(const SimpleHitbox& hitbox, sf::Sprite sprite, sf::Vector2f center)
{
    set(hitbox);
    setSprite(sprite, center);
}

SimpleVart::SimpleVart(const SimpleHitbox& hitbox, uptrt<DrawableObject> sprite)
{
    set(hitbox);
    setSprite(move(sprite));
}

SimpleVart::~SimpleVart()
{

}


void SimpleVart::update(const sf::Vector2f& pos, float dt)
{
    (void) dt;
    (void) pos;
}

void SimpleVart::updatePos(sf::Vector2f& pos, float dt)
{
    pos += getSpeed() * dt;
}

bool SimpleVart::doDelete() const
{
    return m_toDelete;
}

uptrt<DrawableObject> SimpleVart::setSprite(sf::Sprite sprite, sf::Vector2f center)
{
    return setSprite( uptr(new SimpleSprite(sprite, center)) );
}

uptrt<DrawableObject> SimpleVart::setSprite(uptrt<DrawableObject> sprite)
{
    std::swap(sprite, m_sprite);
    return sprite;                      // returns what was m_sprite before calling this function
}

void SimpleVart::removeThis()
{
    m_toDelete = true;
}


void SimpleVart::drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const
{
    m_sprite->drawIn(pos + getSpeed()*dt, target, limits, dt);
}

void SimpleVart::recycle(sf::Vector2f pos, sf::FloatRect zone, bool deleteIfOut)
{
    if (getHitbox(pos).intersects(zone) != deleteIfOut)
    removeThis();
}

