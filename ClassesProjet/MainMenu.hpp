
#ifndef MAIN_MENU_HEADER
#define MAIN_MENU_HEADER

#include "LevelBase.hpp"
#include "../Moteur2D/Interfaces/Menus/MenuInterface.hpp"
#include "../Moteur2D/Interfaces/Menus/SimpleButton.hpp"
#include "../Moteur2D/Interfaces/Items/Text.hpp"


class MainMenu : public Menu::MenuInterface
{
    public :

    MainMenu();
    ~MainMenu() noexcept {};
    void set(InputsAbstraction* in, const sf::Font* f);
    virtual bool isLayered() const;


    protected :

    //void addButton(AbstractButton* b);
    virtual void drawThisIn(DrawerAbstraction& window, float dt) const;
    void load(uptrt<LevelBase> level, const sf::Font* f);

    void escape();


    private :

    Menu::Text m_text;

    Menu::SimpleButton m_level_1_button;
    Menu::SimpleButton m_level_2_button;
    Menu::SimpleButton m_level_3_button;
    Menu::SimpleButton m_level_4_button;
    Menu::SimpleButton m_quit_button;
};

uptrt<Menu::AbstractItem> yellowBox(const char* str, Menu::FontStyle& fs, bool small = false);
uptrt<Menu::AbstractItem> redBox(const char* str, Menu::FontStyle& fs, bool small = false);


#endif // MAIN_MENU_HEADER
