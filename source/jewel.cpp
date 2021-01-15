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
    this->del = false;
}

Jewel::Jewel(sf::Vector2f position, char color, sf::Vector2f jewelSize, sf::Texture* jewelTexture)
{
    /**
     * Constructor
     * 
     * @param position in Window, color of Jewel, size of Jewel
     * @brief -Set parameters of Jewel
     * 
    */

    this->body.setSize(jewelSize);
    this->body.setTexture(jewelTexture);
    this->body.setTextureRect(sf::IntRect(0.0f, 20.0f*((int)color-'1'), 20.0f, 20.0f));
    this->color = color;
    this->body.setPosition(position);
    this->originalPositon = position;
    this->del = false;
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

char Jewel::getColor()
{
    return this->color;
}

void Jewel::setToDelete()
{
    this->del = true;
}

bool Jewel::isToDelete()
{
    return this->del;
}



