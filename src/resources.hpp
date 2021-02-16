/*
This class stores all textures and fonts used in the program 
*/

#pragma once

#include "pch.hpp"

class Resources
{
    //Textures
    std::map <std::string, sf::Texture> textures;

    //Fonts
    std::map <std::string, sf::Font> fonts;

public:

    //Lodad all textures and fonts
    Resources();
    ~Resources();
    
    //Getters
    sf::Texture* getTexture(std::string textureName);
    sf::Font* getFont(std::string fontName);
};