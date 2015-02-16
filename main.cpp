
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
        uptrt<sf::RenderWindow> fenetre(new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE));
        fenetre->setFramerateLimit(30);

        BossClass bigBrother(uptr(new Inputs(fenetre.get(), false)), fenetre.get());

        const float MIN_DT = 1.0f/60.0f;        // those are the bounds of the dt value passed in all functions "update(float dt)"
        const float MAX_DT = 0.1f;
        const float MAX_ACC = 1.0f;

        sf::Clock chronos;
        float accumulatedTime = MIN_DT;         // represents the advance the renderer has over the engine

        while (!bigBrother.isDone())
        {
            accumulatedTime += chronos.restart().asSeconds();

            if (accumulatedTime > MAX_ACC)      // these lines prevent the engine from falling in a spiral of death
            accumulatedTime = MAX_ACC;          // (not catching up to the renderer)

            // The way is work is : the (real) world produces time that the engine consumes in dt-sized chunks
            while (accumulatedTime >= MIN_DT && !bigBrother.isDone())
            {
                float dt = std::min(accumulatedTime, MAX_DT);

                bigBrother.update(dt);
                accumulatedTime -= dt;
            }

            if (!bigBrother.isDone())
            bigBrother.display(accumulatedTime);
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

