

#ifndef BASIC_ARCADE_LEVEL_HEADER
#define BASIC_ARCADE_LEVEL_HEADER


#include "AbstractLevel.h"
#include "../Timer.h"


template<typename In>
class BasicArcadeLevel : public AbstractLevel<In>
{
    public :

    BasicArcadeLevel(unsigned int seed = epoch_to_now().count());
    BasicArcadeLevel(std::seed_seq& seed);
    virtual ~BasicArcadeLevel();

    bool gameOver() const;
    virtual bool isPlayerAlive() const = 0;
    virtual void respawnPlayer() = 0;
    virtual void playerKilled(bool isGameOver) = 0;

    virtual void drawThisIn(AbstractDrawer& window, float dt) = 0;
    virtual void updateThis(const In& inputData) = 0;


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



template<typename In>
void BasicArcadeLevel<In>::updateLivesAndTimer(float ticks)
{
    if (!isPlayerAlive())
    {
        if (m_timeBeforeRespawn.getCurrentTime())
        {
            if (m_timeBeforeRespawn.decrement(ticks))
            {
                m_lives--;
                respawnPlayer();
            }
        }

        else if (m_lives)
        {
            m_timeBeforeRespawn.resetTimeToMax();
            playerKilled(false);
        }

        else if (!gameOver())
        {
            setGameOver();
            playerKilled(true);
        }

    }
}






template<typename In>
BasicArcadeLevel<In>::BasicArcadeLevel(unsigned int seed) : AbstractLevel<In>(seed), m_lives(0), m_score(0), m_gameOver(false)
{

}

template<typename In>
BasicArcadeLevel<In>::BasicArcadeLevel(std::seed_seq& seed) : AbstractLevel<In>(seed), m_lives(0), m_score(0), m_gameOver(false)
{

}


template<typename In>
BasicArcadeLevel<In>::~BasicArcadeLevel()
{

}




template<typename In>
int BasicArcadeLevel<In>::score() const
{
    return m_score;
}

template<typename In>
void BasicArcadeLevel<In>::setPoints(int p, bool rel)
{
    if (rel)
    m_score += p;

    else
    m_score = p;
}


template<typename In>
int BasicArcadeLevel<In>::lives() const
{
    return m_lives;
}


template<typename In>
void BasicArcadeLevel<In>::setLives(int l, bool rel)
{
    if (rel)
    m_lives += l;

    else
    m_lives = l;
}


template<typename In>
bool BasicArcadeLevel<In>::gameOver() const
{
    return m_gameOver;
}


template<typename In>
void BasicArcadeLevel<In>::setRespawnTime(float ticks)
{
    m_timeBeforeRespawn.setMaxTime(ticks);
}

template<typename In>
void BasicArcadeLevel<In>::setGameOver()
{
    m_gameOver = true;
}



#endif // BASIC_ARCADE_LEVEL_HEADER


