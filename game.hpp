#ifndef GAME_HPP
#define GAME_HPP

#include "pch.hpp"
#include "board.hpp"

class Game
{
private: 

    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event ev;

    void initWindow();
    void settingsInit();
    void pollEvents();
    void initBoard();

    //Settings
    sf::Vector2f jewelSize;

    ///Board
    Board* board;

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