#include <Inputs.hpp>
#include <vector>
#include <thread>
#include <queue>
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace Inputs
{
    sf::Clock clock;
    std::optional<Inputs::MouseClickEv> getMouseClick()
    {
        MouseClickEv tempEv;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {            
            sf::Vector2i p = sf::Mouse::getPosition();
            tempEv.x = p.x;
            tempEv.y = p.y;
            tempEv.leftClick = true;  
            return std::optional<Inputs::MouseClickEv>{tempEv};
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            sf::Vector2i p = sf::Mouse::getPosition();
            tempEv.x = p.x;
            tempEv.y = p.y;
            tempEv.leftClick = false;                    
            return std::optional<Inputs::MouseClickEv>{tempEv};  
        }
        else {}

        return std::optional<Inputs::MouseClickEv>{};

    }

};