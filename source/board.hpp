/*
This object is used to draw board.
*/

#pragma once

#include "jewel.hpp"

class Board : public Object
{
private:

    //Board appearance
    unsigned size;
    float padding;
    float lineThickness;
    sf::Vector2f jewelSize;
    sf::Vector2f boardMargin;

    sf::RectangleShape body;
    sf::Texture boardTexture;

public:

    //Constructor
    Board(unsigned size_, sf::Vector2f jewelSize, float padding, float lineThickness, sf::Vector2f boardMargin);

    //Descructor
    ~Board();

    //Object specyfic functions
    void draw(sf::RenderWindow* window) override;
    bool contain(sf::Vector2f mousePos) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;
    sf::Vector2f getPosition() override;
    std::string getIdentity() override;
};