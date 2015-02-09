

#include "Level_1.h"
#include "Level_2.h"
#include <random>


LevelBase* Level_1::getNextLevel()
{
    return new Level_2();
}


void Level_1::leftClick(sf::Vector2f pos)
{
    increaseScore(10);

    CarreCouleur* carre = new CarreCouleur(rng());
    carre->setPos(pos);
    carre->randomizeSpeed(rng());

    getCarres().add(carre);
}

void Level_1::rightClick(sf::Vector2f pos)
{
    if (!getCarres().size())    // no carre to teleport
    return;

    ///else

    size_t i = std::uniform_int_distribution<size_t>(0, getCarres().size() - 1)(rng());
    auto it = getCarres().begin();

    while (i)
    {
        it ++;
        i --;
    }

    (*it)->setPos(pos);
    (*it)->randomizeSpeed(rng());
}

