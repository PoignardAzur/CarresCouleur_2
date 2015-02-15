
#include "GameEndCredits.hpp"
#include "MainMenu.hpp"


GameEndCredits::GameEndCredits()
{

}

void GameEndCredits::setInputs(InputsAbstraction* inputs)
{
    AbstractGameInterface::setInputs(inputs);

    EventsMap::MouseEventsMap mouseEvents;
    EventsMap::KeyboardEventsMap keyboardEvents;

    keyboardEvents[sf::Keyboard::Space] = [this](bool pressed)
    {
        if (pressed)
        {
            endThisLater();
        }
    };

    keyboardEvents[sf::Keyboard::Return] = [this](bool pressed)
    {
        if (pressed)
        {
            endThisLater();
        }
    };

    keyboardEvents[sf::Keyboard::Escape] = [this](bool pressed)
    {
        if (pressed)
        {
            endThisLater();
        }
    };

    setInputsEvents(std::move(mouseEvents), std::move(keyboardEvents));
}

void GameEndCredits::setFonts(const sf::Font* f)
{
    setAllFonts(f, DEFAULT_FONT_SIZE / 2, sf::Color::Red, sf::Color::Yellow, sf::Color(200, 200, 200), sf::Color::White);
    m_font = f;
}

void GameEndCredits::setAllCredits()
{
    setGap(30);

    add_title("CARRES COULEUR 2");
    add_subtitle("Le retour de la vengeance");

    add_credit("Game Design", "Olivier FAURE", 10);
    add_credit("Sound Design", "-", 10);
    add_credit("Graphismes", "Olivier FAURE", 10);
    add_credit("Scenario", "-", 10);
    add_credit("Level Design", "-", 10);
    add_credit("Marketing", "-", 10);
    add_credit("Distribution", "-", 10);
}

void GameEndCredits::update(float dt)
{
    SimpleEndCreditsScreen::AbstractEndCreditsScreen::update(dt);

    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Key::Return])
    {
        if (!m_enterPressed)
        endThisLater();

        m_enterPressed = true;
    }

    else
    m_enterPressed = false;
}

up_t<AbstractGameInterface> GameEndCredits::next()
{
    MainMenu* menu = new MainMenu;
    menu->set(getInputs(), m_font);
    return up(menu);
}

