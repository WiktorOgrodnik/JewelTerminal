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
    bool contain(sf::Vector2f mousePos) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;

    Jewel(sf::Vector2f position, sf::Color color, sf::Vector2f jewelSize);
    ~Jewel();
};

#endif /*JEWEL_HPP*/