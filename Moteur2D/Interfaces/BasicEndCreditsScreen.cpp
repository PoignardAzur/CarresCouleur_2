
#include "BasicEndCreditsScreen.hpp"
#include "Items/ItemBox.hpp"
#include "Items/ItemLine.hpp"
#include "Items/Text.hpp"
#include "Items/Sprite.hpp"


void BasicEndCreditsScreen::setAllFonts(const sf::Font* f, unsigned int charSizeMin, const sf::Color& titleColor, const sf::Color& subtitleColor, const sf::Color& creditNameColor, const sf::Color& creditRoleColor)
{
    setTitleFont(Menu::FontStyle(f, charSizeMin * 3, titleColor));
    setSubtitleFont(Menu::FontStyle(f, charSizeMin * 2, subtitleColor));
    setCreditNameFont(Menu::FontStyle(f, charSizeMin * 1.1, creditNameColor));
    setCreditRoleFont(Menu::FontStyle(f, charSizeMin, creditRoleColor));
}

void BasicEndCreditsScreen::setTitleFont(Menu::FontStyle f)
{
    m_titleFont = f;
}

void BasicEndCreditsScreen::setSubtitleFont(Menu::FontStyle f)
{
    m_subtitleFont = f;
}

void BasicEndCreditsScreen::setCreditNameFont(Menu::FontStyle f)
{
    m_creditNameFont = f;
}

void BasicEndCreditsScreen::setCreditRoleFont(Menu::FontStyle f)
{
    m_creditRoleFont = f;
}


void BasicEndCreditsScreen::add_title(const std::string& title)
{
    Menu::Text* text = new Menu::Text(title, m_titleFont);
    add_item(uptr(text));
}

void BasicEndCreditsScreen::add_subtitle(const std::string& subtitle)
{
    Menu::Text* text = new Menu::Text(subtitle, m_subtitleFont);
    add_item(uptr(text));
}

void BasicEndCreditsScreen::add_credit(const std::string& name, const std::string& role, float gap)
{
    auto text1 = uptr(new Menu::Text(name, m_creditNameFont));
    auto text2 = uptr(new Menu::Text(role, m_creditRoleFont));

    Menu::VerticalItemLine* both = new Menu::VerticalItemLine();
    both->setInternAlignement(Menu::Center);
    both->setGaps(gap);
    both->addItem(move(text1));
    both->addItem(move(text2));

    add_item(uptr(both));
}

void BasicEndCreditsScreen::add_sprite(const sf::Sprite& sprite)
{
    add_item(uptr(new Menu::Sprite(sprite)));
}

