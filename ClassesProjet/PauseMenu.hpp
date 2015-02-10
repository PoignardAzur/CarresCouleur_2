

#ifndef PAUSE_MENU_HEADER
#define PAUSE_MENU_HEADER

#include "../Moteur2D/Interfaces/Menus/AbstractMenuInterface.hpp"
#include "../Moteur2D/Interfaces/Menus/AbstractMenu.hpp"
#include "../Moteur2D/Interfaces/Menus/SimpleButton.hpp"
#include "../Moteur2D/Interfaces/Menus/TextBox.hpp"
#include "../Moteur2D/Interfaces/Items/Text.hpp"


class PauseMenu : public Menu::AbstractMenu, public AbstractMenuInterface
{
    public :

    PauseMenu();
    void set(const sf::Font* f, AbstractInputs* in);
    virtual bool isLayered() const;


    protected :

    //void addButton(AbstractButton* b);
    virtual void drawThisIn(AbstractDrawer& window, float dt);
    virtual void updateThis(const float& dt);


    private :

    Menu::Text m_text;
    Menu::SimpleButton m_yesButton;
    Menu::SimpleButton m_noButton;
};


#endif // PAUSE_MENU_HEADER
