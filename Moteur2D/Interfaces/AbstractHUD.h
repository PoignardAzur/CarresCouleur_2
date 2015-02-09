

#ifndef HUD_HEADER
#define HUD_HEADER

#include "AbstractLevel.h"


template <typename In, typename LevelType = AbstractLevel<In> >
class AbstractHUD : public AbstractGameInterface<In>
{
    public :

    explicit AbstractHUD(LevelType* level = 0);
    virtual void setLevel(LevelType* level);
    virtual ~AbstractHUD();

    virtual void drawIn(AbstractDrawer& window, float dt);
    virtual void setUserInputs(AbstractInputs*);

    virtual void update(const In& inputData);
    virtual bool isDone() const;
    virtual AbstractGameInterface<In>* next();


    protected :

    virtual AbstractInputs* getInputs();
    virtual const AbstractInputs* getInputs() const;

    virtual void drawIn(AbstractDrawer& window, LevelType* level, float dt) = 0;
    virtual const LevelType* getLevel() const;

    private:

    LevelType* m_level;
};



template <typename In, typename LevelType>
AbstractHUD<In, LevelType>::AbstractHUD(LevelType* level)
{
    setLevel(level);
}

template <typename In, typename LevelType>
AbstractHUD<In, LevelType>::~AbstractHUD()
{
    if (m_level)
    delete m_level;
}


template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::setLevel(LevelType* level)
{
    m_level = level;
}




template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::drawIn(AbstractDrawer& window, float dt)
{
    drawIn(window, m_level, dt);
}

template <typename In, typename LevelType>
const LevelType* AbstractHUD<In, LevelType>::getLevel() const
{
    return m_level;
}





template <typename In, typename LevelType>
bool AbstractHUD<In, LevelType>::isDone() const
{
    return m_level->isDone();
}


template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::setUserInputs(AbstractInputs* userInputs)
{
    m_level->setUserInputs(userInputs);
}


template <typename In, typename LevelType>
void AbstractHUD<In, LevelType>::update(const In& inputData)
{
    m_level->update(inputData);
}



template <typename In, typename LevelType>
AbstractGameInterface<In>* AbstractHUD<In, LevelType>::next()
{
    return m_level->next();
}

template <typename In, typename LevelType>
AbstractInputs* AbstractHUD<In, LevelType>::getInputs()
{
    return nullptr;
}


template <typename In, typename LevelType>
const AbstractInputs* AbstractHUD<In, LevelType>::getInputs() const
{
    return nullptr;
}






#endif // HUD_HEADER

