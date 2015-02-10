

#include "ObjectDrawer.h"



ObjectDrawer::ObjectDrawer(sf::RenderTarget* t) : m_target(t)
{

}

void ObjectDrawer::clear()
{
    m_target->clear();
}


void ObjectDrawer::draw(const sf::Drawable& objet)
{
    m_target->draw(objet);
}

sf::RenderTarget& ObjectDrawer::target() /// TODO - Change this to getTarget()
{
    return *m_target;
}

