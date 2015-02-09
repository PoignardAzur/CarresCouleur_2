


#ifndef META_INTERFACE_HEADER
#define META_INTERFACE_HEADER

#include "AbstractGameInterface.h"
#include <memory>


template <typename In>
class MetaInterface : public AbstractGameInterface<In>
{
    typedef AbstractGameInterface<In> AGIi;

    public :

    MetaInterface(AGIi* newInterface = nullptr);
    void setInterface(AGIi* newInterface);
    ~MetaInterface();

    void drawIn(AbstractDrawer& window, float dt);
    void update(const In& inputData);

    virtual AGIi* next();


    protected :

    AGIi* currentInterface();
    const AGIi* currentInterface() const;


    private :

    std::unique_ptr<AGIi> m_interface;        // has-a
};



template <typename In>
MetaInterface<In>::MetaInterface(AGIi* newInterface)
{
    setInterface(newInterface);
}

template <typename In>
void MetaInterface<In>::setInterface(AGIi* newInterface)
{
    m_interface.reset(newInterface);
}

template <typename In>
MetaInterface<In>::~MetaInterface()
{

}


template <typename In>
void MetaInterface<In>::drawIn(AbstractDrawer& window, float dt)
{
    if (currentInterface())
    currentInterface()->drawIn(window, dt);
}

template <typename In>
void MetaInterface<In>::update(const In& inputData)
{
    if (currentInterface())
    {
        currentInterface()->update(inputData);

        if (currentInterface()->isDone())
        {
            auto p = currentInterface()->next();

            if (p)
            m_interface.reset(p);

            else
            AbstractGameInterface<In>::endThisLater();
        }
    }
}


template <typename In>
AbstractGameInterface<In>* MetaInterface<In>::currentInterface()
{
    return m_interface.get();
}

template <typename In>
const AbstractGameInterface<In>* MetaInterface<In>::currentInterface() const
{
    return m_interface.get();
}


template <typename In>
AbstractGameInterface<In>* MetaInterface<In>::next()
{
    return nullptr;
}


#endif
