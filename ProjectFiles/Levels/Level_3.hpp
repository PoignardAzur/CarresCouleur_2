
#ifndef HEADER_LEVEL_3
#define HEADER_LEVEL_3

#include "../LevelBase.hpp"


class Level_3 : public LevelBase
{
    public :

    Level_3();

    uptrt<LevelBase> getNextLevel();
    virtual void updateThis(float dt);
    void drawThisIn(DrawerAbstraction& window, float dt) const;

    void generateCarre();

    void leftClick(sf::Vector2f pos);
    void rightClick(sf::Vector2f pos);


    private :

    CarreCouleur m_carreGris;
    sf::Vector2f m_carreGrisPos;
};


#endif // HEADER_LEVEL_3
