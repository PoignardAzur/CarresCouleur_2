

#include "LevelBase.hpp"
#include "Level_HUD.hpp"
#include "GameEndCredits.hpp"
#include "PauseMenu.hpp"


void LevelBase::drawThisIn(AbstractDrawer& window, float dt)
{
    m_carres.drawAllIn(window, sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), dt);
}

void LevelBase::setFont(const sf::Font* font)
{
    m_font = font;
}

void LevelBase::setHUD(Level_HUD* hud)
{
    m_hud = hud;
}

void LevelBase::updateThis(const float& dt)
{
    updatePositions(m_carres, dt);
    m_carres.updateAll(dt);

    for (auto& carre_ptr : m_carres)
    {
        carre_ptr->recycle(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    }


    getInputs()->update(dt);


    if (getInputs()->closeWindow())
    endThisLater();


    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Escape])
    {
        PauseMenu* menu = new PauseMenu();
        menu->set(m_font, getInputs());
        pauseLevel(std::unique_ptr<AbstractMenuInterface>(menu));
    }

    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Space])
    m_carres.clear();


    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Return])
    {
        if (!m_enterPressed)
        setNext();

        m_enterPressed = true;
    }

    else
    m_enterPressed = false;


    if (getInputs()->getMouseButtons()[sf::Mouse::Left])
    {
        if (!m_leftClick)
        leftClick(getInputs()->cursor());

        m_leftClick = true;
    }

    else
    m_leftClick = false;


    if (getInputs()->getMouseButtons()[sf::Mouse::Right])
    {
        if (!m_rightClick)
        rightClick(getInputs()->cursor());

        m_rightClick = true;
    }

    else
    m_rightClick = false;
}

void LevelBase::generateCarre()
{
    CarreCouleur* carre = new CarreCouleur(rng());

    int i = int_dice(1, 4)(rng());
    int s = 1;

    if (i > 2)
    {
        i -= 2;
        s = -1;
    }

    if (i == 1)
    {
        float x = float_dice(WINDOW_WIDTH / 4, WINDOW_WIDTH - WINDOW_WIDTH / 4)(rng());
        float y = WINDOW_HEIGHT * (s + 1) / 2;
        y += s * DEFAULT_CARRE_SIZE / 2;

        float_dice speed(0, DEFAULT_CARRE_SPEED);

        carre->setPos(sf::Vector2f(x, y));
        carre->setSpeed(sf::Vector2f(speed(rng()) - DEFAULT_CARRE_SPEED / 2, speed(rng()) * -s));
    }

    else
    {
        float x = WINDOW_WIDTH * (s + 1) / 2;
        x += s * DEFAULT_CARRE_SIZE / 2;
        float y = float_dice(WINDOW_HEIGHT / 4, WINDOW_HEIGHT - WINDOW_HEIGHT / 4)(rng());

        float_dice speed(0, DEFAULT_CARRE_SPEED);

        carre->setPos(sf::Vector2f(x, y));
        carre->setSpeed(sf::Vector2f(speed(rng()) * -s, speed(rng()) - DEFAULT_CARRE_SPEED / 2));
    }

    getCarres().add(carre);
}

void LevelBase::generateCarreStream(float dt, float minDelay, float maxDelay, int minCarresNumber, int maxCarresNumber)
{
    m_timeBeforeRespawn -= dt;

    if (m_timeBeforeRespawn <= 0)
    {
        m_timeBeforeRespawn = float_dice(minDelay, maxDelay)(rng());

        int i = int_dice(minCarresNumber, maxCarresNumber)(rng());

        while(i--)
        {
            generateCarre();
        }
    }
}


void LevelBase::setNext()
{
    LevelBase* p = getNextLevel();

    if (!p)
    {
        GameEndCredits* credits = new GameEndCredits();
        credits->setUserInputs(getInputs());
        credits->setTargetBounds(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
        credits->setFonts(m_font);
        credits->setAllCredits();

        endThisLater();
        setNextInterface(std::unique_ptr<AbstractGameInterface<float>>(credits));
    }

    else
    {
        giveCarres(p);
        p->increaseScore(score());
        p->setUserInputs(getInputs());

        Level_HUD* hud = new Level_HUD;

        hud->setFont(m_font);
        hud->setLevel(p);
        hud->increaseScore(score(), false);

        endThisLater();
        setNextInterface(std::unique_ptr<AbstractGameInterface<float>>(hud));
    }
}


void LevelBase::increaseScore(int points)
{
    m_score += points;

    if (m_hud)
    m_hud->increaseScore(points);
}

int LevelBase::score() const
{
    return m_score;
}

const VartArray<CarreCouleur>& LevelBase::getCarres() const
{
    return m_carres;
}

VartArray<CarreCouleur>& LevelBase::getCarres()
{
    return m_carres;
}

void LevelBase::giveCarres(LevelBase* nextLevel)
{
    nextLevel->m_carres = std::move(m_carres);
}


