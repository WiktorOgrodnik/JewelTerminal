/*
This object is used to draw jewel on screen.
*/

#pragma once

#include "object.hpp"

class Jewel : public Object
{
private:

    sf::RectangleShape body;
    sf::Vector2f originalPositon;
    bool del; //is object to delete
    char color; //jewel color
    int currentPhase; //current animation phase

public:

    //Constructor
    Jewel(sf::Vector2f position, char color, sf::Vector2f jewelSize, sf::Texture* jewelTexture);

    //Destructor
    ~Jewel();

    //Object specyfic functions
    void draw(sf::RenderWindow* window) override;
    bool contain(sf::Vector2f mousePos) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;
    bool isSelectable() override;
    bool isToMove() override;
    sf::Vector2f getPosition() override;
    bool isReturn() override;
    sf::Vector2f getOriginalPosition() override;
    void setOriginalPosition(sf::Vector2f position) override;
    std::string getIdentity() override;
    void setToDelete() override;
    bool isToDelete() override;
    void hover() override;

    //Jewel idle animation functions
    void updateAnimation(int currentPhase, sf::Texture* jewelTexture);

    //Jewel logic functions
    void setOriginalPosition2(sf::Vector2f position);
    char getColor();
    void setColor(char a);
};