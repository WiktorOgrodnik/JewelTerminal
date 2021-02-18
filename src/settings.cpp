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
    this->boardMargin = sf::Vector2f(229.f, 130.f);
    this->boardPosition = sf::Vector2f(191.f, 103.f);
    this->boardSizePixels = sf::Vector2f(417.f, 392.f);

    //Score texture
    this->scoreImagePosition = sf::Vector2f(20.f, 150.f);

    //Score text
    this->scoreTextFontSize = 26;
    this->scoreTextPosition = sf::Vector2f(40.f, 230.f);

    //Engine
    this->FPSLimit = 60;
    this->verticalSync = true;
    this->videoMode.height = 600;
    this->videoMode.width = 800;

    //Animations
    this->fallingAnimationSpeed = 235.f;

    //Mouse control
    this->moveAxisCheckTime = 1;
    this->moveAxisCheckMargin = sf::Vector2f(6.f, 6.f);
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

sf::Vector2f Settings::getBoardSizePixels()
{
    return this->boardSizePixels;
}

sf::Vector2f Settings::getBoardPosition()
{
    return this->boardPosition;
}

float Settings::getBoardInnerPadding()
{
    return this->boardInnerPadding;
}

float Settings::getBoardLineThickness()
{
    return this->boardLineThickness;
}

sf::Vector2f Settings::getScoreImagePosition()
{
    return this->scoreImagePosition;
}

sf::Vector2f Settings::getScoreTextPosition()
{
    return this->scoreTextPosition;
}

unsigned Settings::getScoreTextFontSize()
{
    return this->scoreTextFontSize;
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

float Settings::getFallingAnimationSpeed()
{
    return this->fallingAnimationSpeed;
}

int Settings::getMoveAxisCheckTime()
{
    return this->moveAxisCheckTime;
}

sf::Vector2f Settings::getMoveAxisCheckMargin()
{
    return this->moveAxisCheckMargin;
}
