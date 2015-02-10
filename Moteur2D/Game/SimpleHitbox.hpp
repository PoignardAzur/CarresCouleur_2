

#ifndef SIMPLE_HITBOX_HEADER
#define SIMPLE_HITBOX_HEADER

#include <SFML/Graphics/Rect.hpp>

#define NULL_PT sf::Vector2f(0,0)
#define NULL_RECT sf::FloatRect(0,0,0,0)


class SimpleHitbox
{
    public :

    explicit SimpleHitbox(sf::FloatRect box = NULL_RECT, sf::Vector2f pos = NULL_PT, sf::Vector2f speed = NULL_PT);
    SimpleHitbox(const SimpleHitbox& other);
    virtual ~SimpleHitbox() {}

    void setHitbox(sf::FloatRect internBox);
    void set(const SimpleHitbox&);

    sf::FloatRect getHitbox(sf::Vector2f center = NULL_PT) const;     // get the placed hitbox of the object

    void setPos(sf::Vector2f pos);
    sf::Vector2f getPos() const;

    void setSpeed(sf::Vector2f speed, bool relative = false);
    sf::Vector2f getSpeed() const;


    private :

    sf::FloatRect m_box;

    sf::Vector2f m_pos;  /// TO UTTERLY REMOVE FROM THE CODE
    sf::Vector2f m_speed;
};


sf::Vector2f getCenter(const sf::FloatRect& box);
bool testCollision(const SimpleHitbox& o1, sf::Vector2f pos1, const SimpleHitbox& o2, sf::Vector2f pos2);


#endif // SIMPLE_HITBOX_HEADER

