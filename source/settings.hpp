#ifndef SETTINGS_HPP
#define SETTINGS_CPP

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
    sf::Color boardLineFillColor;

    //Engine Settings
    sf::VideoMode videoMode;
    bool verticalSync;
    int FPSLimit;

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
    sf::Color getBoardLineFillColor();

    //Engine settings getters
    sf::VideoMode getVideoMode();
    bool getVerticalSyncSetting();
    int getMaxFPS();
    
};

#endif /*SETTINGS_HPP*/
