#include "World.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include "GenerateRandomNumbers.hpp"
#include <iostream>
#include <algorithm>

void updateCycle()
{

}

void World::UpdateNumberOfCircles(unsigned int max_nr_of_circles)
{
    while(m_circles.size() < max_nr_of_circles)
    {
        bool exit = false;
        while(exit == false)
        {
            sf::Vector2f position((float)RandomNumbers::generate(0,window_size.x-60), 0.0f);
            float radius = (float)RandomNumbers::generate(10,30);
            float speed = (float)RandomNumbers::generate(1,5);
            // std::cout << "position : " << position.x << " radius : " << radius << std::endl;
            bool circleOk = true;
            for(const auto& circle : m_circles)
            {
                // std::cout << "Check for overflow currentCicle.x = " << circle.getPos().x << " tempCircle.x = " << position.x << std::endl;
                
                if(circle.overflows(temp) == true)
                {
                    circleOk = true;
                    //a
                    //b
                    //c
                    //d
                    std::cout << "Overflow ! \n";
                    float radius_proivate = (float)RandomNumbers::generate(10,30);
                    auto temp = CircleElement();
                    break;
                }
                //e
                //f
            }
            if(circleOk == true)
            {
                m_circles.emplace_back(position, radius, speed);
                std::cout << "Circle added  position.x = " << position.x << " position.y = " << position.y << " radius = "<< radius << std::endl;
                exit = true;
            }
                
        }
    }  
}

void World::MoveCircles()
{
    for(CircleElement& circle : m_circles)
    {
        circle.moveYAxis();
    }
}

void World::cleanCircles()
{
    std::remove_if(m_circles.begin(), m_circles.end(), [&](CircleElement& arg){
        sf::Vector2f p = arg.getPos();
        return window_size.y < p.y;
    });

    // for(auto it = m_circles.begin(); it != m_circles.end(); it++)
    // {
    //     sf::Vector2f currentPos = it->getPosition();
    //     if(currentPos.y >= window_size.y)
    //         it = m_circles.erase(it);
    // }
}

void World::Update()
{
    if(m_circles.size() < MAX_CIRCLES_ON_BOARD)
    {
        UpdateNumberOfCircles(MAX_CIRCLES_ON_BOARD);
    }

    MoveCircles();
    cleanCircles();
}

void World::Render(sf::RenderWindow& window)
{
    
    for(auto& circle : m_circles)
    {
        window.draw(circle);
    }
}