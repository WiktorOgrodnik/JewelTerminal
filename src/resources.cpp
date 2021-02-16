#include "resources.hpp"

Resources::Resources()
{
    /**
     * Constructor
     * 
     * @brief Load all images and fonts
     * 
     * To-Do: load info about textures from file textures.ini and fonts.ini
     */

    sf::Texture temp;
    
    if (temp.loadFromFile("img/jewels.png"))
        this->textures["jewels"] = temp;
    else Log::New("Error! Failed to load file img/jewel.png");

    if (temp.loadFromFile("img/board.png"))
        this->textures["board"] = temp;
    else Log::New("Error! Failed to load file img/board.png");

    if (temp.loadFromFile("img/scorewb.png"))
        this->textures["score"] = temp;
    else Log::New("Error! Failed to load file img/scorewb.png");

    sf::Font fontTemp;

    if (fontTemp.loadFromFile("font/CodaCaption-ExtraBold.ttf"))
        this->fonts["mainfont"] = fontTemp;
    else Log::New("Error! Failed to load file font/CodaCaption-ExtraBold.ttf");
}

Resources::~Resources()
{
    /**
     * Destructor
     * 
     */
}

sf::Texture* Resources::getTexture(std::string textureName)
{
    /**
     * @brief texture getter
     * 
     * @return specyfic texture
     */

    for (auto& k : this->textures)
        if (k.first == textureName)
            return &(k.second);
    Log::New("Error! Can not find texture: " + textureName);
    return nullptr;
}

sf::Font* Resources::getFont(std::string fontName)
{
    /**
     * @brief font getter
     * 
     * @return specyfic font
     */

    for (auto& k : this->fonts)
        if (k.first == fontName)
            return &(k.second);
    Log::New("Error! Can not find font: " + fontName);
    return nullptr;
}