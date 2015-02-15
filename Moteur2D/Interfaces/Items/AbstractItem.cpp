
#include "AbstractItem.hpp"

bool DRAW_ITEM_HITBOX = false; // doesn't need to be const


Menu::AbstractItem::AbstractItem(AbstractItem* parent)
{
    setParent(parent);
}

void Menu::AbstractItem::setParent(AbstractItem* parent)
{
    m_parent = parent;
}

void Menu::AbstractItem::drawIn(DrawerAbstraction& target, sf::Vector2f position, bool drawHitbox) const
{
    if (drawHitbox)
    drawHitboxIn(target, position);

    drawImageIn(target, position, drawHitbox);
}


void Menu::AbstractItem::drawInBox(DrawerAbstraction& target, sf::FloatRect box, Alignement a, bool drawHitbox) const
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

// used to determine the hitbox's color arbitrarily, and differentiate it from other Items' hitboxes
int Menu::AbstractItem::hashToColor(float x) const
{
    return static_cast<int>(x * 17) % 255;
}

void Menu::AbstractItem::drawHitboxIn(DrawerAbstraction& target, sf::Vector2f position) const
{
    sf::RectangleShape hitbox(getSize());
    hitbox.setPosition(position);
    hitbox.setFillColor(sf::Color( hashToColor(position.x), hashToColor(position.y), hashToColor(getSize().x + getSize().y) ));

    target.draw(hitbox);
}


void Menu::AbstractItem::updateParentSize()
{
    if (m_parent)
    m_parent->updateOwnSize();
}

void Menu::AbstractItem::updateOwnSize()
{
    updateParentSize();
}

