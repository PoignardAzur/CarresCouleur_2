

#include "LevelBase.hpp"
#include "Level_HUD.hpp"
#include "GameEndCredits.hpp"
#include "PauseMenu.hpp"


void LevelBase::setFont(const sf::Font* font)
{
    m_font = font;
}

void LevelBase::setHUD(up_t<Level_HUD> hud)
{
    m_hud = mv(hud);
}

void LevelBase::generateCarre()
{
    CarreCouleur* carre = new CarreCouleur(rng());
    sf::Vector2f pos;

    int i = int_dice(1, 4)(rng());
    int s = 1;

    if (i > 2)
    {
        i -= 2;
        s = -1;
    }

    if (i == 1)
    {
        pos.x = float_dice(WINDOW_WIDTH / 4, WINDOW_WIDTH - WINDOW_WIDTH / 4)(rng());
        pos.y = WINDOW_HEIGHT * (s + 1) / 2;
        pos.y += s * DEFAULT_CARRE_SIZE / 2;

        float_dice speed(0, DEFAULT_CARRE_SPEED);
        carre->setSpeed(sf::Vector2f(speed(rng()) - DEFAULT_CARRE_SPEED / 2, speed(rng()) * -s));
    }

    else
    {
        pos.x = WINDOW_WIDTH * (s + 1) / 2;
        pos.x += s * DEFAULT_CARRE_SIZE / 2;
        pos.y = float_dice(WINDOW_HEIGHT / 4, WINDOW_HEIGHT - WINDOW_HEIGHT / 4)(rng());

        float_dice speed(0, DEFAULT_CARRE_SPEED);
        carre->setSpeed(sf::Vector2f(speed(rng()) * -s, speed(rng()) - DEFAULT_CARRE_SPEED / 2));
    }

    addCarre(up(carre), pos);
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
    up_t<LevelBase> p = getNextLevel();

    if (!p)
    {
        GameEndCredits* credits = new GameEndCredits();
        credits->setUserInputs(getInputs());
        credits->setTargetBounds(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
        credits->setFonts(m_font);
        credits->setAllCredits();

        endThisLater();
        setNextInterface(std::unique_ptr<AbstractGameInterface>(credits));
    }

    else
    {
        giveCarres(p.get());

        Level_HUD* hud = new Level_HUD;
        hud->setFont(m_font);
        p->setHUD(up(hud));

        p->setFont(m_font);
        p->increaseScore(score());
        p->setUserInputs(getInputs());

        endThisLater();
        setNextInterface(mv(p));
    }
}


void LevelBase::drawThisIn(DrawerAbstraction& window, float dt)
{
    drawAllIn(m_carres, window, sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), dt);
}

void LevelBase::drawHUDIn(DrawerAbstraction& window, float dt)
{
    m_hud->drawIn(window, *this, dt);
}

void LevelBase::updateThis(float dt)
{
    updateAllPositions(m_carres, dt);
    updateAll(m_carres, dt);
    m_hud->update(dt);

    for (auto& placedCarre : m_carres)
    {
        placedCarre.get().recycle(placedCarre.getPos(), sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    }


    getInputs()->update(dt);


    if (getInputs()->closeWindow())
    endThisLater();


    if (getInputs()->getKeyboardButtons()[sf::Keyboard::Escape])
    {
        PauseMenu* menu = new PauseMenu();
        menu->set(m_font, getInputs());
        pauseLevel(std::unique_ptr<MenuInterfaceAbstraction>(menu));
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


void LevelBase::increaseScore(int points)
{
    m_score += points;
    m_hud->increaseScore(points);
}

int LevelBase::score() const
{
    return m_score;
}

const VartList<CarreCouleur>& LevelBase::getCarres() const
{
    return m_carres;
}

VartList<CarreCouleur>& LevelBase::getCarres()
{
    return m_carres;
}

void LevelBase::addCarre(up_t<CarreCouleur> vart, sf::Vector2f pos)
{
    VartPusher<CarreCouleur>(&getCarres()).add(mv(vart), pos);
}

void LevelBase::giveCarres(LevelBase* nextLevel)
{
    nextLevel->m_carres = std::move(m_carres);
}


