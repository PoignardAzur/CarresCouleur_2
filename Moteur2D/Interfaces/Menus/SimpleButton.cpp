
#include "SimpleButton.hpp"
#include "../Items/ItemBox.hpp"


Menu::SimplePushButton::SimplePushButton(uptrt<AbstractItem> unselected, uptrt<AbstractItem> selected, AbstractItem* parent)
{
    setSprites(move(unselected), move(selected));
    setParent(parent);
}

void Menu::SimplePushButton::setSprites(uptrt<AbstractItem> unselected, uptrt<AbstractItem> selected)
{
    m_unselected_sprite = move(unselected);
    m_selected_sprite = move(selected);

    setParent(m_parent);
}


void Menu::SimplePushButton::setParent(AbstractItem* parent)
{
    if (m_unselected_sprite)
    m_unselected_sprite->setParent(parent);

    if (m_selected_sprite)
    m_selected_sprite->setParent(parent);

    m_parent = parent;
}


const Menu::AbstractItem& Menu::SimplePushButton::currentSprite(bool selected) const
{
    if (selected && m_selected_sprite)
    return *m_selected_sprite;

    else if (m_unselected_sprite)
    return *m_unselected_sprite;

    else
    return ItemBox();
}

