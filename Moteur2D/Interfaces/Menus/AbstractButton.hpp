

#ifndef ABSTRACT_MENU_BUTTON_HEADER
#define ABSTRACT_MENU_BUTTON_HEADER


namespace Menu
{

    class AbstractButton
    {
        public :

        //virtual bool isGrayed() { return false; }

        virtual void select() = 0;
        virtual void deselect() = 0;
        virtual void press() = 0;

        virtual void left(bool big = false) { big+=0; }    // those four commands are useful for sub_menus and slides
        virtual void right(bool big = false) { big+=0; }   // by default, they do nothing
        virtual void up(bool big = false) { big+=0; }
        virtual void down(bool big = false) { big+=0; }

        virtual ~AbstractButton() {}
    };

}


#endif // MENU_BUTTON_HEADER
