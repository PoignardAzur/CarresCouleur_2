

#include "GameController.h"


GameController::GameController(AbstractInputs* userInputs, sf::RenderWindow* target)
{
    m_userInputs.reset(userInputs);
    m_renderWindow = target;

    if (target)
    m_window.reset(new ObjectDrawer(target));
}


void GameController::update(float dt)
{
    if (m_window)
    m_window->clear();

    interface()->update(dt);

    if (m_window && !interface()->isDone())
    interface()->drawIn(*m_window, dt);

    if (m_userInputs)
    m_userInputs->update();
}


AbstractDrawer* GameController::renderingWindow()
{
    return m_window.get();
}

AbstractInputs* GameController::windowInputs()
{
    return m_userInputs.get();
}

