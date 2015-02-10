

#ifndef SIMPLE_SPRITE_HEADER
#define SIMPLE_SPRITE_HEADER

#include "AbstractDrawable.h"
#include <memory>

#define NULL_PT sf::Vector2f(0,0)


class SimpleSprite : public AbstractDrawable
{
    public :

    SimpleSprite();
    SimpleSprite(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT);
    virtual void set(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT);

    virtual void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const;

    protected :
    sf::Sprite& getSprite() const;

    private :

    mutable sf::Sprite m_sprite;
    sf::Vector2f m_center;
};


#endif // SIMPLE_SPRITE_HEADER

