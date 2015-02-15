
#ifndef SIMPLE_VART_HEADER
#define SIMPLE_VART_HEADER

#include "VartAbs.hpp"
#include "SimpleHitbox.hpp"
#include <up.hpp>

extern bool DRAW_VART_SPRITE;   // these variables are not constants to improve compile time
extern bool DRAW_VART_HITBOX;   // they should not be modified by the program


//Represents a basic object with a provided hitbox and sprite.
class SimpleVart : public VartAbs, public SimpleHitbox
{
    public :

    SimpleVart();
    explicit SimpleVart(sf::Sprite sprite, sf::Vector2f center = NULL_PT);
    explicit SimpleVart(up_t<DrawableObjectAbstraction> sprite);
    explicit SimpleVart(const SimpleHitbox& hitbox, sf::Sprite sprite, sf::Vector2f center = NULL_PT);
    explicit SimpleVart(const SimpleHitbox& hitbox, up_t<DrawableObjectAbstraction> sprite = nullptr);
    virtual ~SimpleVart();

    up_t<DrawableObjectAbstraction> setSprite(sf::Sprite sprite, sf::Vector2f center = NULL_PT);
    up_t<DrawableObjectAbstraction> setSprite(up_t<DrawableObjectAbstraction> sprite);

    virtual void update(const sf::Vector2f& pos, float dt);
    virtual void updatePos(sf::Vector2f& pos, float dt);
    virtual bool doDelete() const;
    virtual void drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const;


    protected :

    virtual void removeThis();


    private :

    bool m_toDelete = false;
    up_t<DrawableObjectAbstraction> m_sprite;
};


#endif // SIMPLE_VART_HEADER
