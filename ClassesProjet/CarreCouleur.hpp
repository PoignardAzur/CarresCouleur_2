

#ifndef HEADER_CARRE_COULEUR
#define HEADER_CARRE_COULEUR

#define DEFAULT_CARRE_SIZE 30
#define DEFAULT_CARRE_SPEED 160

#include "../Moteur2D/Interfaces/AbstractLevel.h"
#include "../Moteur2D/Game/SimpleHitbox.h"
#include "../Moteur2D/Game/AbsVart.h"


class CarreCouleur : public AbsVart, public SimpleHitbox
{
    public :

    CarreCouleur(sf::Color color, float sizeCarre = DEFAULT_CARRE_SIZE);
    CarreCouleur(std_rng& rng, float sizeCarre = DEFAULT_CARRE_SIZE);

    void randomizeSpeed(std_rng& rng);

    bool toDelete() const;
    void update(float dt);
    void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const;

    sf::Vector2f getPos() const;
    bool recycle(sf::FloatRect limits, bool deleteIfOOB = true);
//    void setSpeed(sf::Vector2f speed, bool relative = false);
//    sf::Vector2f getSpeed() const;

    private :

    float m_age = 0;
    bool m_toDelete = false;

    sf::Color m_color;
    float m_size;
};


#endif // HEADER_CARRE_COULEUR