

#ifndef HEADER_TIMER
#define HEADER_TIMER

#include <vector>


// A class for an in-game timer
class Timer
{
    public :

    Timer(float startTime = 0, float maxTime = 0);

    void setMaxTime(float t);
    void setTime(float t, bool respectLimit = false);
    void resetTimeToMax();

    bool decrement(float dt); // returns true if the timer reached zero

    float getMaxTime() const;
    float getCurrentTime() const;


    private :

    float m_time;
    float m_maxTime;
};

std::vector<bool> decrement(std::vector<Timer> tableau, float dt);


#endif
