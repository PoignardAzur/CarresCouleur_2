

#ifndef HEADER_TABLEAU_VARTS
#define HEADER_TABLEAU_VARTS

#include "PlacedVart.hpp"
#include <list>


template <typename V = AbsVart>
using VartList = std::list<Placed<V>>;

template <typename V>
void updateAll(VartList<V>& list, float dt, bool delDeadVarts = true, bool updatePos = false)
{
    if (updatePos)
    updateAllPositions(list, dt);

    for (auto& placedVart : list)
    {
        placedVart.get().update(placedVart.getPos(), dt);
    }

    if (delDeadVarts)
    deleteDeadVarts(list);
    /* we could just call erase(p) in the loop, but it could lead to
    problems should a live Vart need variables from a deleted one */
}


template <typename V>
void drawAllIn(VartList<V>& list, AbstractDrawer& target, sf::FloatRect limits, float dt)
{
    for (auto& placedVart : list)
    {
        placedVart.get().drawIn(placedVart.getPos(), target, limits, dt);
    }
}


template <typename V>
void deleteDeadVarts(VartList<V>& list)
{
    list.remove_if
    (
        [](const Placed<V>& placedVart)
        {
            return placedVart.get().toDelete();
        }
    );
}


template <typename V>
void updateAllPositions(VartList<V>& list, float dt)
{
    for (auto& placedVart : list)
    {
        placedVart.get().updatePos(placedVart.pos, dt);
    }
}


template <typename V = AbsVart>
class VartPusher
{
    public :

    VartPusher(VartList<V>* list);
    virtual ~VartPusher();
    void add(up_t<V> vart, sf::Vector2f pos);


    private :

    VartList<V>* m_list;    // use-a
};

template <typename V>
VartPusher<V>::VartPusher(VartList<V>* list)
{
    m_list = list;
}

template <typename V>
VartPusher<V>::~VartPusher()
{

}

template <typename V>
void VartPusher<V>::add(up_t<V> vart, sf::Vector2f pos)
{
    m_list->push_back(Placed<V>(mv(vart), pos));
}


#endif

