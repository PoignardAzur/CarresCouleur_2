
#include "StartEndBool.hpp"


StartEnd::StartEnd(bool nValue, Event f) : m_value(nValue), m_lastValue(nValue)
{
    setFunction(f);
}

void StartEnd::setFunction(Event f)
{
    m_function = f;
}

inline bool StartEnd::value()
{
    return m_value;
}

inline bool StartEnd::started()
{
    return m_value && (!m_lastValue);
}

inline bool StartEnd::ended()
{
    return (!m_value) && (!m_lastValue);
}

inline bool StartEnd::changed()
{
    return m_value != m_lastValue;
}

bool StartEnd::update(bool nValue)
{
    if (nValue != m_lastValue)
    m_function(nValue);

    m_lastValue = m_value;
    m_value = nValue;

    return started();
}

