
#include "MetaInterface.hpp"


MetaInterface::MetaInterface(AbstractGameInterface* newInterface)
{
    setInterface(newInterface);
}

void MetaInterface::setInterface(AbstractGameInterface* newInterface)
{
    m_interface.reset(newInterface);
}

MetaInterface::~MetaInterface()
{

}


void MetaInterface::drawIn(DrawerAbstraction& window, float dt)
{
    if (currentInterface())
    currentInterface()->drawIn(window, dt);
}

void MetaInterface::update(float dt)
{
    if (currentInterface())
    {
        currentInterface()->update(dt);

        if (currentInterface()->isDone())
        {
            auto p = currentInterface()->next();

            if (p)
            m_interface.reset(p);

            else
            AbstractGameInterface::endThisLater();
        }
    }
}


AbstractGameInterface* MetaInterface::currentInterface()
{
    return m_interface.get();
}

const AbstractGameInterface* MetaInterface::currentInterface() const
{
    return m_interface.get();
}

AbstractGameInterface* MetaInterface::next()
{
    return nullptr;
}

