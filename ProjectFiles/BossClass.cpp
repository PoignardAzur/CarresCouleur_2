
#include "BossClass.hpp"
#include "Level_HUD.hpp"
#include "TitleScreen.hpp"

#define FONT_FILE_NAME "Resources/arial.ttf"


BossClass::BossClass(uptrt<InputsAbstraction> userInputs, sf::RenderWindow* target) : GameController(move(userInputs), target)
{
    if (!m_font.loadFromFile(FONT_FILE_NAME))
    throw "Couldn't load font" FONT_FILE_NAME;

    m_screen.reset(new TitleScreen(&windowInputs(), &m_font));
    m_screen->load();
}

ScreenAbstraction& BossClass::interface()
{
    return *m_screen;
}

void BossClass::update(float dt)
{
    GameController::update(dt);

    if (m_screen->isDone())
    {
        m_screen = m_screen->getNextScreen();

        if (!m_screen)
        m_isDone = true;

        else
        m_screen->load();
    }
}

bool BossClass::isDone() const
{
    return m_isDone;
}

