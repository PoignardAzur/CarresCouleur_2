
#ifndef META_INTERFACE_HEADER
#define META_INTERFACE_HEADER

#include "AbstractGameInterface.hpp"
#include <memory>


class MetaInterface : public AbstractGameInterface
{
    public :

    MetaInterface(AbstractGameInterface* newInterface = nullptr);
    void setInterface(AbstractGameInterface* newInterface);
    ~MetaInterface();

    void drawIn(DrawerAbstraction& window, float dt);
    void update(float dt);

    virtual AbstractGameInterface* next();


    protected :

    AbstractGameInterface* currentInterface();
    const AbstractGameInterface* currentInterface() const;


    private :

    std::unique_ptr<AbstractGameInterface> m_interface;        // has-a
};


#endif
