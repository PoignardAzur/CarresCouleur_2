
#ifndef SIMPLE_CREDITS_SCREEN_HEADER
#define SIMPLE_CREDITS_SCREEN_HEADER

#include "AbstractEndCreditsScreen.hpp"
#include "Items/TextObjectAbstraction.hpp"


// Basic implementation of AbstractEndCreditsScreen
class SimpleEndCreditsScreen : public AbstractEndCreditsScreen
{
    public :

    void setAllFonts(const sf::Font* f, unsigned int charSizeMin, const sf::Color& titleColor, const sf::Color& subtitleColor, const sf::Color& creditName, const sf::Color& creditRole);

    void setTitleFont(Menu::FontStyle f);
    void setSubtitleFont(Menu::FontStyle f);
    void setCreditNameFont(Menu::FontStyle f);
    void setCreditRoleFont(Menu::FontStyle f);

    void add_title(const std::string& title);
    void add_subtitle(const std::string& subtitle);
    void add_credit(const std::string& name, const std::string& role, float gap);
    void add_sprite(const sf::Sprite& sprite);

    virtual uptrt<AbstractGameInterface> next() = 0;

//  INHERITED METHODS
//  sf::FloatRect getTargetBounds();
//  virtual void add_item(std::unique_ptr<Menu::ItemAbstraction> item);


    private :

    Menu::FontStyle m_titleFont;
    Menu::FontStyle m_subtitleFont;
    Menu::FontStyle m_creditNameFont;
    Menu::FontStyle m_creditRoleFont;
};


#endif // SIMPLE_CREDITS_SCREEN_HEADER
