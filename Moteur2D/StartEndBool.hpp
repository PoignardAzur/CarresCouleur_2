
#ifndef START_END_BOOL_HEADER
#define START_END_BOOL_HEADER

#include <functional>


// The value is considered "started" when it's just become positive, "ended" when it's just become negative, changed in both cases.
class StartEnd
{
    public :

    using Event = std::function<void(bool)>;

    explicit StartEnd(bool nValue = false, Event f = Event());
    void setFunction(Event f);

    bool value();
    bool started();
    bool ended();
    bool changed();

    bool update(bool nValue);   // returns the same thing as the started() method


    private :

    bool m_value;
    bool m_lastValue;

    Event m_function;
};


#endif // START_END_BOOL_HEADER
