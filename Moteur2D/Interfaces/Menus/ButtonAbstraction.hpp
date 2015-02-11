
#ifndef MENU_BUTTON_ABSTRACTION_HEADER
#define MENU_BUTTON_ABSTRACTION_HEADER


namespace Menu
{

    class ButtonAbstraction
    {
        public :

        //virtual bool isGrayed() { return false; }

        virtual void select() = 0;
        virtual void deselect() = 0;
        virtual void press() = 0;

        virtual void left(bool big = false)     { (void) big; }     // those four commands are useful for sub_menus and slides
        virtual void right(bool big = false)    { (void) big; }     // by default, they do nothing
        virtual void up(bool big = false)       { (void) big; }
        virtual void down(bool big = false)     { (void) big; }

        virtual ~ButtonAbstraction() = default;
    };

}


#endif // MENU_BUTTON_ABSTRACTION_HEADER
