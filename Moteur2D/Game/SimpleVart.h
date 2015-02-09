

#ifndef HEADER_VARTS
#define HEADER_VARTS

#include "AbsVart.h"
#include "SimpleHitbox.h"
#include <memory>

#define DRAW_VART_SPRITE true
#define DRAW_VART_HITBOX true


//Represents a basic object with a provided hitbox and sprite.
class SimpleVart : public AbsVart, public SimpleHitbox
{
    public :

    SimpleVart();
    explicit SimpleVart(AbstractDrawable* sprite);
    explicit SimpleVart(const SimpleHitbox& hitbox, AbstractDrawable* sprite = nullptr);
    virtual ~SimpleVart();

    virtual void update(float dt);
    virtual bool doDelete() const;
    virtual void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const;


    protected :

    std::unique_ptr<AbstractDrawable> setSprite(AbstractDrawable* sprite);
    virtual void removeThis();


    private :

    bool m_toDelete = false;
    std::unique_ptr<AbstractDrawable> m_sprite;
};


#endif

