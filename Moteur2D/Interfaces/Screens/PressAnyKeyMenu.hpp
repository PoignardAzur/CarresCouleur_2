
#ifndef PAK_MENU_HEADER
#define PAK_MENU_HEADER

#include "GameInterfaceAbstraction.hpp"
#include <functional>
#include <set>


// A simple menu to begin the game ; the menu is replaced by the next one when you press a key
class PressKeyToContinue : public ScreenAbstraction
{
    public :

    virtual void setInputs(InputsAbstraction* inputs);

    virtual void update(float dt);
    virtual void drawIn(DrawerAbstraction& window, float dt) const = 0;
    virtual ScreenPointer getNextScreen() = 0;


    protected :

    virtual std::set<sf::Keyboard::Key> getKeysToContinue();
};


#endif // PAK_MENU_HEADER
