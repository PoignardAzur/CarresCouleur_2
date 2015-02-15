
#ifndef PAK_MENU_HEADER
#define PAK_MENU_HEADER

#include "AbstractGameInterface.hpp"
#include <functional>


// A simple menu to begin the game ; the menu is replaced by the next one when you press a key
class PressAnyKeyMenu : public AbstractGameInterface
{
    public :

    virtual void drawIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void update(float dt);

    // as soon as a key is pressed, this interface is killed and replaced by nextInterface
    void setNext(uptrt<AbstractGameInterface> nextInterface);
    void setNext(std::function<uptrt<AbstractGameInterface>(void)> nextInterface);
    uptrt<AbstractGameInterface> next();


    private :

    std::function<uptrt<AbstractGameInterface>(void)> m_nextInterface;
};


#endif // PAK_MENU_HEADER
