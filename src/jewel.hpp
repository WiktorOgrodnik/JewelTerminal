/*
This object is used to draw jewel on screen.
*/

#pragma once

#include "selectable.hpp"
#include "rectangle.hpp"

class Jewel : public Rectangle, public Selectable
{
private:

    sf::Vector2f originalPositon;
    bool del; //is object to delete
    char color; //jewel color
    int currentPhase; //current animation phase

public:

    //Constructor
    Jewel(sf::Vector2f position, char color, sf::Vector2f jewelSize, sf::Texture* jewelTexture);

    //Destructor
    ~Jewel();

    //Selectable specyfic functions
    bool contain(sf::Vector2f mousePos) override;
    bool isToMove() override;
    bool isReturn() override;
    sf::Vector2f getOriginalPosition() override;
    void setOriginalPosition(sf::Vector2f position) override;
    void setToDelete() override;
    bool isToDelete() override;
    void hover() override;
    void unHover() override;

    //Jewel idle animation functions
    void updateAnimation(int currentPhase, sf::Texture* jewelTexture);

    //Jewel logic functions
    void setOriginalPosition2(sf::Vector2f position);
    char getColor();
    void setColor(char a);
};