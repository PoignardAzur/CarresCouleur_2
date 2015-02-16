

#include "GameController.hpp"


GameController::GameController(uptrt<InputsAbstraction> userInputs, sf::RenderWindow* target)
{
    m_userInputs = std::move(userInputs);
    m_renderWindow = target;

    if (target)
    m_window.reset(new ObjectDrawer(target));
}


void GameController::update(float dt)
{
    if (m_userInputs)
    m_userInputs->update(dt);

    interface().update(dt);
}

void GameController::display(float dt)
{
    if (!interface().isDone())
    {
        m_window->clear();
        interface().drawIn(*m_window, dt);
        m_renderWindow->display();
    }
}


DrawerAbstraction& GameController::renderingWindow()
{
    return *(m_window.get());
}

InputsAbstraction& GameController::windowInputs()
{
    return *(m_userInputs.get());
}

