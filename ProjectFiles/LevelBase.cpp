
#include "LevelBase.hpp"
#include "Level_HUD.hpp"
#include "GameEndCredits.hpp"

const int WINDOW_HEIGHT = 500;
const int WINDOW_WIDTH = 800;

const float MAX_RESPAWN_DELAY = 4.0;
const int MIN_CARRES_NUMBER = 1;
const int MAX_CARRES_NUMBER = 6;


void LevelBase::setFont(const sf::Font* font)
{
    m_font = font;
}

void LevelBase::setHUD(uptrt<Level_HUD> hud)
{
    m_hud = move(hud);
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

    addCarre(uptr(carre), pos);
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


std::list<sf::Mouse::Button> LevelBase::getTriggerButtons() const
{
    return {sf::Mouse::Left, sf::Mouse::Right};
}

std::list<sf::Keyboard::Key> LevelBase::getTriggerKeys() const
{
    return {sf::Keyboard::Space, sf::Keyboard::Return, sf::Keyboard::Escape};
}

void LevelBase::trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursor)
{
    if (pressed)
    {
        if (button == sf::Mouse::Left)
        {
            leftClick(cursor);
        }

        if (button == sf::Mouse::Right)
        {
            rightClick(cursor);
        }
    }
}

void LevelBase::trigger(sf::Keyboard::Key key, bool pressed)
{
    if (pressed)
    {
        switch (key)
        {
            case sf::Keyboard::Space :
                m_carres.clear();
            break;

            case sf::Keyboard::Return :
                setNext();
            break;

            case sf::Keyboard::Escape :
                m_pauseMenu = new PauseMenu();
                m_pauseMenu->set(m_font, getInputs());
                pauseLevel(std::unique_ptr<MenuInterfaceAbstraction>(m_pauseMenu));
            break;

            default:
            break;
        }
    }
}


void LevelBase::setNext()
{
    uptrt<LevelBase> p = getNextLevel();

    if (!p)
    {
        GameEndCredits* credits = new GameEndCredits();
        credits->setInputs(getInputs());
        credits->setTargetBounds(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
        credits->setFonts(m_font);
        credits->setAllCredits();

        endThisLater();
        setNextInterface(std::unique_ptr<GameInterfaceAbstraction>(credits));
    }

    else
    {
        giveCarres(p.get());

        Level_HUD* hud = new Level_HUD;
        hud->setFont(m_font);
        p->setHUD(uptr(hud));

        p->setFont(m_font);
        p->increaseScore(score(), false);
        p->setInputs(getInputs());

        endThisLater();
        setNextInterface(move(p));
    }
}


void LevelBase::drawThisIn(DrawerAbstraction& window, float dt) const
{
    drawAllIn(m_carres, window, sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), dt);
}

void LevelBase::drawHUDIn(DrawerAbstraction& window, float dt) const
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

    if (getInputs()->closeWindow())
    endThisLater();
}


void LevelBase::increaseScore(int points, bool draw)
{
    m_score += points;
    m_hud->increaseScore(points, draw);
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

void LevelBase::addCarre(uptrt<CarreCouleur> vart, sf::Vector2f pos)
{
    VartPusher<CarreCouleur>(&getCarres()).add(move(vart), pos);
}

void LevelBase::giveCarres(LevelBase* nextLevel)
{
    nextLevel->m_carres = std::move(m_carres);
}


