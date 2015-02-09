// Summary of the most important classes of the engine, do not compile

class SimpleHitbox
{
    SimpleHitbox(sf::FloatRect box = NULL_RECT, sf::Vector2f pos = NULL_PT, sf::Vector2f speed = NULL_PT);
    void setHitbox(sf::FloatRect internBox);
    void set(const SimpleHitbox&);

    sf::FloatRect getHitbox(sf::Vector2f center = NULL_PT) const;     // get the placed hitbox of the object
    void setSpeed(sf::Vector2f speed, bool relative = false);
    sf::Vector2f getSpeed() const;
};

class SimpleVart : public SimpleHitbox
{
    SimpleVart(const SimpleHitbox& hitbox, AbstractDrawable* sprite = nullptr);
    virtual void update(float dt);
    virtual bool doDelete() const;
    virtual void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const;

    protected :
    std::unique_ptr<AbstractDrawable> setSprite(AbstractDrawable* sprite);
    virtual void removeThis();
};


template <typename T>
class VartArray : public std::list<std::unique_ptr<T>>
{
    virtual void updateAll(float dt, bool delDeadVarts = true);                           // Updates every Vart of the list
    virtual void drawAllIn(AbstractDrawer& target, sf::FloatRect limits, float dt);       // Draws every Vart of the list

    virtual void add(T* vart);
    virtual void deleteDeadVarts();
};


class ObjectDrawer : public AbstractDrawer
{
    ObjectDrawer(sf::RenderTarget* cible);
    virtual void draw(const sf::Drawable& o);
    virtual void clear(); // reset the screen

    protected :
    sf::RenderTarget& target();
};


class SimpleSprite : public AbstractDrawable
{
    SimpleSprite(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT);
    virtual void set(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT);
    virtual void drawIn(sf::Vector2f pos, AbstractDrawer& target, sf::FloatRect limits, float dt) const;

    protected :
    sf::Sprite& getSprite() const;
};

class AnimatedSprite : public SimpleSprite
{
    void setSprite(const sf::Sprite& sprite, sf::Vector2f center = NULL_PT, int nvFrames = 1, int nhFrames = 1, float animFrame = DEFAULT_ANIM_FRAME_LENGTH, bool loop = false);
    void update(float dt);
};


template <typename In>
class AbstractGameInterface
{
    virtual void drawIn(AbstractDrawer& window, float dt) = 0;
    virtual void setUserInputs(AbstractInputs*);
    virtual void update(const In& inputData) = 0;       // by default, 'In' is the number of ticks since the last update
    virtual bool isDone() const;                        // if this returns true, the interface must be deleted and replaced by
    virtual AbstractGameInterface<In>* next() = 0;      // the next interface

    protected :
    virtual void endThisLater();
    virtual AbstractInputs* getInputs();
    virtual const AbstractInputs* getInputs() const;
};


