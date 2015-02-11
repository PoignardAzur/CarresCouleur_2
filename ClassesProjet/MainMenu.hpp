

#ifndef MAIN_MENU_HEADER
#define MAIN_MENU_HEADER

#include "LevelBase.hpp"
#include "../Moteur2D/Interfaces/Menus/MenuInterfaceAbstraction.hpp"
#include "../Moteur2D/Interfaces/Menus/MenuAbstraction.hpp"
#include "../Moteur2D/Interfaces/Menus/SimpleButton.hpp"
#include "../Moteur2D/Interfaces/Items/Text.hpp"


class MainMenu : public Menu::MenuAbstraction, public MenuInterfaceAbstraction
{
    public :

    MainMenu();
    ~MainMenu() noexcept {};
    void set(const sf::Font* f, InputsAbstraction* in);
    virtual bool isLayered() const;


    protected :

    //void addButton(AbstractButton* b);
    virtual void drawThisIn(DrawerAbstraction& window, float dt);
    virtual void updateThis(float dt);
    void load(up_t<LevelBase> level, const sf::Font* f);


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
