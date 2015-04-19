
#include "ItemLine.hpp"


// ITEM LINE

Menu::ItemLine::ItemLine()
{

}

Menu::ItemLine::ItemLine(std::vector<SharedItem> items, float gaps, bool vertical) : AbstractItemLine(std::move(items), gaps)
{
    setVertical(vertical);
}

void Menu::ItemLine::setVertical(bool vertical)
{
    m_vertical = vertical;
    updateOwnSize();
}

bool Menu::ItemLine::isVertical() const
{
    return m_vertical;
}


// VERTICAL ITEM LINE

Menu::VerticalItemLine::VerticalItemLine()
{

}

Menu::VerticalItemLine::VerticalItemLine(std::vector<SharedItem> items, float gaps) : AbstractItemLine(std::move(items), gaps)
{

}

bool Menu::VerticalItemLine::isVertical() const
{
    return true;
}


// HORIZONTAL ITEM LINE

Menu::HorizontalItemLine::HorizontalItemLine()
{

}

Menu::HorizontalItemLine::HorizontalItemLine(std::vector<SharedItem> items, float gaps) : AbstractItemLine(std::move(items), gaps)
{

}

bool Menu::HorizontalItemLine::isVertical() const
{
    return false;
}

