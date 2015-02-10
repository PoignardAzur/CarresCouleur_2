

#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include "Menus/AbstractMenuInterface.h"
#include <random>
#include <chrono>
#include <memory>


inline auto epoch_to_now() -> decltype(std::chrono::system_clock::now().time_since_epoch())
{
    return std::chrono::system_clock::now().time_since_epoch();
}

typedef std::uniform_real_distribution<float> float_dice;
typedef std::uniform_real_distribution<double> double_dice;
typedef std::uniform_int_distribution<int> int_dice;
typedef std::default_random_engine std_rng;


template <typename In>
class AbstractLevel : public AbstractGameInterface<In>
{
    public :

    AbstractLevel(unsigned int seed = epoch_to_now().count());
    AbstractLevel(std::seed_seq& seed);
    void setSeed(unsigned int seed = epoch_to_now().count());
    void setSeed(std::seed_seq& seed);
    virtual ~AbstractLevel();

    virtual std_rng& rng();

    virtual void drawIn(AbstractDrawer& window, float dt);
    virtual void update(const In& inputData);

    virtual void drawThisIn(AbstractDrawer& window, float dt) = 0;
    virtual void updateThis(const In& inputData) = 0;

    virtual void pauseLevel(std::unique_ptr<AbstractMenuInterface> pauseMenu);
    virtual void setNextInterface(std::unique_ptr<AbstractGameInterface<In>> nextInt);
    virtual AbstractGameInterface<In>* next();


    private :

    std_rng m_randomGenerator;
    std::unique_ptr<AbstractMenuInterface> m_pauseMenu;
    AbstractGameInterface<In>* m_nextInt = nullptr; // has-a
};


template <typename In>
AbstractLevel<In>::AbstractLevel(unsigned int seed) : m_randomGenerator(seed)
{

}

template <typename In>
AbstractLevel<In>::AbstractLevel(std::seed_seq& seed) : m_randomGenerator(seed)
{

}

template <typename In>
void AbstractLevel<In>::setSeed(unsigned int seed)
{
    m_randomGenerator.seed(seed);
}

template <typename In>
void AbstractLevel<In>::setSeed(std::seed_seq& seed)
{
    m_randomGenerator.seed(seed);
}


template <typename In>
AbstractLevel<In>::~AbstractLevel()
{

}


template <typename In>
std_rng& AbstractLevel<In>::rng()
{
    return m_randomGenerator;
}

template <typename In>
void AbstractLevel<In>::drawIn(AbstractDrawer& window, float dt)
{
    if (m_pauseMenu)
    {
        if (m_pauseMenu->isLayered())
        drawThisIn(window, 0);

        m_pauseMenu->drawIn(window, dt);
    }

    else
    drawThisIn(window, dt);
}

template <typename In>
void AbstractLevel<In>::update(const In& inputData)
{
    if (m_pauseMenu)
    {
        m_pauseMenu->update(inputData);

        if (m_pauseMenu->isDone())
        {
            delete m_nextInt;
            m_nextInt = m_pauseMenu->next();
            m_pauseMenu.reset();

            if (m_nextInt)
            AbstractGameInterface<In>::endThisLater();
        }
    }

    else
    updateThis(inputData);

}


template <typename In>
void AbstractLevel<In>::pauseLevel(std::unique_ptr<AbstractMenuInterface> pauseMenu)
{
    m_pauseMenu = std::move(pauseMenu);
}

template <typename In>
void AbstractLevel<In>::setNextInterface(std::unique_ptr<AbstractGameInterface<In>> nextInt)
{
    m_nextInt = nextInt.release();
}

template <typename In>
AbstractGameInterface<In>* AbstractLevel<In>::next()
{
    return m_nextInt;
}


#endif // LEVEL_HEADER
