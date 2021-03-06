
#include "ItemStack.hpp"


Menu::ItemStack::ItemStack()
{
    m_size = sf::Vector2f(0,0);
}

Menu::ItemStack::ItemStack(std::vector<ItemAlignPair> items, bool sizeIsMax)
{
    setItems(std::move(items), sizeIsMax);
}

void Menu::ItemStack::setItems(std::vector<ItemAlignPair> items, bool sizeIsMax)
{
    for (auto& item : items)
    {
        item.first->setParent(this);
    }

    m_items = std::move(items);
    m_sizeIsMax = sizeIsMax;

    updateOwnSize();
}

void Menu::ItemStack::addItem(uptrt<AbstractItem> item, Alignement align)
{
    m_items.push_back(ItemAlignPair(move(item), align));
    item->setParent(this);
    updateOwnSize();
}

void Menu::ItemStack::drawImageIn(DrawerAbstraction& target, sf::Vector2f position, bool isHitboxDrawn) const
{
    sf::FloatRect box(position.x, position.y, m_size.x, m_size.y);

    for (auto const& alignedItem : m_items)
    {
        alignedItem.first->drawInBox(target, box, alignedItem.second, isHitboxDrawn);
    }
}

sf::Vector2f Menu::ItemStack::getSize() const
{
    return m_size;
}

void Menu::ItemStack::updateOwnSize()
{
    if (m_sizeIsMax)
    {
        m_size = sf::Vector2f(0,0);

        for (auto const& alignedItem : m_items)
        {
            m_size.x = m_size.x > alignedItem.first->getSize().x ? m_size.x : alignedItem.first->getSize().x;
            m_size.y = m_size.y > alignedItem.first->getSize().y ? m_size.y : alignedItem.first->getSize().y;
        }
    }

    else if (m_items.size())
    {
        m_size = m_items.front().first->getSize();

        for (auto const& alignedItem : m_items)
        {
            m_size.x = m_size.x < alignedItem.first->getSize().x ? m_size.x : alignedItem.first->getSize().x;
            m_size.y = m_size.y < alignedItem.first->getSize().y ? m_size.y : alignedItem.first->getSize().y;
        }
    }

    else
    m_size = sf::Vector2f(0,0);

    updateParentSize();
}

