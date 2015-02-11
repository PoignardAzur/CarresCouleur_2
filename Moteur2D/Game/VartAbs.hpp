
#ifndef VART_ABSTRACTION_HEADER
#define VART_ABSTRACTION_HEADER

#include "../Graphic/ObjectDrawer.hpp"


// Object that can be drawn and updated
class VartAbs
{
    public :

    virtual bool toDelete() const = 0;
    virtual void update(const sf::Vector2f& pos, float dt) = 0;
    virtual void updatePos(sf::Vector2f& pos, float dt) = 0;
    virtual void drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const = 0;

//    virtual sf::Vector2f getPos() const = 0; /// TO UTTERLY REMOVE FROM THE CODE

    virtual ~VartAbs() {}
};


#endif // VART_ABSTRACTION_HEADER
