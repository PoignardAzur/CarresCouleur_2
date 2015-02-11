

#include "Level_HUD.hpp"

#define SCORE_BOX_GAPS 20
#define PLUS_MARK_DURATION 1


sf::Color plusMarkColor(int alpha)
{
    return sf::Color(200, 200, 0, alpha);
}


Level_HUD::Level_HUD()
{
    m_score_ptr = new Menu::Counter(Menu::FontStyle(), true, 0, 0 , 10000);
    m_box.setItem(m_score_ptr);
    m_box.setSize(sf::Vector2f(SCORE_BOX_GAPS, SCORE_BOX_GAPS), true);
    m_box.setAlignement(Menu::MiddleRightSide, SCORE_BOX_GAPS, 0);
    m_box.setColor(sf::Color(128, 128, 128));
}

void Level_HUD::setFont(const sf::Font* font)
{
    m_font = font;
    m_score_ptr->setFont(m_font, DEFAULT_FONT_SIZE * 2, sf::Color::White);
}

void Level_HUD::setLevel(LevelBase* level)
{
    AbstractHUD<LevelBase>::setLevel(level);
    level->setHUD(this);
    level->setFont(m_font);
}

void Level_HUD::update(const float& dt)
{
    AbstractHUD<LevelBase>::update(dt);

    for (auto& plusMark : m_plussesList)
    {
        plusMark.first += dt;
    }

    m_plussesList.remove_if
    (
        [](const std::pair<float, int>& plusMark)
        {
            return plusMark.first >= PLUS_MARK_DURATION;
        }
    );
}

void Level_HUD::drawIn(DrawerAbstraction& window, LevelBase* level, float dt)
{
    level->drawIn(window, dt);
    m_box.drawIn(window, sf::Vector2f(2,2));

    Menu::Text text("", Menu::FontStyle(m_font, 2 * DEFAULT_FONT_SIZE / 3));

    for (auto& plusMark : m_plussesList)
    {
        float age = plusMark.first + dt;

        if (plusMark.first + dt < PLUS_MARK_DURATION)
        {
            text.setString("+" + std::to_string(plusMark.second));
            text.setColor(plusMarkColor(255 * (PLUS_MARK_DURATION - age) / PLUS_MARK_DURATION));

            sf::FloatRect box(0, 0, m_box.getSize().x - SCORE_BOX_GAPS / 2, m_box.getSize().y - SCORE_BOX_GAPS / 2 - 10 * age);
            text.drawInBox(window, box, Menu::BottomRightCorner);
        }
    }
}

void Level_HUD::increaseScore(int points, bool draw)
{
    if (!points)
    return;

    m_scoreValue += points;
    m_score_ptr->setValue(m_scoreValue);

    if (draw)
    m_plussesList.push_back(std::pair<float, int>(0, points));
}

