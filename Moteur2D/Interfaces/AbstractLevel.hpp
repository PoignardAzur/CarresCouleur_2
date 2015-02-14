
#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include "Menus/MenuInterfaceAbstraction.hpp"
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


class AbstractLevel : public AbstractGameInterface
{
    public :

    AbstractLevel(unsigned int seed = epoch_to_now().count());
    AbstractLevel(std::seed_seq& seed);
    virtual ~AbstractLevel();

    void setSeed(unsigned int seed = epoch_to_now().count());
    void setSeed(std::seed_seq& seed);

    virtual void setInputs(InputsAbstraction*);

    virtual std_rng& rng();

    virtual void drawIn(DrawerAbstraction& window, float dt) const final;
    virtual void update(float dt) final;


    protected :

    virtual std::list<sf::Mouse::Button> getTriggerButtons() const = 0;
    virtual std::list<sf::Keyboard::Key> getTriggerKeys() const = 0;

    virtual void trigger(sf::Mouse::Button button, bool pressed, sf::Vector2f cursor) = 0;
    virtual void trigger(sf::Keyboard::Key key, bool pressed) = 0;

    virtual void drawThisIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void drawHUDIn(DrawerAbstraction& window, float dt) const = 0;
    virtual void updateThis(float dt) = 0;

    virtual void pauseLevel(std::unique_ptr<MenuInterfaceAbstraction> pauseMenu);
    virtual const MenuInterfaceAbstraction* getPauseMenu() const;
    virtual MenuInterfaceAbstraction* getPauseMenu();

    virtual void setNextInterface(std::unique_ptr<AbstractGameInterface> nextInt);
    virtual up_t<AbstractGameInterface> next();


    private :

    std_rng m_randomGenerator;
    up_t<MenuInterfaceAbstraction> m_pauseMenu;
    bool m_pauseMenuLoaded = false;
    up_t<AbstractGameInterface> m_nextInt;
};


#endif // LEVEL_HEADER
