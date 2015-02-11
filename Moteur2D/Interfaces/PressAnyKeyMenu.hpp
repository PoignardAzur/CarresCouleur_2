

#ifndef PAK_MENU_HEADER
#define PAK_MENU_HEADER

#include "AbstractGameInterface.hpp"
#include <functional>


class PressAnyKeyMenu : public AbstractGameInterface
{
    public :

    virtual void drawIn(DrawerAbstraction& window, float dt) = 0;
    virtual void update(float dt);

    // as soon as a key is pressed, this interface is killed and replaced by nextInterface
    void setNext(AbstractGameInterface* nextInterface);
    void setNext(std::function<AbstractGameInterface*(void)> nextInterface);
    AbstractGameInterface* next();


    private :

    std::function<AbstractGameInterface*(void)> m_nextInterface;
};


#endif // PAK_MENU_HEADER
