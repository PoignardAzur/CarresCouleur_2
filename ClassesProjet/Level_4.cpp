

#include "Level_4.h"

#define TIME_BETWEEN_CARRES 0.1


void Level_4::update(const float& dt)
{
    LevelBase::update(dt);

    if (m_timeBeforeNextCarre > 0)
    m_timeBeforeNextCarre -= dt;

    if (getInputs()->mouseButtons()[sf::Mouse::Left] && m_timeBeforeNextCarre <= 0)
    {
        float carreSize = float_dice(DEFAULT_CARRE_SIZE / 2, DEFAULT_CARRE_SIZE * 2)(rng());
        CarreCouleur* carre = new CarreCouleur(rng(), carreSize);
        carre->setPos(getInputs()->cursor());
        carre->randomizeSpeed(rng());

        getCarres().add(carre);
        m_timeBeforeNextCarre = TIME_BETWEEN_CARRES;
    }
}

LevelBase* Level_4::getNextLevel()
{
    return nullptr;
}

void Level_4::leftClick(sf::Vector2f pos)
{

}

void Level_4::rightClick(sf::Vector2f pos)
{

}

