

#include "ItemAbstraction.hpp"


bool DRAW_ITEM_HITBOX = false; // doesn't need to be const


Menu::ItemAbstraction::ItemAbstraction(ItemAbstraction* parent)
{
    setParent(parent);
}

void Menu::ItemAbstraction::setParent(ItemAbstraction* parent)
{
    m_parent = parent;
}

void Menu::ItemAbstraction::drawIn(DrawerAbstraction& target, sf::Vector2f position, bool drawHitbox) const
{
    if (drawHitbox)
    drawHitboxIn(target, position);

    drawImageIn(target, position, drawHitbox);
}


void Menu::ItemAbstraction::drawInBox(DrawerAbstraction& target, sf::FloatRect box, Alignement a, bool drawHitbox) const
{
    sf::Vector2f position(box.left, box.top);


    if (isRight(a))
    position.x += box.width - getSize().x;

    if (isVerticalMiddle(a))
    position.x += (box.width - getSize().x) / 2;


    if (isBottom(a))
    position.y += box.height - getSize().y;

    if (isHorizontalMiddle(a))
    position.y += (box.height - getSize().y) / 2;


    drawIn(target, position, drawHitbox);
}


int Menu::ItemAbstraction::hashToColor(float x) const
{
    return static_cast<int>(x * 17) % 255;
}

void Menu::ItemAbstraction::drawHitboxIn(DrawerAbstraction& target, sf::Vector2f position) const
{
    sf::RectangleShape hitbox(getSize());
    hitbox.setPosition(position);
    hitbox.setFillColor(sf::Color( hashToColor(position.x), hashToColor(position.y), hashToColor(getSize().x + getSize().y) ));

    target.draw(hitbox);
}


void Menu::ItemAbstraction::updateParentSize()
{
    if (m_parent)
    m_parent->updateOwnSize();
}

void Menu::ItemAbstraction::updateOwnSize()
{
    updateParentSize();
}





