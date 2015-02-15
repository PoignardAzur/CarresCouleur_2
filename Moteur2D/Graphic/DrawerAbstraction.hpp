
#ifndef DRAWER_ABSTRACTION_HEADER
#define DRAWER_ABSTRACTION_HEADER

#include <SFML/Graphics.hpp>
#include "DrawableAbstraction.hpp"


class DrawerAbstraction
{
    public :

    virtual ~DrawerAbstraction() = default;
    virtual void clear() = 0;                                // reset the screen
    virtual void draw(const sf::Drawable& object) = 0;

    virtual void draw(const DrawableObjectAbstraction& object, sf::Vector2f pos, sf::FloatRect limits, float dt)
    {
        object.drawIn(pos, *this, limits, dt); // see DrawableObjectAbstraction::drawIn(...)
    }
};


#endif //DRAWER_ABSTRACTION_HEADER
