
#include "BasicArcadeLevel.hpp"


BasicArcadeLevel::BasicArcadeLevel(unsigned int seed) : AbstractLevel(seed), m_lives(0), m_score(0), m_gameOver(false)
{

}

BasicArcadeLevel::BasicArcadeLevel(std::seed_seq& seed) : AbstractLevel(seed), m_lives(0), m_score(0), m_gameOver(false)
{

}

void BasicArcadeLevel::updateLivesAndTimer(float ticks)
{
    if (!isPlayerAlive())
    {
        if (m_timeBeforeRespawn.getCurrentTime() > 0)
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


BasicArcadeLevel::~BasicArcadeLevel()
{

}


int BasicArcadeLevel::score() const
{
    return m_score;
}

void BasicArcadeLevel::setPoints(int p, bool rel)
{
    if (rel)
    m_score += p;

    else
    m_score = p;
}

int BasicArcadeLevel::lives() const
{
    return m_lives;
}

void BasicArcadeLevel::setLives(int l, bool rel)
{
    if (rel)
    m_lives += l;

    else
    m_lives = l;
}


bool BasicArcadeLevel::gameOver() const
{
    return m_gameOver;
}

void BasicArcadeLevel::setRespawnTime(float ticks)
{
    m_timeBeforeRespawn.setMaxTime(ticks);
}

void BasicArcadeLevel::setGameOver()
{
    m_gameOver = true;
}

