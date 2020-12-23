#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
private: 

    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event ev;

    void initWindow();
    void pollEvents();

public:

    Game();
    virtual ~Game();

    ///Getters
    const bool running() const;

    ///Functions
    void update();
    void render();
};

#endif /*GAME_HPP*/