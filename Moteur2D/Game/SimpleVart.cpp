

#include "SimpleVart.hpp"
#include <utility>


SimpleVart::SimpleVart()
{

}

SimpleVart::SimpleVart(const SimpleHitbox& hitbox, up_t<DrawableObjectAbstraction> sprite)
{
    set(hitbox);
    setSprite(mv(sprite));
}

SimpleVart::SimpleVart(up_t<DrawableObjectAbstraction> sprite)
{
    setSprite(mv(sprite));
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

up_t<DrawableObjectAbstraction> SimpleVart::setSprite(up_t<DrawableObjectAbstraction> sprite)
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


