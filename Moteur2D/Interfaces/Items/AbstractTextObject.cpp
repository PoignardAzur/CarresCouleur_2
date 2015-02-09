

#include "AbstractTextObject.h"


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


Menu::AbstractTextObject::AbstractTextObject()
{

}

void Menu::AbstractTextObject::setFont(const FontStyle& f)
{
    m_fontStyle = f;
    setFontStyle(f);
}

void Menu::AbstractTextObject::setFont(const sf::Font* f, unsigned int charSize)
{
    setFont(FontStyle(f, charSize, m_fontStyle.c));
}

void Menu::AbstractTextObject::setFont(const sf::Font* f, unsigned int charSize, const sf::Color& c)
{
    setFont(FontStyle(f, charSize, c));
}

void Menu::AbstractTextObject::setColor(const sf::Color& c)
{
    setFont(FontStyle(m_fontStyle.f, m_fontStyle.charSize, c));
}


Menu::FontStyle Menu::AbstractTextObject::getFontStyle() const
{
    return m_fontStyle;
}


