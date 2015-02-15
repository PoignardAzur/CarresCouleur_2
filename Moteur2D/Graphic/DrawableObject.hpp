
#ifndef DRAWABLE_OBJECT_HEADER
#define DRAWABLE_OBJECT_HEADER

#include <SFML/Graphics.hpp>


class DrawerAbstraction;

// Interface for drawable objects
class DrawableObject
{
    public :

    virtual ~DrawableObject() = default;
    virtual void drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const = 0;
    // When this function is called, the object is drawn at the position pos, in the rectangle limits,
    // in the state it's predicted to be after the time dt has passed
};


#endif // DRAWABLE_OBJECT_HEADER
