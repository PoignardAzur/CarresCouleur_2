
#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include "../Menus/MenuInterfaceAbstraction.hpp"
#include <random>
#include <chrono>


inline auto epoch_to_now() -> decltype(std::chrono::system_clock::now().time_since_epoch())
{
    return std::chrono::system_clock::now().time_since_epoch();
}

using float_dice = std::uniform_real_distribution<float>;
using double_dice = std::uniform_real_distribution<double>;
using int_dice= std::uniform_int_distribution<int>;
using std_rng = std::default_random_engine;


class Level : public ScreenAbstraction
{
    public :

    Level(unsigned int seed = epoch_to_now().count());
    Level(std::seed_seq& seed);
    virtual ~Level();

    void setSeed(unsigned int seed = epoch_to_now().count());                   // sets the seed of the level's RNG
    void setSeed(std::seed_seq& seed);

    virtual void setInputs(InputsAbstraction*);

    virtual std_rng& rng();

    virtual void drawIn(DrawerAbstraction& window, float dt) const final;       // those two methods take care of an eventual pause
    virtual void update(float dt) final;                                        // menu then call updateThis / drawThisIn + drawHUDIn


    protected :

    virtual std::list<sf::Mouse::Button> getTriggerButtons() const = 0;         // this method has to return the keys that can be used as
    virtual std::list<sf::Keyboard::Key> getTriggerKeys() const = 0;            // arguments to the method trigger(...)

    virtual void trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursor) = 0;
    virtual void trigger(sf::Keyboard::Key key, bool pressed) = 0;

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void drawHUDIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void updateThis(float dt) = 0;

    virtual void pauseLevel(uptrt<MenuInterfaceAbstraction> pauseMenu);          // this methods pauses the level until pauseMenu is closed
    virtual const MenuInterfaceAbstraction* getPauseMenu() const;
    virtual MenuInterfaceAbstraction* getPauseMenu();


    private :

    std_rng m_randomGenerator;

    uptrt<MenuInterfaceAbstraction> m_pauseMenu;
    bool m_pauseMenuLoaded = false;
};


#endif // LEVEL_HEADER
