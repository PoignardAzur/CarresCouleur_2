


#include "Counter.h"



Menu::Counter::Counter(FontStyle f, bool rightAligned, int n, int min, int max, int base)
{
    setFont(f);
    setRightAligned(rightAligned);

    setValue(n);
    setBounds(min, max);
//    setBase(base);
}

Menu::Counter::Counter(int n, int min, int max, int base)
{
    setValue(n);
    setBounds(min, max);
    //setBase(base);
}

void Menu::Counter::setValue(int n)
{
    m_value = n;

    updateText();
}

void Menu::Counter::setBounds(int min, int max)
{
    m_minimumValue = min;
    m_maximumValue = max;

    updateText();
    updateOwnSize();
}
/*
void Menu::Counter::setBase(int base)
{
    m_base = base;

    updateText();
    updateSize();
}*/

void Menu::Counter::setRightAligned(bool rightAligned)
{
    m_rightAligned = rightAligned;
}

void Menu::Counter::setFontStyle(const FontStyle& f)
{
    m_drawnText.setFont(f);

    updateOwnSize();
}


void Menu::Counter::drawImageIn(AbstractDrawer& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    if (m_rightAligned)
    m_drawnText.drawIn(target, sf::Vector2f(position.x + getSize().x - m_drawnText.getSize().x, position.y), isHitboxDrawn);

    else
    m_drawnText.drawIn(target, position, isHitboxDrawn);
}


sf::Vector2f Menu::Counter::getSize() const
{
    return m_size;
}



void Menu::Counter::updateOwnSize()
{
    std::string currentText = std::to_string(m_value > m_maximumValue ? m_maximumValue : (m_value < m_minimumValue ? m_minimumValue : m_value));

    m_drawnText.setString(std::to_string(m_maximumValue));
    sf::Vector2f size1 = m_drawnText.getSize();

    m_drawnText.setString(std::to_string(m_minimumValue));
    sf::Vector2f size2 = m_drawnText.getSize();

    m_size.x = size1.x > size2.x ? size1.x : size2.x;
    m_size.y = size1.y > size2.y ? size1.y : size2.y;

    m_drawnText.setString(currentText);
    updateParentSize();
}


void Menu::Counter::updateText()
{
    m_drawnText.setString(std::to_string(m_value > m_maximumValue ? m_maximumValue : (m_value < m_minimumValue ? m_minimumValue : m_value)));
}







