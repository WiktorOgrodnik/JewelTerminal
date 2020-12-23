#ifndef JEWEL_HPP
#define JEWEL_HPP

#include "pch.hpp"
#include "object.hpp"

class Jewel : public Object
{
private:
    sf::RectangleShape body;

public:

    void draw(sf::RenderWindow* window) override;

    Jewel(sf::Vector2f position, sf::Color color, sf::Vector2f jewelSize);
};

#endif /*JEWEL_HPP*/