

#include "SimpleVart.h"
#include <utility>


SimpleVart::SimpleVart()
{

}

SimpleVart::SimpleVart(const SimpleHitbox& hitbox, up_t<AbstractDrawable> sprite)
{
    set(hitbox);
    setSprite(sprite);
}

SimpleVart::SimpleVart(up_t<AbstractDrawable> sprite)
{
    setSprite(sprite);
}

SimpleVart::~SimpleVart()
{

}


void SimpleVart::update(float dt)
{
    (void) dt;
}

bool SimpleVart::doDelete() const
{
    return m_toDelete;
}

up_t<AbstractDrawable> SimpleVart::setSprite(up_t<AbstractDrawable> sprite)
{
    up_t<AbstractDrawable> sprite_(sprite);
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


