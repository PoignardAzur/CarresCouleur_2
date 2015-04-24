
#ifndef ABSTRACT_CREDITS_SCREEN_HEADER
#define ABSTRACT_CREDITS_SCREEN_HEADER

#include "PressAnyKeyMenu.hpp"
#include "../Items/AbstractItem.hpp"
#include <list>
#include <memory>


extern const int DEFAULT_CREDITS_SPEED;

struct RisingItem
{
    float height;
    std::unique_ptr<Menu::AbstractItem> item;
};


class EndCreditsScreen : public PressKeyToContinue
{
    public :

    void setMargin(float margin);
    void setGap(float gapBetweenItems);
    void setSpeed(float verticalItemSpeed);
    void setTargetBounds(sf::FloatRect bounds);     // usually the bounds of the screen

    virtual void add_title(const std::string& title) = 0;
    virtual void add_subtitle(const std::string& title) = 0;
    virtual void add_credit(const std::string& name, const std::string& role, float gap) = 0;

    virtual void drawIn(DrawerAbstraction& window, float dt) const;
    void drawCreditsIn(DrawerAbstraction& window, float dt) const;
    virtual void update(float dt);
    virtual uptrt<ScreenAbstraction> getNextScreen() = 0;


    protected :

    virtual std::set<sf::Keyboard::Key> getKeysToContinue();

    virtual bool areCreditsDone() const;
    virtual bool endAfterLastCredits() const;

    sf::FloatRect getTargetBounds();
    virtual void add_item(std::unique_ptr<Menu::AbstractItem> item);


    private :

    sf::FloatRect m_targetBounds;

    std::list<std::unique_ptr<Menu::AbstractItem>> m_itemFile;
    std::list<RisingItem> m_risingItemFile;
    void pushItem(float height);
    float lastItemHeight();

    float m_margin = 0;
    float m_gap = 0;
    float m_speed = DEFAULT_CREDITS_SPEED;
};


#endif // ABSTRACT_CREDITS_SCREEN_HEADER
