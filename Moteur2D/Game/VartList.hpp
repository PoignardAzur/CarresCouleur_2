
#ifndef VART_LIST_HEADER
#define VART_LIST_HEADER

#include "PlacedVart.hpp"
#include <list>


template <typename V = VartAbs>
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
    /* we could just call erase(p) in the loop, but it could lead to problems
    should a live Vart need variables from a deleted one during its update */
}


template <typename V>
void drawAllIn(const VartList<V>& list, DrawerAbstraction& target, sf::FloatRect limits, float dt)
{
    for (const auto& placedVart : list)
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
        placedVart.updatePos(dt);
    }
}


template <typename V>
void updateAllPositions(VartList<V>& list, sf::FloatRect zone, bool deleteIfOut = true)
{
    for (auto& placedVart : list)
    {
        placedVart.get().recycle(placedVart.getPos(), zone, deleteIfOut);
    }
}


// This class is useful for letting a class add Varts to a list, but not modify the list
// POINTER SAFETY : 'add()' must not be called after 'm_list' is deleted
template <typename V = VartAbs>
class VartPusher
{
    public :

    explicit VartPusher(VartList<V>* list);
    virtual ~VartPusher();
    void add(uptrt<V> vart, sf::Vector2f pos);


    private :

    VartList<V>* m_list; // use-a
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
void VartPusher<V>::add(uptrt<V> vart, sf::Vector2f pos)
{
    m_list->push_back(Placed<V>(move(vart), pos));
}


#endif // VART_LIST_HEADER
