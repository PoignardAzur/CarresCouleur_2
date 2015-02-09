
#include "ClassesProjet/BossClass.h"
#include <iostream>

#define WINDOW_TITLE "Carres couleur 2 : le retour de la vengeance"


inline int catchError(const char* e)
{
    std::cerr << "ERROR : " << e << std::endl;
    return EXIT_FAILURE;
}

int main(int argc, char** argv)
{
    try
    {
        sf::RenderWindow* fenetre = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

        fenetre->setFramerateLimit(30);
        BossClass bigBrother(new Inputs(fenetre, false), fenetre);
        sf::Clock chronos;
        chronos.restart();

        while (!bigBrother.isDone())
        {
            bigBrother.update(chronos.restart().asSeconds());
            fenetre->display();
        }

        fenetre->close();

        return EXIT_SUCCESS;
    }

    catch (std::string const& e)
    {
        return catchError(e.c_str());
    }

    catch (const char* e)
    {
        return catchError(e);
    }

    catch (std::exception const& e)
    {
        return catchError(e.what());
    }

    catch (...)
    {
        return catchError("Non specified error occured");
    }

}

