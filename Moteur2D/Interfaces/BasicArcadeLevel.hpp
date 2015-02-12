
#ifndef BASIC_ARCADE_LEVEL_HEADER
#define BASIC_ARCADE_LEVEL_HEADER

#include "AbstractLevel.hpp"
#include "../Timer.hpp"


class BasicArcadeLevel : public AbstractLevel
{
    public :

    BasicArcadeLevel(unsigned int seed = epoch_to_now().count());
    BasicArcadeLevel(std::seed_seq& seed);
    virtual ~BasicArcadeLevel();

    bool gameOver() const;
    virtual bool isPlayerAlive() const = 0;
    virtual void respawnPlayer() = 0;
    virtual void playerKilled(bool isGameOver) = 0;

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void updateThis(float dt) = 0;


    protected :

    int score() const;
    void setPoints(int p, bool rel = false);

    int lives() const;
    void setLives(int l, bool rel = false);

    void setRespawnTime(float ticks);
    void updateLivesAndTimer(float ticks);
    void setGameOver();


    private :

    Timer m_timeBeforeRespawn;
    int m_lives;
    int m_score;
    bool m_gameOver;
};


#endif // BASIC_ARCADE_LEVEL_HEADER
