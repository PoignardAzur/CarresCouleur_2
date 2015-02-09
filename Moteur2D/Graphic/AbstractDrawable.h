

#ifndef HEADER_OBJET_AFFICHABLE_ABSTRAIT
#define HEADER_OBJET_AFFICHABLE_ABSTRAIT

#include <SFML/Graphics.hpp>


class AbstractDrawer;

// Interface for drawable objects
class AbstractDrawable
{
    public :

    virtual ~AbstractDrawable() {}
    virtual void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const = 0;
};


#endif // HEADER_OBJET_AFFICHABLE_ABSTRAIT
