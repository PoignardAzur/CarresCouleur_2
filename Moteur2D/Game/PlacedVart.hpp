
#ifndef PLACED_VART_HEADER
#define PLACED_VART_HEADER

#include "VartAbs.hpp"
#include <up.hpp>


// This abstraction allows to modify a Vart without modifying its position
template <typename V>
class Fixed
{
    public :

    Fixed(uptrt<V> vart);
    Fixed(Fixed&& other);
    virtual ~Fixed() = default;

    virtual sf::Vector2f getPos() const = 0;
    virtual void updatePos(float dt) = 0;

    V& get();
    const V& get() const;


    private :

    uptrt<V> m_vart;
};


// This class represents the set of a Vart (V) and its position
template <typename V>
class Placed : public Fixed<V>
{
    public :

    Placed(uptrt<V> vart, sf::Vector2f n_pos);
    Placed(Placed&& other);

    sf::Vector2f getPos() const;
    void setPos(sf::Vector2f p);
    void updatePos(float dt);

    sf::Vector2f pos;
};


template <typename V>
Fixed<V>::Fixed(uptrt<V> vart)
{
    m_vart = move(vart);
}

template <typename V>
Fixed<V>::Fixed(Fixed&& other)
{
    m_vart = move(other.m_vart);
}

template <typename V>
V& Fixed<V>::get()
{
    return *(m_vart.get());
}

template <typename V>
const V& Fixed<V>::get() const
{
    return *(m_vart.get());
}


template <typename V>
Placed<V>::Placed(uptrt<V> n_v, sf::Vector2f n_pos) : Fixed<V>(move(n_v))
{
    setPos(n_pos);
}

template <typename V>
Placed<V>::Placed(Placed<V>&& other) : Fixed<V>(move(other))
{
    setPos(other.pos);
}

template <typename V>
sf::Vector2f Placed<V>::getPos() const
{
    return pos;
}

template <typename V>
void Placed<V>::setPos(sf::Vector2f p)
{
    pos = p;
}

template <typename V>
void Placed<V>::updatePos(float dt)
{
    Fixed<V>::get().updatePos(pos, dt);
}


#endif // PLACED_VART_HEADER
