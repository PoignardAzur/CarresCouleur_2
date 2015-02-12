

/*
The value is considered "started" when it's just become positive, "ended" when it's just become negative, changed in both cases.
*/



class StartEnd
{
    public :

    StartEnd(bool nValue = false);

    bool value();
    bool started();
    bool ended();
    bool changed();

    bool update(bool nValue);
    bool operator()(bool nValue);


    private :

    bool m_value;
    bool m_lastValue;
};

