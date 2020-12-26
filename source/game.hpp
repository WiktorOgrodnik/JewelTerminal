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

    //Init functions
    void initVariables();
    void initWindow();
    void initSettings();
    void initBoard();

    void pollEvents();

    //Settings
    sf::Vector2f jewelSize;

    //Board
    Board* board;

public:

    Game();
    ~Game();

    //Getters
    const bool running() const;

    //Functions
    void update();
    void render();
};

#endif /*GAME_HPP*/