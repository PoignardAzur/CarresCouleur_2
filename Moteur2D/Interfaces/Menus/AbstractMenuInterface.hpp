

#ifndef ABSTRACT_MENU_INTERFACE
#define ABSTRACT_MENU_INTERFACE

#include "../AbstractGameInterface.h"
#include <memory>


class AbstractMenuInterface : public AbstractGameInterface<float>
{
    public :

    void drawIn(AbstractDrawer& window, float dt);
    void update(const float& inputData);
    AbstractGameInterface<float>* next();

    virtual bool isLayered() const = 0;
    // if this returns true, the menu is drawn on top of the level / another menu, which must be drawn first

    protected :

    void openSubmenu(std::unique_ptr<AbstractMenuInterface> submenu);
    virtual void drawThisIn(AbstractDrawer& window, float dt) = 0;
    virtual void updateThis(const float& dt) = 0;
    virtual void setNextLevel(AbstractGameInterface<float>* nextLevel);


    private :

    std::unique_ptr<AbstractMenuInterface> m_submenu;
    AbstractGameInterface<float>* m_nextLevel = nullptr;
};

#endif // ABSTRACT_MENU_INTERFACE
