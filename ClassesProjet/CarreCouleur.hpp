
#ifndef CARRE_COULEUR_HEADER
#define CARRE_COULEUR_HEADER

#include "../Moteur2D/Interfaces/AbstractLevel.hpp"
#include "../Moteur2D/Game/SimpleHitbox.hpp"
#include "../Moteur2D/Game/VartAbs.hpp"


extern int DEFAULT_CARRE_SIZE;
extern int DEFAULT_CARRE_SPEED;


class CarreCouleur : public VartAbs, public SimpleHitbox
{
    public :

    CarreCouleur(sf::Color color, float sizeCarre = DEFAULT_CARRE_SIZE);
    CarreCouleur(std_rng& rng, float sizeCarre = DEFAULT_CARRE_SIZE);

    void randomizeSpeed(std_rng& rng);

    bool toDelete() const;
    void update(const sf::Vector2f& pos, float dt);
    void updatePos(sf::Vector2f& pos, float dt);
    void drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const;

    bool recycle(sf::Vector2f pos, sf::FloatRect limits, bool deleteIfOOB = true, bool ignoreAge = false);

    private :

    float m_age = 0;
    bool m_toDelete = false;

    sf::Color m_color;
    float m_size;
};


#endif // CARRE_COULEUR_HEADER
