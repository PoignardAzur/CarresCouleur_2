
#include "ObjectDrawer.hpp"


ObjectDrawer::ObjectDrawer(sf::RenderTarget* t) : m_target(t)
{

}

void ObjectDrawer::clear()
{
    m_target->clear();
}


void ObjectDrawer::draw(const sf::Drawable& object)
{
    m_target->draw(object);
}

sf::RenderTarget& ObjectDrawer::getTarget()
{
    return *m_target;
}

