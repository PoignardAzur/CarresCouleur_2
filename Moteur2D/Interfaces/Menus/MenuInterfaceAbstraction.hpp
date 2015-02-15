
#ifndef MENU_INTERFACE_ABSTRACTION_HEADER
#define MENU_INTERFACE_ABSTRACTION_HEADER

#include "../GameInterfaceAbstraction.hpp"
#include <memory>


class MenuInterfaceAbstraction : public GameInterfaceAbstraction
{
    public :

    void drawIn(DrawerAbstraction& window, float dt) const final;   // those two methods take care of eventual submenus
    void update(float dt) final;                                    // and then call updateThis / drawThisIn
    uptrt<GameInterfaceAbstraction> next();

    virtual bool isLayered() const = 0;
    // if this returns true, the menu is drawn on top of the level / another menu, which must be drawn first

    protected :

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void updateThis(float dt) = 0;

    void openSubmenu(uptrt<MenuInterfaceAbstraction> submenu);
    virtual const MenuInterfaceAbstraction* getSubmenu() const;
    virtual MenuInterfaceAbstraction* getSubmenu();

    virtual void setNextLevel(uptrt<GameInterfaceAbstraction> nextLevel);
    // calling this method in a submenu before deleting it is equivalent to calling this method for the uppermost parent and deleting it
    // the value of m_nextLevel can be overwritten by the next update, so endThisLater() should be called right after this method

    private :

    uptrt<MenuInterfaceAbstraction> m_submenu;
    bool m_submenuLoaded = false;
    uptrt<GameInterfaceAbstraction> m_nextLevel;
};


#endif // MENU_INTERFACE_ABSTRACTION_HEADER
