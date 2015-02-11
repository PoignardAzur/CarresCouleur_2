

#include "CarreCouleur.hpp"


CarreCouleur::CarreCouleur(sf::Color color, float sizeCarre)
{
    m_color = color;
    m_size = sizeCarre;

    setHitbox(sf::FloatRect(-m_size / 2, -m_size / 2, m_size, m_size));
}

CarreCouleur::CarreCouleur(std_rng& rng, float sizeCarre)
{
    int_dice c(0, 255);
    m_color = sf::Color(c(rng), c(rng), c(rng));
    m_size = sizeCarre;

    setHitbox(sf::FloatRect(-m_size / 2, -m_size / 2, m_size, m_size));
}

void CarreCouleur::randomizeSpeed(std_rng& rng)
{
    float_dice v(-DEFAULT_CARRE_SPEED, DEFAULT_CARRE_SPEED);
    setSpeed( sf::Vector2f(v(rng), v(rng)) );
}

bool CarreCouleur::toDelete() const
{
    return m_toDelete;
}

void CarreCouleur::update(const sf::Vector2f& pos, float dt)
{
    (void) pos;

    if (m_age < 1)
    m_age += dt;
}

void CarreCouleur::updatePos(sf::Vector2f& pos, float dt)
{
    pos += getSpeed() * dt;
}

void CarreCouleur::drawIn(sf::Vector2f pos, DrawerAbstraction& target, sf::FloatRect limits, float dt) const
{
    (void) limits;

    sf::RectangleShape rect(sf::Vector2f(m_size, m_size));
    rect.setPosition(pos + getSpeed() * dt - sf::Vector2f(m_size/2, m_size/2));

    rect.setFillColor(m_color);
    target.draw(rect);
}

bool CarreCouleur::recycle(sf::Vector2f pos, sf::FloatRect limits, bool deleteIfOOB)
{
    m_toDelete = m_age > 1 && (getHitbox(pos).intersects(limits) xor deleteIfOOB);
    return m_toDelete;
}

