

#include "Text.h"


Menu::Text::Text(const std::string& str, FontStyle f)
{
    setString(str);
    setFont(f);
}

Menu::Text::Text(FontStyle f)
{
    setFont(f);
}


void Menu::Text::setString(const std::string& str)
{
    m_text.setString(str);
    updateParentSize();
}

void Menu::Text::setFontStyle(const FontStyle& f)
{
    m_text.setFont(*(f.f));
    m_text.setCharacterSize(f.charSize);
    m_text.setColor(f.c);

    updateParentSize();
}


void Menu::Text::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    const_cast<Text*>(this)->m_text.setPosition(position.x - m_text.getLocalBounds().left, position.y - m_text.getLocalBounds().top);
    target.draw(m_text);
}

sf::Vector2f Menu::Text::getSize() const
{
    return sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height);
}


