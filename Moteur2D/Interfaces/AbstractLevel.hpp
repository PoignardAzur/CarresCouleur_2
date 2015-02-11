
#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include "Menus/MenuInterfaceAbstraction.hpp"
#include <random>
#include <chrono>
#include <memory>


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
    void setSeed(unsigned int seed = epoch_to_now().count());
    void setSeed(std::seed_seq& seed);
    virtual ~AbstractLevel();

    virtual std_rng& rng();

    virtual void drawIn(DrawerAbstraction& window, float dt) final;
    virtual void update(float dt) final;

    virtual void drawThisIn(DrawerAbstraction& window, float dt) = 0;
    virtual void updateThis(float dt) = 0;

    virtual void pauseLevel(std::unique_ptr<MenuInterfaceAbstraction> pauseMenu);
    virtual void setNextInterface(std::unique_ptr<AbstractGameInterface> nextInt);  /// TODO - Delete that, or make it protected ?
    virtual AbstractGameInterface* next();


    private :

    std_rng m_randomGenerator;
    std::unique_ptr<MenuInterfaceAbstraction> m_pauseMenu;
    AbstractGameInterface* m_nextInt = nullptr; // has-a
};


#endif // LEVEL_HEADER
