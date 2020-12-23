#include "pch.hpp"
#include "jewel.hpp"

Jewel::Jewel(sf::Vector2f position, sf::Color color, sf::Vector2f jewelSize)
{
    this->body.setSize(jewelSize);
    this->body.setFillColor(color);
    this->body.setOutlineThickness(1.f);
    this->body.setOutlineColor(sf::Color::Black);
    this->body.setPosition(position);
}

void Jewel::draw(sf::RenderWindow* window)
{
    window->draw(this->body);
}