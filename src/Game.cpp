#include <Game.hpp>
#include "GenerateRandomNumbers.hpp"

//This is the planet feature


void Game::HandleInput()
{
    // if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    // {
    //     sf::Vector2i p = sf::Mouse::getPosition();
    //     std::cout << p.x << " , " << p.y << std::endl;
    // }
    std::optional<Inputs::MouseClickEv> mouseClick = Inputs::getMouseClick();
    if(mouseClick.has_value())
        std::cout << "Mouse click ev";
    
}

void Game::Update()
{
    m_window.Update();
    world.Update();

}

void Game::Render()
{
    m_window.BeginDraw();
    world.Render(m_window.GetRenderWindow());
    m_window.EndDraw();
}

Window& Game::GetWindow()
{
    return m_window;
}

Game::~Game()
{
    
}