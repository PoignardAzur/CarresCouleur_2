
#include "BossClass.hpp"
#include "MainMenu.hpp"
#include "Level_HUD.hpp"
#include "TitleScreen.hpp"

#define FONT_FILE_NAME "Resources/arial.ttf"


BossClass::BossClass(up_t<InputsAbstraction> userInputs, sf::RenderWindow* target) : GameController(mv(userInputs), target)
{
    if (!m_font.loadFromFile(FONT_FILE_NAME))
    throw "Couldn't load font" FONT_FILE_NAME;

    MainMenu* menu = new MainMenu;
    menu->set(&m_font, &windowInputs());

    m_interface.reset(new TitleScreen(menu, &windowInputs(), &m_font));
}

AbstractGameInterface& BossClass::interface()
{
    return *(m_interface.get());
}

void BossClass::update(float dt)
{
    GameController::update(dt);

    if (m_interface->isDone())
    {
        m_interface = m_interface->next();

        if (!m_interface)
        m_isDone = true;
    }
}

bool BossClass::isDone() const
{
    return m_isDone;
}

