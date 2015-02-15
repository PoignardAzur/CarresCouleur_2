
#ifndef SIMPLE_SPRITE_HEADER
#define SIMPLE_SPRITE_HEADER

#include "DrawableObject.hpp"
#include <memory>

extern const sf::Vector2f NULL_PT; // defined in Game/SimpleHitbox


class SimpleSprite : public DrawableObject
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

    mutable sf::Sprite m_sprite;        // is mutable because m_sprite.setPosition(pos) is called in the drawIn method
    sf::Vector2f m_center;
};


#endif // SIMPLE_SPRITE_HEADER

