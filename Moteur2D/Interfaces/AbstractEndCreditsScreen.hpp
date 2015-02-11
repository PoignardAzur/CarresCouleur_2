

#ifndef ABSTRACT_CREDITS_SCREEN_HEADER
#define ABSTRACT_CREDITS_SCREEN_HEADER

#include "AbstractGameInterface.hpp"
#include "Items/ItemAbstraction.hpp"
#include <list>
#include <memory>

#define DEFAULT_CREDITS_SPEED 60


struct RisingItem
{
    float height;
    std::unique_ptr<Menu::ItemAbstraction> item;
};


class AbstractEndCreditsScreen : public AbstractGameInterface<float>
{
    public :

    void setMargin(float margin);
    void setGap(float gapBetweenItems);
    void setSpeed(float verticalItemSpeed);
    void setTargetBounds(sf::FloatRect bounds);

    virtual void add_title(const std::string& title) = 0;
    virtual void add_subtitle(const std::string& title) = 0;
    virtual void add_credit(const std::string& name, const std::string& role) = 0;

    void drawIn(DrawerAbstraction& window, float dt);
    void update(const float& inputData);

    virtual AbstractGameInterface<float>* next() = 0;


    protected :

    sf::FloatRect getTargetBounds();
    virtual void add_item(std::unique_ptr<Menu::ItemAbstraction> item);


    private :

    sf::FloatRect m_targetBounds;

    std::list<std::unique_ptr<Menu::ItemAbstraction>> m_itemFile;
    std::list<RisingItem> m_risingItemFile;

    float m_margin = 0;
    float m_gap = 0;
    float m_speed = DEFAULT_CREDITS_SPEED;
};


#endif // CREDIT_SCREEN_HEADER
