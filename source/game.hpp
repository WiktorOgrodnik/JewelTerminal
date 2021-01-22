#ifndef GAME_HPP
#define GAME_HPP

#include "pch.hpp"
#include "board.hpp"
#include "engine.hpp"
//#include "settings.hpp"
#include "logika.hpp"
#include "score.h"
#include "label.hpp"
class Game
{
private: 

    sf::RenderWindow* window;
    sf::Event ev;

    //Init functions
    void initVariables();
    void initWindow();
    void initResources();
    void initSettings();
    void initObjects();

    void pollEvents();
    void updateMousePositions();
    void updateAnimations();
    void updateLogic();

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
    int jewelPos2;

    char tab[13][13]; // do usunięcia

    //Settings
    Settings settings;
    Score score;

    //Selected
    Object* selected;
    Object* selectedExtraJewel;
    
    //Animacja
    int animationPhase;
    float animationTime;
    bool animationBlocker;


    //Grafika
    sf::Texture jewelTextures;
    sf::Texture scoreLogo;

public:

    Game();
    ~Game();

    //Getters
    const bool running() const;

    //Loop functions
    void updateDeltaTime();
    void update();
    void render();
    void updateTextures();
};

#endif /*GAME_HPP*/
