

#include "Level_1.hpp"
#include "Level_2.hpp"
#include <random>


uptrt<LevelBase> Level_1::getNextLevel()
{
    return uptr(new Level_2());
}


void Level_1::leftClick(sf::Vector2f pos)
{
    increaseScore(10);

    CarreCouleur* carre = new CarreCouleur(rng());
    carre->randomizeSpeed(rng());

    addCarre(uptr(carre), pos);
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

    it->setPos(pos);
    it->get().randomizeSpeed(rng());
}

