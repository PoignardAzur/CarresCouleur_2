
#ifndef MAIN_MENU_HEADER
#define MAIN_MENU_HEADER

#include "LevelBase.hpp"
#include "../Moteur2D/Interfaces/Menus/MenuInterface.hpp"
#include "../Moteur2D/Interfaces/Menus/SimpleButton.hpp"
#include "../Moteur2D/Interfaces/Items/Text.hpp"


class MainMenu : public BasicMenuInterface
{
    public :

    MainMenu();
    ~MainMenu() noexcept {};
    void set(InputsAbstraction* in, const sf::Font* f);
    virtual bool isLayered() const;


    protected :

    template <typename Level>
    std::function<void(void)> getLevelLoadingFunction(const sf::Font* f);

    virtual const Menu::ButtonListAbstraction& buttonList() const;
    virtual Menu::ButtonListAbstraction& buttonList();

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const;
    void loadNext(uptrt<LevelBase> level, const sf::Font* f);

    void escape();


    private :

    Menu::Text m_text;
    Menu::SimpleButtonList m_buttons;
};


#endif // MAIN_MENU_HEADER
