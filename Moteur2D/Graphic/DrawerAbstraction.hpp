

#ifndef DRAWER_ABSTRACTION_HEADER
#define DRAWER_ABSTRACTION_HEADER

#include <SFML/Graphics.hpp>
#include "DrawableAbstraction.hpp"


class DrawerAbstraction
{
    public :

    virtual ~DrawerAbstraction() = default;
    virtual void clear() = 0;                           // reset the screen
    virtual void draw(const sf::Drawable& o) = 0;

    virtual void draw(const DrawableObjectAbstraction& o, sf::Vector2f pos, sf::FloatRect limits, float dt)
    {
        o.drawIn(pos, *this, limits, dt);
    }
};


#endif //DRAWER_ABSTRACTION_HEADER
