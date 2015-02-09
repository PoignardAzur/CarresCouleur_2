

#include "AnimatedSprite.h"
#include <cmath>


AnimatedSprite::AnimatedSprite()
{

}

AnimatedSprite::AnimatedSprite(const sf::Sprite& sprite, sf::Vector2f center, int nvFrames, int nhFrames, float animFrame, bool loop)
{
    setSprite(sprite, center, nvFrames, nhFrames, animFrame, loop);
}

void AnimatedSprite::setSprite(const sf::Sprite& sprite, sf::Vector2f center, int nvFrames, int nhFrames, float animFrame, bool loop)
{
    set(sprite, center);
    m_nvFrames = nvFrames;
    m_nhFrames = nhFrames;
    m_loopAnim = loop;

    m_animFrameLength = animFrame;
    m_animLength = animFrame * nvFrames * nhFrames;
    m_spriteAge = 0;
}

void AnimatedSprite::update(float dt)
{
    m_spriteAge = newSpriteAge(dt);
}

float AnimatedSprite::newSpriteAge(float dt) const
{
    float spriteAge = m_spriteAge;

    if (m_loopAnim || m_spriteAge <= m_animLength)
    spriteAge += dt;

    if (m_loopAnim)
    spriteAge = fmod(spriteAge, m_animLength);

    return spriteAge;
}

void AnimatedSprite::drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const
{
    sf::Vector2u textureSize = getSprite().getTexture()->getSize(); // the size of the texture
    textureSize.x /= m_nhFrames;    // the size of an individual frame
    textureSize.y /= m_nvFrames;

    float spriteAge = newSpriteAge(dt);
    int frame = spriteAge < m_animFrameLength ? spriteAge / m_animFrameLength : (spriteAge / m_animFrameLength) - 1;

    sf::IntRect textureRect(textureSize.x * (frame % m_nhFrames), textureSize.y * (frame / m_nhFrames), textureSize.x, textureSize.y);
    getSprite().setTextureRect(textureRect);

    SimpleSprite::drawIn(pos, target, limits, dt);
}



