#ifndef GAME_HPP
#define GAME_HPP

#include "pch.hpp"
#include "board.hpp"
#include "engine.hpp"
#include "settings.hpp"

class Game
{
private: 

    sf::RenderWindow* window;
    sf::Event ev;

    //Init functions
    void initVariables();
    void initWindow();
    void initSettings();
    void initObjects();

    void pollEvents();
    void updateMousePositions();

    //Delta time
    sf::Clock deltaTimeClock;
    float deltaTime;

    //Objects
    std::vector <Layer*> layers;
    std::vector <Jewel*> jewels;

    ///Mouse Positions
    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePositionView;
    sf::Vector2f mousePositionDelta;
    sf::Vector2f mousePositionDeltaCheckDirecton;

    bool moveDirectionCheck;
    bool moveAxis; // 0 - horizontal, 1 - vertical
    int jewelPos;

    //Settings
    Settings settings;

    //Selected
    Object* selected;
    Object* selectedExtraJewel;

public:

    Game();
    ~Game();

    //Getters
    const bool running() const;

    //Loop functions
    void updateDeltaTime();
    void update();
    void render();
};

#endif /*GAME_HPP*/