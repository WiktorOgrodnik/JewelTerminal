#ifndef BOARD_HPP
#define BOARD_HPP

#include "pch.hpp"
#include "jewel.hpp"
#include <vector>

class Board : public Object
{
private:

    sf::RectangleShape line;
    std::vector <std::vector <Jewel*>> theBoard;

public:

    Board(int size, sf::Color color, sf::Vector2f jewelSize);
    ~Board();

    void draw(sf::RenderWindow* window) override;
};

#endif /*BOARD_HPP*/