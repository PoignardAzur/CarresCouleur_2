

#include "ObjectDrawer.h"



void ObjectDrawer::clear()
{
    m_target->clear();
}


void ObjectDrawer::draw(const sf::Drawable& objet)
{
    m_target->draw(objet);
}

ObjectDrawer::ObjectDrawer(sf::RenderTarget* t) : m_target(t)
{

}

sf::RenderTarget& ObjectDrawer::target()
{
    return *m_target;
}

