

#ifndef HEADER_VART_ABSTRAIT
#define HEADER_VART_ABSTRAIT

#include "../Graphic/ObjectDrawer.h"


// Object that can be drawn and updated
class AbsVart
{
    public :

    virtual bool toDelete() const = 0;
    virtual void update(float dt) = 0;
    virtual void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const = 0;

    virtual sf::Vector2f getPos() const = 0; /// TO UTTERLY REMOVE FROM THE CODE

    virtual ~AbsVart() {}
};


#endif
