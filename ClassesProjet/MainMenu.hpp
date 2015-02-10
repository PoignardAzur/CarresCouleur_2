

#ifndef MAIN_MENU_HEADER
#define MAIN_MENU_HEADER

#include "LevelBase.hpp"
#include "../Moteur2D/Interfaces/Menus/AbstractMenuInterface.hpp"
#include "../Moteur2D/Interfaces/Menus/AbstractMenu.hpp"
#include "../Moteur2D/Interfaces/Menus/SimpleButton.hpp"
#include "../Moteur2D/Interfaces/Items/Text.hpp"


class MainMenu : public Menu::AbstractMenu, public AbstractMenuInterface
{
    public :

    MainMenu();
    void set(const sf::Font* f, AbstractInputs* in);
    virtual bool isLayered() const;


    protected :

    //void addButton(AbstractButton* b);
    virtual void drawThisIn(AbstractDrawer& window, float dt);
    virtual void updateThis(const float& dt);
    void load(LevelBase* level, const sf::Font* f);


    private :

    Menu::Text m_text;

    Menu::SimpleButton m_level_1_button;
    Menu::SimpleButton m_level_2_button;
    Menu::SimpleButton m_level_3_button;
    Menu::SimpleButton m_level_4_button;
    Menu::SimpleButton m_quit_button;

    bool m_enterPressed = true;
    bool m_spacePressed = true;

    bool m_upPressed = true;
    bool m_downPressed = true;
};


#endif // MAIN_MENU_HEADER
