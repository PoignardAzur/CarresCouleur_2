
#include "TextBox.hpp"


Menu::TextBox::TextBox(sf::Vector2f boxSize, sf::Color c, const std::string& text, FontStyle f)
{
    set(boxSize, c, text, f);
}

void Menu::TextBox::set(sf::Vector2f boxSize, sf::Color c, const std::string& text, FontStyle f)
{
    m_box.setItem(uptr(new Text(text, f)));
    m_box.setSize(boxSize);
    m_box.setColor(c);
}

sf::Vector2f Menu::TextBox::getSize() const
{
    return m_box.getSize();
}

void Menu::TextBox::drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    m_box.drawIn(target, position, isHitboxDrawn);
}

