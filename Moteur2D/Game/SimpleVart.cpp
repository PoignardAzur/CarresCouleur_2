

#include "SimpleVart.h"
#include <utility>


SimpleVart::SimpleVart()
{

}

SimpleVart::SimpleVart(const SimpleHitbox& hitbox, AbstractDrawable* sprite)
{
    set(hitbox);
    setSprite(sprite);
}

SimpleVart::SimpleVart(AbstractDrawable* sprite)
{
    setSprite(sprite);
}

SimpleVart::~SimpleVart()
{

}


void SimpleVart::update(float dt)
{

}

bool SimpleVart::doDelete() const
{
    return m_toDelete;
}

std::unique_ptr<AbstractDrawable> SimpleVart::setSprite(AbstractDrawable* sprite)
{
    std::unique_ptr<AbstractDrawable> sprite_(sprite);
    std::swap(sprite_, m_sprite);
    return sprite_;
}

void SimpleVart::removeThis()
{
    m_toDelete = true;
}


void SimpleVart::drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const
{
    m_sprite->drawIn(pos + getSpeed()*dt, target, limits, dt);
}


