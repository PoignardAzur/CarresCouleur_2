
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
    explicit SimpleVart(uptrt<DrawableObject> sprite);
    explicit SimpleVart(const SimpleHitbox& hitbox, sf::Sprite sprite, sf::Vector2f center = NULL_PT);
    explicit SimpleVart(const SimpleHitbox& hitbox, uptrt<DrawableObject> sprite = nullptr);
    virtual ~SimpleVart();

    uptrt<DrawableObject> setSprite(sf::Sprite sprite, sf::Vector2f center = NULL_PT);
    uptrt<DrawableObject> setSprite(uptrt<DrawableObject> sprite);

    virtual void update(const sf::Vector2f& pos, float dt);
    virtual void updatePos(sf::Vector2f& pos, float dt);
    virtual bool doDelete() const;
    virtual void drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const;


    protected :

    virtual void removeThis();


    private :

    bool m_toDelete = false;
    uptrt<DrawableObject> m_sprite;
};


#endif // SIMPLE_VART_HEADER
