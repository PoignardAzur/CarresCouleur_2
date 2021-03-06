
#include "SimpleHitbox.hpp"

const sf::Vector2f NULL_PT(0,0);
const sf::FloatRect NULL_RECT(0,0,0,0);


SimpleHitbox::SimpleHitbox(sf::FloatRect box, sf::Vector2f speed) : m_box(box), m_speed(speed)
{

}

SimpleHitbox::SimpleHitbox(const SimpleHitbox& other)
{
    set(other);
}

void SimpleHitbox::setHitbox(sf::FloatRect nInternBox)
{
    m_box = nInternBox;
}

void SimpleHitbox::set(const SimpleHitbox& other)
{
    setHitbox(other.m_box);
    setSpeed(other.m_speed);
}


sf::FloatRect SimpleHitbox::getHitbox(sf::Vector2f center) const     // get the placed hitbox of the object
{
    return sf::FloatRect(m_box.left + center.x, m_box.top + center.y, m_box.width, m_box.height);
}


void SimpleHitbox::setSpeed(sf::Vector2f speed, bool relative)
{
    if (relative)
    setSpeed(getSpeed() + speed, false);

    else
    m_speed = speed;
}

sf::Vector2f SimpleHitbox::getSpeed() const
{
    return m_speed;
}


sf::Vector2f getCenter(const sf::FloatRect& rect)
{
    return sf::Vector2f(rect.left + (rect.width / 2), rect.top + (rect.height / 2));
}

bool testCollision(const SimpleHitbox& o1, sf::Vector2f pos1, const SimpleHitbox& o2, sf::Vector2f pos2)
{
    return o1.getHitbox(pos1).intersects(o2.getHitbox(pos2));
}

