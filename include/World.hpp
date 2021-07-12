#ifndef WORLD_H
#define WORLD_H
#include "CircleElement.hpp"
#include <SFML/System.hpp>
#include <vector>

class World
{
    public:
        World(sf::Vector2u arg_window_size) : window_size{arg_window_size}
        {
            m_circles.reserve(16);
        }

        void Update();
        void Render(sf::RenderWindow& window);

    private:
    
        std::vector<CircleElement> m_circles;
        const unsigned int MAX_CIRCLES_ON_BOARD = 4;
        const sf::Vector2u window_size;

        void UpdateNumberOfCircles(unsigned int max_nr_of_circles);
        void MoveCircles();
        void cleanCircles();
        
        
};

#endif