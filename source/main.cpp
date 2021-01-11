#include "game.hpp"

int main()
{
    srand (time(NULL));

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