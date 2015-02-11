

#ifndef PLACED_VART_HEADER
#define PLACED_VART_HEADER

#include "AbsVart.hpp"
#include <up.hpp>


template <typename V>
class Fixed
{
    public :

    Fixed(up_t<V> vart);
    Fixed(Fixed&& other);
    virtual ~Fixed() = default;

    virtual sf::Vector2f getPos() const = 0;
//    virtual void updatePos(float dt) = 0;
    V& get();
    const V& get() const;


    private :

    up_t<V> m_vart;
};


template <typename V>
class Placed : public Fixed<V>
{
    public :

    Placed(up_t<V> vart, sf::Vector2f n_pos);
    Placed(Placed&& other);

    sf::Vector2f getPos() const;
    void setPos(sf::Vector2f p);
//    virtual void updatePos(float dt) = 0;

    sf::Vector2f pos;
};


template <typename V>
Fixed<V>::Fixed(up_t<V> vart)
{
    m_vart = mv(vart);
}

template <typename V>
Fixed<V>::Fixed(Fixed&& other)
{
    m_vart = mv(other.m_vart);
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
Placed<V>::Placed(up_t<V> n_v, sf::Vector2f n_pos) : Fixed<V>(mv(n_v))
{
    setPos(n_pos);
}

template <typename V>
Placed<V>::Placed(Placed<V>&& other) : Fixed<V>(mv(other))
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


#endif
