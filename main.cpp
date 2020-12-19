#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{
    //Window
    sf::RenderWindow gameWindow(sf::VideoMode(640, 480), "Jewel", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    //Game loop
    while (gameWindow.isOpen())
    {
        //Event pooling
        while(gameWindow.pollEvent(ev))
        {
            switch (ev.type)
            {
                case sf::Event::Closed:
                    gameWindow.close();
                    break;
                case sf::Event::KeyPressed:
                    if (ev.key.code == sf::Keyboard::Escape) 
                        gameWindow.close();
                    break;
            }
        }

        //Update

        //Render
        gameWindow.clear();
        gameWindow.display();
    }

    return 0;
}