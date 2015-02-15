
#include "ClassesProjet/BossClass.hpp"
#include <iostream>

#define WINDOW_TITLE "Carres couleur 2 : le retour de la vengeance"


inline int catchError(const char* e)
{
    std::cerr << "ERROR : " << e << std::endl;
    return EXIT_FAILURE;
}

int main(int /*argc*/, char** /*argv*/)
{
    try
    {
        up_t<sf::RenderWindow> fenetre(new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE));

        fenetre->setFramerateLimit(30);
        BossClass bigBrother(up(new Inputs(fenetre.get(), false)), fenetre.get());
        sf::Clock chronos;
        chronos.restart();

        const float min_dt = 1.0f/60.0f;    // those are the bounds of the dt value passed in all functions "update(float dt)"
        const float max_dt = 0.1f;
        float accumulatedTime = 0.0;        // represents the advance the renderer has over the engine

        while (!bigBrother.isDone())
        {
            accumulatedTime += chronos.restart().asSeconds();

            if (accumulatedTime > 1)  // this lines prevents the engine from falling in a spiral of death (not catching up to the renderer)
            accumulatedTime = 1;

            // The way is work is : the (real) world produces time that the engine consumes in dt-sized chunks
            while (accumulatedTime >= min_dt && !bigBrother.isDone())
            {
                float dt = max_dt < accumulatedTime ? max_dt : accumulatedTime;

                bigBrother.update(dt);
                accumulatedTime -= dt;
            }

            if (!bigBrother.isDone())
            bigBrother.display(accumulatedTime);

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
        return catchError("Non specified error occurred");
    }

}

