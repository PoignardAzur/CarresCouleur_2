

#ifndef HEADER_TABLEAU_VARTS
#define HEADER_TABLEAU_VARTS

#include "AbsVart.hpp"
#include <list>
#include "up.hpp"


template <typename T = AbsVart>
using VartList = std::list<up_t<T>>;

template <typename T>
void updateAll(VartList<T>& list, float dt, bool delDeadVarts = true)
{
    for (auto& vart_ptr : list)
    {
        vart_ptr->update(dt);
    }

    if (delDeadVarts)
    deleteDeadVarts(list);
    /* we could just call erase(p) in the loop, but it could lead to
    problems should a live Vart need variables from a deleted one */
}


template <typename T>
void drawAllIn(VartList<T>& list, AbstractDrawer& target, sf::FloatRect limits, float dt)
{
    for (auto& vart_ptr : list)
    {
        vart_ptr->drawIn(vart_ptr->getPos(), target, limits, dt);
    }
}


template <typename T>
void deleteDeadVarts(VartList<T>& list)
{
    list.remove_if
    (
        [](const up_t<T>& p)
        {
            return p->toDelete();
        }
    );
}


template <typename T>
void updatePositions(VartList<T>& list, float dt)
{
    for (auto& vart_ptr : list)
    {
        vart_ptr->setPos(vart_ptr->getPos() + vart_ptr->getSpeed() * dt);
    }
}


template <typename T = AbsVart>
class VartPusher
{
    public :

    VartPusher(VartList<T>* list);
    virtual ~VartPusher();
    void add(up_t<T>* vart);


    private :

    VartList<T>* m_list;    // use-a
};

template <typename T>
VartPusher<T>::VartPusher(VartList<T>* list)
{
    m_list = list;
}

template <typename T>
VartPusher<T>::~VartPusher()
{

}

template <typename T>
void VartPusher<T>::add(up_t<T>* vart)
{
    m_list->push_back(mv(vart));
}


#endif

