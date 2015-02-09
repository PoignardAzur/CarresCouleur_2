

#ifndef HEADER_AFFICHEUR_OBJETS_ABSTRAIT
#define HEADER_AFFICHEUR_OBJETS_ABSTRAIT

#include <SFML/Graphics.hpp>
#include "AbstractDrawable.h"


class AbstractDrawer
{
    public :

    virtual ~AbstractDrawer() {}
    virtual void clear() = 0;                           // reset the screen
    virtual void draw(const sf::Drawable& o) = 0;

    virtual void draw(const AbstractDrawable& o, sf::Vector2f pos, sf::FloatRect limits, float dt)
    {
        o.drawIn(pos, *this, limits, dt);
    }
};


#endif //HEADER_AFFICHEUR_OBJETS_ABSTRAIT
