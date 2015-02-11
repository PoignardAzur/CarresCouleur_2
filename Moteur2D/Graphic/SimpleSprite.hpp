

#ifndef SIMPLE_SPRITE_HEADER
#define SIMPLE_SPRITE_HEADER

#include "DrawableAbstraction.hpp"
#include <memory>

#define NULL_PT sf::Vector2f(0,0)


class SimpleSprite : public DrawableObjectAbstraction
{
    public :

    SimpleSprite();
    SimpleSprite(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT);
    virtual void set(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT);
    ~SimpleSprite() noexcept {}

    virtual void drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const;

    protected :
    sf::Sprite& getSprite() const;

    private :

    mutable sf::Sprite m_sprite;
    sf::Vector2f m_center;
};


#endif // SIMPLE_SPRITE_HEADER

