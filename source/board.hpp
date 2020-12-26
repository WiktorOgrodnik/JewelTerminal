#ifndef BOARD_HPP
#define BOARD_HPP

#include "pch.hpp"
#include "jewel.hpp"

class Board : public Object
{
private:

    sf::RectangleShape line;
    unsigned size;

public:

    Board(int size_, sf::Vector2f jewelSize);
    ~Board();

    void draw(sf::RenderWindow* window) override;
    bool contain(sf::Vector2f mousePos) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;
};

#endif /*BOARD_HPP*/