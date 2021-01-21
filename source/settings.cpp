#include "settings.hpp"

Settings::Settings()
{
    //Jewel
    this->jewelSize = sf::Vector2f(20.f, 20.f);
    this->switchTime = 1.5f;

    //Board
    this->boardSize = 13u;
    this->boardInnerPadding = 7.f;
    this->boardLineThickness = 3.f;
    this->boardMargin = sf::Vector2f(199.f, 130.f);
    this->boardLineFillColor = sf::Color::Black;

    //Engine
    this->FPSLimit = 60;
    this->verticalSync = true;
    this->videoMode.height = 600;
    this->videoMode.width = 800;
}

sf::Vector2f Settings::getJewelSize()
{
    return this->jewelSize;
} 

float Settings::getSwitchTime()
{
	return this->switchTime;
}

unsigned Settings::getBoardSize()
{
    return this->boardSize;
}

sf::Vector2f Settings::getBoardMargin()
{
    return this->boardMargin;
}

float Settings::getBoardInnerPadding()
{
    return this->boardInnerPadding;
}

float Settings::getBoardLineThickness()
{
    return this->boardLineThickness;
}

sf::Color Settings::getBoardLineFillColor()
{
    return this->boardLineFillColor;
}

sf::VideoMode Settings::getVideoMode()
{
    return this->videoMode;
}

int Settings::getMaxFPS()
{
    return this->FPSLimit;
}

bool Settings::getVerticalSyncSetting()
{
    return this->verticalSync;
}
