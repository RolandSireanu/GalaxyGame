#include "Benchmark.hpp"

namespace Benchmark
{
    sf::Clock clock;

    void start_measurement()
    {
        clock.restart();   
    }

    sf::Int32 stop_measurement()
    {
        sf::Time elapsed = clock.getElapsedTime();
        return elapsed.asMilliseconds();
    }

};