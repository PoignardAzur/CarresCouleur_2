

#ifndef PAK_MENU_HEADER
#define PAK_MENU_HEADER

#include "AbstractGameInterface.h"
#include <functional>


template <typename In>
class PressAnyKeyMenu : public AbstractGameInterface<In>
{
    public :

    virtual void drawIn(AbstractDrawer& window, float dt) = 0;
    virtual void update(const In& inputData);

    void setNext(AbstractGameInterface<In>* nextInterface);         // as soon as a key is pressed, this interface is killed and replaced by nextInterface
    void setNext(std::function<AbstractGameInterface<In>*(void)> nextInterface);
    AbstractGameInterface<In>* next();


    private :

    std::function<AbstractGameInterface<In>*(void)> m_nextInterface;
};


template <typename In>
void PressAnyKeyMenu<In>::update(const In& inputData)
{
    if (AbstractGameInterface<In>::getInputs()->anyKeyPressed())
    AbstractGameInterface<In>::endThisLater();
}

template <typename In>
void PressAnyKeyMenu<In>::setNext(AbstractGameInterface<In>* nextInterface)
{
    setNext
    (
        [=](void)
        {
            return nextInterface;
        }
    );
}

template <typename In>
void PressAnyKeyMenu<In>::setNext(std::function<AbstractGameInterface<In>*(void)> nextInterface)
{
    m_nextInterface = nextInterface;
}

template <typename In>
AbstractGameInterface<In>* PressAnyKeyMenu<In>::next()
{
    return m_nextInterface();
}


#endif // PAK_MENU_HEADER
