#include "pch.hpp"
#include "jewel.hpp"

Jewel::Jewel(sf::Vector2f position, sf::Color color, sf::Vector2f jewelSize)
{
    /**
     * Constructor
     * 
     * @param position in Window, color of Jewel, size of Jewel
     * @brief -Set parameters of Jewel
     * 
    */

    this->body.setSize(jewelSize);
    this->body.setFillColor(color);
    this->body.setOutlineThickness(1.f);
    this->body.setOutlineColor(sf::Color::Black);
    this->body.setPosition(position);
    this->originalPositon = position;
}

Jewel::Jewel(sf::Vector2f position, char color, sf::Vector2f jewelSize)
{
    /**
     * Constructor
     * 
     * @param position in Window, color of Jewel, size of Jewel
     * @brief -Set parameters of Jewel
     * 
    */

    this->body.setSize(jewelSize);
    this->body.setOutlineThickness(1.f);
    this->body.setOutlineColor(sf::Color::Black);
    switch (color)
    {
        case '1': this->body.setFillColor(sf::Color::Blue); break;
        case '2': this->body.setFillColor(sf::Color::Red); break;
        case '3': this->body.setFillColor(sf::Color::Yellow); break;
        case '4': this->body.setFillColor(sf::Color::Green); break;
        case '5': this->body.setFillColor(sf::Color::Magenta); break;
        case '6': this->body.setFillColor(sf::Color::Cyan); break;
    }
    this->body.setPosition(position);
    this->originalPositon = position;
}


Jewel::~Jewel()
{
    /**
     * Destructor
     * 
     * @brief -Does nothing
     * 
     */
}

void Jewel::draw(sf::RenderWindow* window)
{
    /**
     *
     * @param RenderWindow
     * 
     * @brief -draw object on screen
     * 
     * @return void
     */

    window->draw(this->body);
}

bool Jewel::contain(sf::Vector2f mousePos)
{
    return this->body.getGlobalBounds().contains(mousePos);
}

void Jewel::move(sf::Vector2f moveVector) 
{
    this->body.move(moveVector);
}

void Jewel::setPosition(sf::Vector2f position) 
{
    this->body.setPosition(position);
}

bool Jewel::isSelectable()
{
    return true;
}

bool Jewel::isToMove()
{
    return true;
}

sf::Vector2f Jewel::getPosition()
{
    return this->body.getPosition();
}

bool Jewel::isReturn()
{
    return true;
}

sf::Vector2f Jewel::getOriginalPosition()
{
    return this->originalPositon;
}

void Jewel::setOriginalPosition(sf::Vector2f position)
{
    this->originalPositon = position;
    this->setPosition(position);
}

std::string Jewel::getIdentity()
{
    return "jewel";
}

