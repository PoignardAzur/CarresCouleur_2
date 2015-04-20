
#include "Level_2.hpp"
#include "Level_3.hpp"
#include <cmath>

uptrt<LevelBase> Level_2::getNextLevel()
{
    return uptr(new Level_3());
}

void pushAround(Placed<CarreCouleur>& carre, sf::Vector2f pos, float force)
{
    pos -= carre.getPos();
    float squared_distance = sqrt(pos.x * pos.x + pos.y * pos.y);
    carre.get().setSpeed(500000.0f * pos * force / (squared_distance * squared_distance * squared_distance), true);
}

void Level_2::updateThis(float dt)
{
    LevelBase::updateThis(dt);
    generateCarreStream(dt);

    if (getInputs()->getMouseButtons()[sf::Mouse::Left])
    {
        for (auto& placedCarre : getCarres())
        {
            pushAround(placedCarre, getInputs()->cursor(), -3*dt);
        }
    }

    if (getInputs()->getMouseButtons()[sf::Mouse::Right])
    {
        for (auto& placedCarre : getCarres())
        {
            pushAround(placedCarre, getInputs()->cursor(), 2*dt);
        }
    }
}

void Level_2::leftClick(sf::Vector2f pos)
{
    (void) pos;
}

void Level_2::rightClick(sf::Vector2f pos)
{
    (void) pos;
}

