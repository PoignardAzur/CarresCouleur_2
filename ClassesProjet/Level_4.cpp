
#include "Level_4.hpp"

#define TIME_BETWEEN_CARRES 0.1


void Level_4::updateThis(float dt)
{
    LevelBase::updateThis(dt);

    if (m_timeBeforeNextCarre > 0)
    m_timeBeforeNextCarre -= dt;

    if (getInputs()->getMouseButtons()[sf::Mouse::Left] && m_timeBeforeNextCarre <= 0)
    {
        float carreSize = float_dice(DEFAULT_CARRE_SIZE / 2, DEFAULT_CARRE_SIZE * 2)(rng());
        CarreCouleur* carre = new CarreCouleur(rng(), carreSize);
        carre->randomizeSpeed(rng());

        addCarre(up(carre), getInputs()->cursor());
        m_timeBeforeNextCarre = TIME_BETWEEN_CARRES;
    }
}

up_t<LevelBase> Level_4::getNextLevel()
{
    return up_t<LevelBase>();
}

void Level_4::leftClick(sf::Vector2f pos)
{
    (void) pos;
}

void Level_4::rightClick(sf::Vector2f pos)
{
    (void) pos;
}

