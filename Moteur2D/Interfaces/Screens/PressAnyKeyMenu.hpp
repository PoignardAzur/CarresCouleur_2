
#ifndef PAK_MENU_HEADER
#define PAK_MENU_HEADER

#include "GameInterfaceAbstraction.hpp"
#include <functional>


// A simple menu to begin the game ; the menu is replaced by the next one when you press a key
class PressAnyKeyMenu : public GameInterfaceAbstraction
{
    public :

    virtual void drawIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void update(float dt);

    // as soon as a key is pressed, this interface is killed and replaced by nextInterface
    void setNext(uptrt<GameInterfaceAbstraction> nextInterface);
    void setNext(std::function<uptrt<GameInterfaceAbstraction>(void)> nextInterface);
    uptrt<GameInterfaceAbstraction> next();


    private :

    std::function<uptrt<GameInterfaceAbstraction>(void)> m_nextInterface;
};


#endif // PAK_MENU_HEADER
