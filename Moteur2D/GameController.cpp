

#include "GameController.hpp"


GameController::GameController(up_t<InputsAbstraction> userInputs, sf::RenderWindow* target)
{
    m_userInputs = std::move(userInputs);
    m_renderWindow = target;

    if (target)
    m_window.reset(new ObjectDrawer(target));
}


void GameController::update(float dt)
{
    if (m_userInputs)
    m_userInputs->update();

    interface().update(dt);
}

void GameController::display(float dt)
{
    m_window->clear();

    if (!interface().isDone())
    interface().drawIn(*m_window, dt);
}


DrawerAbstraction& GameController::renderingWindow()
{
    return *(m_window.get());
}

InputsAbstraction& GameController::windowInputs()
{
    return *(m_userInputs.get());
}

