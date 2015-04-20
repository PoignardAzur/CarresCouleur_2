
#include "TextObjectAbstraction.hpp"

const int DEFAULT_FONT_SIZE = 30;


Menu::FontStyle::FontStyle(const sf::Font* n_f, unsigned int n_charSize, const sf::Color& n_c)
{
    f = n_f;
    charSize = n_charSize;
    c = n_c;
}

Menu::FontStyle::FontStyle(const FontStyle& other)
{
    f = other.f;
    charSize = other.charSize;
    c = other.c;
}


Menu::TextObjectAbstraction::TextObjectAbstraction()
{

}

Menu::TextObjectAbstraction::~TextObjectAbstraction()
{

}

void Menu::TextObjectAbstraction::setFont(const FontStyle& f)
{
    m_fontStyle = f;
    setFontStyle(f);
}

void Menu::TextObjectAbstraction::setFont(const sf::Font* f, unsigned int charSize)
{
    setFont(FontStyle(f, charSize, m_fontStyle.c));
}

void Menu::TextObjectAbstraction::setFont(const sf::Font* f, unsigned int charSize, const sf::Color& c)
{
    setFont(FontStyle(f, charSize, c));
}

void Menu::TextObjectAbstraction::setColor(const sf::Color& c)
{
    setFont(FontStyle(m_fontStyle.f, m_fontStyle.charSize, c));
}


Menu::FontStyle Menu::TextObjectAbstraction::getFontStyle() const
{
    return m_fontStyle;
}

