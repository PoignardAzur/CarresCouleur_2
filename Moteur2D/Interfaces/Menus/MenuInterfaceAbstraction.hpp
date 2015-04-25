
#ifndef MENU_INTERFACE_ABSTRACTION_HEADER
#define MENU_INTERFACE_ABSTRACTION_HEADER

#include "../Screens/ScreenAbstraction.hpp"


class MenuInterfaceAbstraction : public ScreenAbstraction
{
    public :

    // those two methods take care of eventual submenus and then call updateThis / drawThisIn
    virtual void drawIn(DrawerAbstraction& window, float dt) const;
    virtual void update(float dt);

    bool loadNewScreen() const;

    virtual bool isLayered() const = 0;
    // if this returns true, the menu is drawn on top of the level / another menu, which must be drawn first


    protected :

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void updateThis(float dt) = 0;

    void openSubmenu(uptrt<MenuInterfaceAbstraction> submenu);
    virtual const MenuInterfaceAbstraction* getSubmenu() const;
    virtual MenuInterfaceAbstraction* getSubmenu();

    void closeMenu();
    void setNextScreenAndClose(ScreenPointer nextScreen);


    private :

    uptrt<MenuInterfaceAbstraction> m_submenu;
    bool m_submenuLoaded = false;

    bool m_loadNewScreen = false;
};


#endif // MENU_INTERFACE_ABSTRACTION_HEADER
