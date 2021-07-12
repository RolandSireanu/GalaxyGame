#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "CircleElement.hpp"
#include <optional>
#include "Inputs.hpp"
#include <vector>
#include "World.hpp"

class Game
{
    public:
        Game() : m_window("Game window", {800, 600}) , world(sf::Vector2u(800,600))
        {
            
        }
        ~Game();
        void HandleInput();
        void Update();
        void Render();
        
        Window& GetWindow();
    private:
        Window m_window;
        World world;

};


#endif