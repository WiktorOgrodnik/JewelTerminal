/**
 * @file main.cpp
 * @author Wiktor Ogrodnik, Jakub Janiszek, Mikołaj Hasik, Konrad Woźniak, Mikołaj Balwicki
 * @brief Open-source puzzle game written in C++ with SFML library. This is our final version for semester project.
 * @version 1.0
 * @date 2021-01-24
 * 
 * @copyright Copyright (c) Wiktor Ogrodnik, Jakub Janiszek, Mikołaj Hasik, Konrad Woźniak, Mikołaj Balwicki 2021
 * 
 */

#include "game.hpp"

int main()
{
    srand(time(NULL));

    Game game; 

    //Game loop
    while (game.running())
    {
        game.updateDeltaTime();
        game.update();
        game.render();
    }

    return 0;
}
