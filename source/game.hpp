/*
This is the most important class in the all game. It contains init functions to initialize all important variables and resources,
it also ordes to render objects and updates the game state. This class also contains functions which is used to draw and manage drawable objects.
*/

#pragma once

#include "board.hpp"
#include "layer.hpp"
#include "settings.hpp"
#include "logika.hpp"
#include "score.h"
#include "label.hpp"

class Game
{
private: 

    //Game window
    sf::RenderWindow* window;

    //Input event
    sf::Event ev;

    //Init functions
    void initVariables();
    void initWindow();
    void initResources();
    void initObjects();

    //Update functions
    void pollEvents();
    void updateMousePositions();
    void updateAnimations();
    void updateLogic();

    //Engine functions
    //Add objects
    void addObject(bool topPririty, Object* newObject);
    void addObject(unsigned layer, Object* newObject);
    void addTopLayer();
    //void addToTheSameLayerAs(std::vector<Layer*>* layers, Object* newObject, Object* existingObject); 

    //Move objects
    void moveTo(Object* object, sf::Vector2f position);

    //Give selectable
    Object* giveSelectable();

    //Delete objects
    //void delteObject(Object* object);
    void deleteUnnecessary();

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

    //Mouse control
    int moveDirectionCheck; //TO-DO switch to int
    bool moveAxis; // 0 - horizontal, 1 - vertical
    int jewelPos;
    int jewelPos2;

    //Score
    unsigned score;

    //The board
    char tab[13][13]; // to delete

    //Settings
    Settings settings;
    //Score score;

    //Selected
    Object* hover;
    Object* selected;
    Object* selectedExtraJewel;
    
    //Animations
    int animationPhase;
    float animationTime;
    bool animationBlocker;

    //Textures
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
};