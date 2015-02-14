
#ifndef MENU_INTERFACE_HEADER
#define MENU_INTERFACE_HEADER

#include "MenuInterfaceAbstraction.hpp"
#include "MenuAbstraction.hpp"


namespace Menu
{

    class MenuInterface : public Menu::MenuAbstraction, public MenuInterfaceAbstraction
    {
        public :

        MenuInterface(bool isVertical = true, bool doesLoop = false);
        virtual ~MenuInterface() noexcept {}
        virtual void setInputs(InputsAbstraction* inputs);

        virtual bool isLayered() const = 0;


        protected :

        virtual void escape() = 0;
        virtual void drawThisIn(DrawerAbstraction& window, float dt) const = 0;
        virtual void updateThis(float dt);

    };

}


#endif // MENU_INTERFACE_HEADER
