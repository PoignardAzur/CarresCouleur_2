

#ifndef HEADER_LEVEL_2
#define HEADER_LEVEL_2

#include "LevelBase.h"


class Level_2 : public LevelBase
{
    public :

    LevelBase* getNextLevel();
    virtual void update(const float& dt);

    void leftClick(sf::Vector2f pos);
    void rightClick(sf::Vector2f pos);


    private :

    float m_timeBeforeRespawn = 0;
    float m_timeBeforeScoring = 0;
};

#endif // HEADER_LEVEL_1
