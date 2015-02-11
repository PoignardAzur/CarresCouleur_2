
#ifndef HUD_HEADER
#define HUD_HEADER

#include "AbstractLevel.hpp"


template <typename LevelType = AbstractLevel>
class AbstractHUD : public AbstractGameInterface
{
    public :

    explicit AbstractHUD(LevelType* level = nullptr);
    virtual void setLevel(LevelType* level);
    virtual ~AbstractHUD();

    virtual void drawIn(DrawerAbstraction& window, float dt);
    virtual void setUserInputs(InputsAbstraction*);

    virtual void update(float dt);
    virtual bool isDone() const;
    virtual AbstractGameInterface* next();


    protected :

    virtual InputsAbstraction* getInputs();
    virtual const InputsAbstraction* getInputs() const;

    virtual void drawIn(DrawerAbstraction& window, LevelType* level, float dt) = 0;
    virtual const LevelType* getLevel() const;

    private:

    LevelType* m_level;
};



template <typename LevelType>
AbstractHUD<LevelType>::AbstractHUD(LevelType* level)
{
    setLevel(level);
}

template <typename LevelType>
AbstractHUD<LevelType>::~AbstractHUD()
{
    if (m_level)
    delete m_level;
}


template <typename LevelType>
void AbstractHUD<LevelType>::setLevel(LevelType* level)
{
    m_level = level;
}


template <typename LevelType>
void AbstractHUD<LevelType>::drawIn(DrawerAbstraction& window, float dt)
{
    drawIn(window, m_level, dt);
}

template <typename LevelType>
const LevelType* AbstractHUD<LevelType>::getLevel() const
{
    return m_level;
}


template <typename LevelType>
bool AbstractHUD<LevelType>::isDone() const
{
    return m_level->isDone();
}


template <typename LevelType>
void AbstractHUD<LevelType>::setUserInputs(InputsAbstraction* userInputs)
{
    m_level->setUserInputs(userInputs);
}


template <typename LevelType>
void AbstractHUD<LevelType>::update(float dt)
{
    m_level->update(dt);
}


template <typename LevelType>
AbstractGameInterface* AbstractHUD<LevelType>::next()
{
    return m_level->next();
}

template <typename LevelType>
InputsAbstraction* AbstractHUD<LevelType>::getInputs()
{
    return nullptr;
}

template <typename LevelType>
const InputsAbstraction* AbstractHUD<LevelType>::getInputs() const
{
    return nullptr;
}


#endif // HUD_HEADER
