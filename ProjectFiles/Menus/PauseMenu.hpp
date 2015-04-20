
#ifndef PAUSE_MENU_HEADER
#define PAUSE_MENU_HEADER

#include "../../Moteur2D/Interfaces/Menus/MenuInterface.hpp"
#include "../../Moteur2D/Interfaces/Menus/SimpleButtonList.hpp"
#include "../../Moteur2D/Interfaces/Items/Text.hpp"


class PauseMenu : public BasicMenuInterface
{
    public :

    PauseMenu();
    void set(const sf::Font* f, InputsAbstraction* in);

    virtual bool isLayered() const;


    protected :

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const;

    virtual const Menu::ButtonListAbstraction& buttonList() const;
    virtual Menu::ButtonListAbstraction& buttonList();


    private :

    Menu::Text m_text;
    Menu::SimpleButtonList m_buttons;
};


#endif // PAUSE_MENU_HEADER
