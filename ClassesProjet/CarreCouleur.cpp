

#include "CarreCouleur.h"


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

void CarreCouleur::update(float dt)
{
    if (m_age < 1)
    m_age += dt;
}

void CarreCouleur::drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const
{
    (void) limits;

    sf::RectangleShape rect(sf::Vector2f(m_size, m_size));
    rect.setPosition(pos + getSpeed() * dt - sf::Vector2f(m_size/2, m_size/2));

    rect.setFillColor(m_color);
    target.draw(rect);
}

sf::Vector2f CarreCouleur::getPos() const
{
    return SimpleHitbox::getPos();
}

bool CarreCouleur::recycle(sf::FloatRect limits, bool deleteIfOOB)
{
    m_toDelete = m_age > 1 && (getHitbox(getPos()).intersects(limits) xor deleteIfOOB);
    return m_toDelete;
}

