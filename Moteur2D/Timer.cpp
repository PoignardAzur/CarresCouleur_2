

#include "Timer.h"


Timer::Timer(float startTime, float maxTime) : m_time(startTime)
{
    if (maxTime > 0)
    m_maxTime = maxTime;

    else
    m_maxTime = startTime;
}


void Timer::setMaxTime(float t)
{
    m_maxTime = t;
}

void Timer::setTime(float t, bool respectLimit)
{
    if (!respectLimit || t <= m_maxTime)
    m_time = t;

    else
    m_time = m_maxTime;
}

void Timer::resetTimeToMax()
{
    m_time = m_maxTime;
}

bool Timer::decrement(float ticks)
{
    if (m_time > 0)
    m_time -= ticks;

    if (m_time <= 0)
    {
        m_time = 0;
        return true;
    }

/// else
    return false;
}

float Timer::getMaxTime() const
{
    return m_maxTime;
}

float Timer::getCurrentTime() const
{
    return m_time;
}



std::vector<bool> decrement(std::vector<Timer> tableau, float dt)
{
    std::vector<bool> tableauRetour (tableau.size(), true);
    auto p1 = tableau.begin();
    auto p2 = tableauRetour.begin();

    while (p1 != tableau.end())
    {
        *p2 = p1->decrement(dt);

        p1++;
        p2++;
    }

    return tableauRetour;
}




