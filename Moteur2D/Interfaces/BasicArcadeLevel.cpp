
#include "BasicArcadeLevel.hpp"


BasicArcadeLevel::BasicArcadeLevel(unsigned int seed) : AbstractLevel(seed), m_lives(0), m_score(0), m_gameOver(false)
{

}

BasicArcadeLevel::BasicArcadeLevel(std::seed_seq& seed) : AbstractLevel(seed), m_lives(0), m_score(0), m_gameOver(false)
{

}

void BasicArcadeLevel::updateLivesAndTimer(float dt)
{
    if (!isPlayerAlive())
    {
        if (m_timeBeforeRespawn.getCurrentTime() > 0)
        {
            if (m_timeBeforeRespawn.decrement(dt))
            {
                m_lives--;
                respawnPlayer();
            }
        }

        else if (m_lives)
        {
            m_timeBeforeRespawn.resetTimeToMax();
            playerKilledEvent(false);
        }

        else if (!isGameOver())
        {
            setGameOver();
            playerKilledEvent(true);
        }
    }
}


BasicArcadeLevel::~BasicArcadeLevel()
{

}


int BasicArcadeLevel::getScore() const
{
    return m_score;
}

void BasicArcadeLevel::setScore(int p, bool rel)
{
    if (rel)
    m_score += p;

    else
    m_score = p;
}

int BasicArcadeLevel::getLives() const
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


bool BasicArcadeLevel::isGameOver() const
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

