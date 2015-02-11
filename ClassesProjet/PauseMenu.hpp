

#ifndef PAUSE_MENU_HEADER
#define PAUSE_MENU_HEADER

#include "../Moteur2D/Interfaces/Menus/MenuInterfaceAbstraction.hpp"
#include "../Moteur2D/Interfaces/Menus/MenuAbstraction.hpp"
#include "../Moteur2D/Interfaces/Menus/SimpleButton.hpp"
#include "../Moteur2D/Interfaces/Menus/TextBox.hpp"
#include "../Moteur2D/Interfaces/Items/Text.hpp"


class PauseMenu : public Menu::MenuAbstraction, public MenuInterfaceAbstraction
{
    public :

    PauseMenu();
    ~PauseMenu() noexcept {}
    void set(const sf::Font* f, InputsAbstraction* in);
    virtual bool isLayered() const;


    protected :

    //void addButton(AbstractButton* b);
    virtual void drawThisIn(DrawerAbstraction& window, float dt);
    virtual void updateThis(float dt);


    private :

    Menu::Text m_text;
    Menu::SimpleButton m_yesButton;
    Menu::SimpleButton m_noButton;
};


#endif // PAUSE_MENU_HEADER
