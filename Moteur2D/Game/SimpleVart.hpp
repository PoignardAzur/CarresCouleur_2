

#ifndef HEADER_VARTS
#define HEADER_VARTS

#include "AbsVart.hpp"
#include "SimpleHitbox.hpp"
#include <up.hpp>

#define DRAW_VART_SPRITE true
#define DRAW_VART_HITBOX true


//Represents a basic object with a provided hitbox and sprite.
class SimpleVart : public AbsVart, public SimpleHitbox
{
    public :

    SimpleVart();
    explicit SimpleVart(up_t<AbstractDrawable> sprite);
    explicit SimpleVart(const SimpleHitbox& hitbox, up_t<AbstractDrawable> sprite = nullptr);
    virtual ~SimpleVart();

    virtual void update(const sf::Vector2f& pos, float dt);
    virtual void updatePos(sf::Vector2f& pos, float dt);
    virtual bool doDelete() const;
    virtual void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const;


    protected :

    up_t<AbstractDrawable> setSprite(up_t<AbstractDrawable> sprite);
    virtual void removeThis();


    private :

    bool m_toDelete = false;
    up_t<AbstractDrawable> m_sprite;
};


#endif

