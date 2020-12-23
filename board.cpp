#include "board.hpp"

Board::Board(int size, sf::Color color, sf::Vector2f jewelSize)
{
    this->theBoard.resize(size);

    float inX = 100;
    float inY = 100;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Jewel* temp = new Jewel(sf::Vector2f(inX + j * 30.f, inY + i * 30.f), color, jewelSize);
            this->theBoard[i].push_back(temp);
        }
    }

    this->line.setSize(sf::Vector2f(size * (jewelSize.x + 10.f), 3.f));
    this->line.setFillColor(sf::Color::Black);
}

void Board::draw(sf::RenderWindow* window)
{   
    for (int i = 0; i < theBoard.size(); i++)
    {
        this->line.setPosition(sf::Vector2f(95, 95 + i * 30));
        window->draw(this->line);

        line.rotate(90.f);

        this->line.setPosition(sf::Vector2f(95 + i * 30, 95));
        window->draw(this->line);

        line.rotate(270.f);

        for (int j = 0; j < theBoard[i].size(); j++)
            theBoard[i][j]->draw(window);
    }

    this->line.setPosition(sf::Vector2f(95, 95 + theBoard.size() * 30));
    window->draw(this->line);
    line.rotate(90.f);

    this->line.setPosition(sf::Vector2f(95 + theBoard.size() * 30, 95));
    window->draw(this->line);
    line.rotate(270.f);

       
}