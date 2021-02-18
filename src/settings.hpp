/*
This class store important game constants.
*/

#pragma once

#include "pch.hpp"

class Settings
{
    //Game Settings

    //Jewel
    sf::Vector2f jewelSize;
    float switchTime;

    //Board
    unsigned boardSize;
    sf::Vector2f boardMargin;
    float boardInnerPadding;
    float boardLineThickness;
    sf::Vector2f boardSizePixels;
    sf::Vector2f boardPosition;

    //Score texture
    sf::Vector2f scoreImagePosition;

    //Score text
    sf::Vector2f scoreTextPosition;
    unsigned scoreTextFontSize;

    //Engine Settings  
    sf::VideoMode videoMode;
    bool verticalSync;
    int FPSLimit;

    //Animations
    float fallingAnimationSpeed;

    //Mouse control
    int moveAxisCheckTime;
    sf::Vector2f moveAxisCheckMargin;

public:

    Settings();

    //Game settings getters

    //Jewel gettrs
    sf::Vector2f getJewelSize();
    float getSwitchTime();

    //Board getters
    unsigned getBoardSize();
    sf::Vector2f getBoardMargin();
    float getBoardInnerPadding();
    float getBoardLineThickness();
    sf::Vector2f getBoardSizePixels();
    sf::Vector2f getBoardPosition();

    //Score image getters
    sf::Vector2f getScoreImagePosition();

    //Score text getters
    sf::Vector2f getScoreTextPosition();
    unsigned getScoreTextFontSize();

    //Engine settings getters
    sf::VideoMode getVideoMode();
    bool getVerticalSyncSetting();
    int getMaxFPS();

    //Animation settings getters
    float getFallingAnimationSpeed();

    //Mouse control getters
    int getMoveAxisCheckTime();
    sf::Vector2f getMoveAxisCheckMargin();
};