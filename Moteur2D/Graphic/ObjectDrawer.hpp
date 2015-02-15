
#ifndef OBJECT_DRAWER_HEADER
#define OBJECT_DRAWER_HEADER

#include "DrawerAbstraction.hpp"


class ObjectDrawer : public DrawerAbstraction
{
    public :

    explicit ObjectDrawer(sf::RenderTarget* t);

    virtual void clear();                               // reset the screen
    virtual void draw(const sf::Drawable& object);

    protected :
    sf::RenderTarget& getTarget();

    private :
    sf::RenderTarget* m_target;       // use-a
};


#endif
