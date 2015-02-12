
#ifndef HUD_HEADER
#define HUD_HEADER

#include "AbstractLevel.hpp"


template <typename LevelType = AbstractLevel>
class AbstractHUD
{
    public :

    explicit AbstractHUD(LevelType* level = nullptr);
    virtual void setLevel(LevelType* level);
    virtual ~AbstractHUD() = default;

    virtual void drawIn(DrawerAbstraction& window, const LevelType& level, float dt) const = 0;
    virtual void update(float dt);


    private:

    LevelType* m_level;
};


template <typename LevelType>
AbstractHUD<LevelType>::AbstractHUD(LevelType* level)
{
    setLevel(level);
}

template <typename LevelType>
void AbstractHUD<LevelType>::setLevel(LevelType* level)
{
    m_level = level;
}

template <typename LevelType>
void AbstractHUD<LevelType>::update(float dt)
{
    (void) dt;
}



#endif // HUD_HEADER
