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

    //Engine Settings
    sf::VideoMode videoMode;
    bool verticalSync;
    int FPSLimit;

    //Mouse control
    int moveAxisCheckTime;
    sf::Vector2f moveAxisCheckMargin;

public:

    Settings();

    //Game settings getters

    //Jewel
    sf::Vector2f getJewelSize();
    float getSwitchTime();

    //Board
    unsigned getBoardSize();
    sf::Vector2f getBoardMargin();
    float getBoardInnerPadding();
    float getBoardLineThickness();

    //Engine settings getters
    sf::VideoMode getVideoMode();
    bool getVerticalSyncSetting();
    int getMaxFPS();

    //Mouse control getters
    int getMoveAxisCheckTime();
    sf::Vector2f getMoveAxisCheckMargin();
    
};