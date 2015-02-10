

#ifndef ANIMATED_SPRITE_HEADER
#define ANIMATED_SPRITE_HEADER

#include "SimpleSprite.h"
#include <memory>

#define DEFAULT_ANIM_FRAME_LENGTH 0.2f


class AnimatedSprite : public SimpleSprite
{
    public :

    AnimatedSprite();
    AnimatedSprite(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT, int nvFrames = 1, int nhFrames = 1, float animFrame = DEFAULT_ANIM_FRAME_LENGTH, bool loop = false);
    void setSprite(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT, int nvFrames = 1, int nhFrames = 1, float animFrame = DEFAULT_ANIM_FRAME_LENGTH, bool loop = false);

    void update(float dt);
    virtual float newSpriteAge(float dt) const;     // returns the new value m_spriteAge would have after dt ticks, taking into account the value of m_loopAnim

    virtual void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const;


    private :

    int m_nvFrames;
    int m_nhFrames;
    bool m_loopAnim;                // if true, once done, the animation restarts from the beginning

    float m_animFrameLength;
    float m_animLength;             // stores the total length of the animation
    float m_spriteAge;              // stores how many ticks passed since the animation started
};


#endif // SIMPLE_SPRITE_HEADER
