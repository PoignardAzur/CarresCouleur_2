
#ifndef SIMPLE_HITBOX_HEADER
#define SIMPLE_HITBOX_HEADER

#include <SFML/Graphics/Rect.hpp>

extern const sf::Vector2f NULL_PT;
extern const sf::FloatRect NULL_RECT;


// A rectangular box with a speed and no position
class SimpleHitbox
{
    public :

    explicit SimpleHitbox(sf::FloatRect box = NULL_RECT, sf::Vector2f speed = NULL_PT);
    SimpleHitbox(const SimpleHitbox& other);
    virtual ~SimpleHitbox() {}

    void setHitbox(sf::FloatRect internBox);
    void set(const SimpleHitbox&);

    sf::FloatRect getHitbox(sf::Vector2f center = NULL_PT) const;     // get the placed hitbox of the object

    void setSpeed(sf::Vector2f speed, bool relative = false);
    sf::Vector2f getSpeed() const;


    private :

    sf::FloatRect m_box;
    sf::Vector2f m_speed;
};


sf::Vector2f getCenter(const sf::FloatRect& box);
bool testCollision(const SimpleHitbox& o1, sf::Vector2f pos1, const SimpleHitbox& o2, sf::Vector2f pos2);


#endif // SIMPLE_HITBOX_HEADER
