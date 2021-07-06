#include "Game.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>
#include <memory>
#include <SFML/System.hpp>
#include <Inputs.hpp>
#ifdef EnableTests
    #include<gtest/gtest.h>
#endif
using namespace std;

int main(int ac, char** av)
{
    #ifdef EnableTests
        testing::InitGoogleTest(&ac, av);
        return RUN_ALL_TESTS();
    #else

        Game game;
        sf::Clock clock;

        while(game.GetWindow().IsDone() == false)
        {
            clock.restart();    
            game.HandleInput();

            sf::Time elapsed = clock.getElapsedTime();
            cout << " Duration HandleInput : " << elapsed.asMilliseconds() << "us\n";
            clock.restart();

            game.Update();
            elapsed = clock.getElapsedTime();
            cout << " Duration Update : " << elapsed.asMilliseconds() << "us\n";
            clock.restart();

            game.Render();
            elapsed = clock.getElapsedTime();
            cout << " Duration Render : " << elapsed.asMilliseconds() << "us\n";

        }
    #endif

    return 0;
}
