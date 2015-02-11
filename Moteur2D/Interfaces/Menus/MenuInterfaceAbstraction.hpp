
#ifndef MENU_INTERFACE_ABSTRACTION_HEADER
#define MENU_INTERFACE_ABSTRACTION_HEADER

#include "../AbstractGameInterface.hpp"
#include <memory>


class MenuInterfaceAbstraction : public AbstractGameInterface
{
    public :

    void drawIn(DrawerAbstraction& window, float dt);
    void update(float dt);
    up_t<AbstractGameInterface> next();

    virtual bool isLayered() const = 0;
    // if this returns true, the menu is drawn on top of the level / another menu, which must be drawn first

    protected :

    void openSubmenu(up_t<MenuInterfaceAbstraction> submenu);
    virtual void drawThisIn(DrawerAbstraction& window, float dt) = 0;
    virtual void updateThis(float dt) = 0;
    virtual void setNextLevel(up_t<AbstractGameInterface> nextLevel);


    private :

    up_t<MenuInterfaceAbstraction> m_submenu;
    up_t<AbstractGameInterface> m_nextLevel;
};


#endif // MENU_INTERFACE_ABSTRACTION_HEADER
