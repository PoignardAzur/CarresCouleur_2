

#include "SimpleEndCreditsScreen.h"
#include "Items/ItemBox.h"
#include "Items/ItemStack.h"
#include "Items/Text.h"
#include "Items/Sprite.h"


void SimpleEndCreditsScreen::setAllFonts(const sf::Font* f, unsigned int charSizeMin, const sf::Color& titleColor, const sf::Color& subtitleColor, const sf::Color& creditNameColor, const sf::Color& creditRoleColor)
{
    setTitleFont(Menu::FontStyle(f, charSizeMin * 3, titleColor));
    setSubtitleFont(Menu::FontStyle(f, charSizeMin * 2, subtitleColor));
    setCreditNameFont(Menu::FontStyle(f, charSizeMin * 1.1, creditNameColor));
    setCreditRoleFont(Menu::FontStyle(f, charSizeMin, creditRoleColor));
}

void SimpleEndCreditsScreen::setTitleFont(Menu::FontStyle f)
{
    m_titleFont = f;
}

void SimpleEndCreditsScreen::setSubtitleFont(Menu::FontStyle f)
{
    m_subtitleFont = f;
}

void SimpleEndCreditsScreen::setCreditNameFont(Menu::FontStyle f)
{
    m_creditNameFont = f;
}

void SimpleEndCreditsScreen::setCreditRoleFont(Menu::FontStyle f)
{
    m_creditRoleFont = f;
}


void SimpleEndCreditsScreen::add_title(const std::string& title)
{
    Menu::Text* text = new Menu::Text(title, m_titleFont);
    add_item(std::unique_ptr<Menu::Text>(text));
}

void SimpleEndCreditsScreen::add_subtitle(const std::string& subtitle)
{
    Menu::Text* text = new Menu::Text(subtitle, m_subtitleFont);
    add_item(std::unique_ptr<Menu::Text>(text));
}

void SimpleEndCreditsScreen::add_credit(const std::string& name, const std::string& role)
{
    Menu::Text* text1 = new Menu::Text(name, m_creditNameFont);
    Menu::Text* text2 = new Menu::Text(role, m_creditRoleFont);

    sf::Vector2f size(text1->getSize().x, text1->getSize().y + text2->getSize().y + 30);
    Menu::ItemBox* box = new Menu::ItemBox(text1);
    box->setSize(size);

    Menu::ItemStack* both = new Menu::ItemStack();
    both->addItem(box, Menu::MiddleTopSide);
    both->addItem(text2, Menu::MiddleBottomSide);

    add_item(std::unique_ptr<Menu::ItemStack>(both));
}

void SimpleEndCreditsScreen::add_sprite(const sf::Sprite& sprite)
{
    add_item(std::unique_ptr<Menu::Sprite>(new Menu::Sprite(sprite)));
}

