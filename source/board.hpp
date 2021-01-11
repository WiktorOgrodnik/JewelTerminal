#ifndef BOARD_HPP
#define BOARD_HPP

#include "pch.hpp"
#include "jewel.hpp"

class Board : public Object
{
private:

    sf::RectangleShape line;
    unsigned size;
    float padding;
    float lineThickness;
    sf::Vector2f jewelSize;
    sf::Vector2f boardMargin;

public:

    Board(unsigned size_, sf::Vector2f jewelSize_, float padding_, float lineThickness_,  sf::Color lineColor, sf::Vector2f boardMargin_);
    ~Board();

    void draw(sf::RenderWindow* window) override;
    bool contain(sf::Vector2f mousePos) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;
    bool isSelectable() override;
    bool isToMove() override;
    sf::Vector2f getPosition() override;
};

#endif /*BOARD_HPP*/