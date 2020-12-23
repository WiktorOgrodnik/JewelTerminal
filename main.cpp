#include <iostream>
#include "game.hpp"

int main()
{
    Game game;   

    //Game loop
    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}