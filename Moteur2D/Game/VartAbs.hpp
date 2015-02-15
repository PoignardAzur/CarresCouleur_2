
#ifndef VART_ABSTRACTION_HEADER
#define VART_ABSTRACTION_HEADER

#include "../Graphic/ObjectDrawer.hpp"


/* Object that can be drawn and updated
NOTE : All the following functions use external parameters to get the position of the
Vart because it is NOT supposed to store its position, and neither are its child classes
*/
class VartAbs
{
    public :

    virtual bool toDelete() const = 0;
    virtual void update(const sf::Vector2f& pos, float dt) = 0;     // updates itself depending on its position
    virtual void updatePos(sf::Vector2f& pos, float dt) = 0;        // updates its own position
    virtual void drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const = 0;

    virtual ~VartAbs() {}
};


#endif // VART_ABSTRACTION_HEADER
