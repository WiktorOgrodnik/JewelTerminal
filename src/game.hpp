/*
This is the most important class in the all game. It contains init functions to initialize all important variables and resources,
it also ordes to render objects and updates the game state. This class also contains functions which is used to draw and manage drawable objects.
*/

#pragma once

#include "layer.hpp"
#include "settings.hpp"
#include "logic.hpp"
#include "resources.hpp"

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
    void initObjects();

    //Update functions
    void pollEvents();
    void updateMousePositions();
    void updateAnimations();
    void updateLogic();

    //Engine functions
    //Add objects
    void addObject(bool topPririty, sf::Drawable* newObject);
    void addObject(unsigned layer, sf::Drawable* newObject);
    void addTopLayer();
    //void addToTheSameLayerAs(std::vector<Layer*>* layers, Object* newObject, Object* existingObject); 

    //Give selectable
    Selectable* giveSelectable();

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
    int moveDirectionCheck;
    bool moveAxis; // 0 - horizontal, 1 - vertical
    int jewelPos;
    int jewelPos2;

    //Score
    unsigned score;
    sf::Text* scoreLabel;

    //Settings
    Settings settings;

    //Resources
    Resources resources;

    //Selected
    Selectable* hover;
    Selectable* selected;
    Jewel* selectedExtraJewel;
    
    //Animations
    int animationPhase;
    float animationTime;
    bool animationBlocker;
    
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