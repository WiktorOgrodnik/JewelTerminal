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
