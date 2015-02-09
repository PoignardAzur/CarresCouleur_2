

#ifndef HEADER_TABLEAU_VARTS
#define HEADER_TABLEAU_VARTS

#include "AbsVart.h"
#include <list>
#include <memory>


template <typename T = AbsVart>
class VartPusher
{
    public :

    virtual void add(T* vart) = 0;
    virtual ~VartPusher() {}
};


template <typename T = AbsVart>
class VartArray : public std::list<std::shared_ptr<T>>, public VartPusher<T> /// TODO -> move to unique_ptr and debug
{
    public :

    virtual ~VartArray();

    virtual void updateAll(float dt, bool delDeadVarts = true);                           // Updates every Vart of the list
    virtual void drawAllIn(AbstractDrawer& target, sf::FloatRect limits, float dt);       // Draws every Vart of the list
    virtual void add(T* vart);

    virtual void deleteDeadVarts();


    private :

    typedef std::list<std::shared_ptr<T>> lpT;
};


template <typename T>
VartArray<T>::~VartArray()
{

}


template <typename T>
void VartArray<T>::updateAll(float dt, bool delDeadVarts)
{
    for (auto& vart_ptr : *this)
    {
        vart_ptr->update(dt);
    }

    if (delDeadVarts)
    deleteDeadVarts();
    /* we could just call erase(p) in the loop, but it could lead to
    problems should a live Vart need variables from a deleted one */
}


template <typename T>
void VartArray<T>::drawAllIn(AbstractDrawer& target, sf::FloatRect limits, float dt)
{
    for (auto& vart_ptr : *this)
    {
        vart_ptr->drawIn(vart_ptr->getPos(), target, limits, dt);
    }
}


template <typename T>
void VartArray<T>::add(T* vart)
{
    lpT::push_back(std::shared_ptr<T>(vart));
}



template <typename T>
void VartArray<T>::deleteDeadVarts()
{
    lpT::remove_if
    (
        [](const std::shared_ptr<T>& p)
        {
            return p->toDelete();
        }
    );
}


template <typename T>
void updatePositions(VartArray<T>& vl, float dt)
{
    for (auto& vart_ptr : vl)
    {
        vart_ptr->setPos(vart_ptr->getPos() + vart_ptr->getSpeed() * dt);
    }
}



#endif

