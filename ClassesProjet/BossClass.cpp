

#include "BossClass.h"

#include "MainMenu.h"
#include "Level_HUD.h"
#include "TitleScreen.h"

#define FONT_FILE_NAME "Resources/arial.ttf"


BossClass::BossClass(AbstractInputs* userInputs, sf::RenderWindow* target) : GameController(userInputs, target)
{
    if (!m_font.loadFromFile(FONT_FILE_NAME))
    throw "Couldn't load font" FONT_FILE_NAME;

    MainMenu* menu = new MainMenu;
    menu->set(&m_font, userInputs);

    m_interface.setInterface(new TitleScreen(menu, userInputs, &m_font));
}

AbstractGameInterface<float>* BossClass::interface()
{
    return &m_interface;
}

void BossClass::update(float dt)
{
    GameController::update(dt);
}

bool BossClass::isDone() const
{
    return m_interface.isDone();
}

