
#ifndef BASIC_MENU_INTERFACE_HEADER
#define BASIC_MENU_INTERFACE_HEADER

#include "MenuInterfaceAbstraction.hpp"
#include "ButtonListAbstraction.hpp"

#include <functional>


class BasicMenuInterface : public MenuInterfaceAbstraction
{
    public :

    virtual void setInputs(InputsAbstraction* inputs);

    virtual bool isLayered() const = 0;


    protected :

    template <typename Screen>
    std::function<void(void)> getLoadingFunction();

    template <typename Menu>
    std::function<void(void)> getSubmenuFunction();

    virtual const Menu::ButtonListAbstraction& buttonList() const = 0;
    virtual Menu::ButtonListAbstraction& buttonList() = 0;
    virtual void escape();  // this method is called when the Esc button is pressed

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void updateThis(float dt);
};


template <typename Screen>
std::function<void(void)> BasicMenuInterface::getLoadingFunction()
{
    return [this]()
    {
        setNextScreenAndClose(uptr(new Screen));
    };
}

template <typename Menu>
std::function<void(void)> BasicMenuInterface::getSubmenuFunction()
{
    return [this]()
    {
        openSubmenu(uptr(new Menu));
    };
}


#endif // BASIC_MENU_INTERFACE_HEADER
