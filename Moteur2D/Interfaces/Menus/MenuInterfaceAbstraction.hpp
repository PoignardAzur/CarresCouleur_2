
#ifndef MENU_INTERFACE_ABSTRACTION_HEADER
#define MENU_INTERFACE_ABSTRACTION_HEADER

#include "../AbstractGameInterface.hpp"
#include <memory>


class MenuInterfaceAbstraction : public AbstractGameInterface<float>
{
    public :

    void drawIn(DrawerAbstraction& window, float dt);
    void update(const float& inputData);
    AbstractGameInterface<float>* next();

    virtual bool isLayered() const = 0;
    // if this returns true, the menu is drawn on top of the level / another menu, which must be drawn first

    protected :

    void openSubmenu(std::unique_ptr<MenuInterfaceAbstraction> submenu);
    virtual void drawThisIn(DrawerAbstraction& window, float dt) = 0;
    virtual void updateThis(const float& dt) = 0;
    virtual void setNextLevel(AbstractGameInterface<float>* nextLevel);


    private :

    std::unique_ptr<MenuInterfaceAbstraction> m_submenu;
    AbstractGameInterface<float>* m_nextLevel = nullptr;
};


#endif // MENU_INTERFACE_ABSTRACTION_HEADER
