#include "board.hpp"

Board::Board(int size_, sf::Vector2f jewelSize)
{
    /**
     *  Constructor
     *   
     *  @param size of board, color of jewels (temporary), size of jewel
     *  
     *  @brief -Initialize theBoard
     *  -Create jewels
     *  -Create line, which is used to create board borders
     *  -Set board margin (temporary)
     * 
     *  TO-DO:
     *  -Add more parameters to margins and distance
    */
    this->size = size_;
    // Line
    this->line.setSize(sf::Vector2f(size * (jewelSize.x + 10.f), 3.f));
    this->line.setFillColor(sf::Color::Black);
}

Board::~Board()
{
    /**
     * Destructor
     * 
     * @brief 
     * 
     */
}

void Board::draw(sf::RenderWindow* window)
{   
    /**
     * @param RenderWindow
     * 
     * @brief -Draw the board
     * 
     * @return void
     */

    for (int i = 0; i <= this->size; i++)
    {
        this->line.setPosition(sf::Vector2f(95, 95 + i * 30));
        window->draw(this->line);

        this->line.rotate(90.f);

        this->line.setPosition(sf::Vector2f(95 + i * 30, 95));
        window->draw(this->line);

        this->line.rotate(270.f);
    }

    //this->line.setPosition(sf::Vector2f(95, 95 + this->theBoard.size() * 30));
    //indow->draw(this->line);
    //this->line.rotate(90.f);

    //this->line.setPosition(sf::Vector2f(95 + this->theBoard.size() * 30, 95));
    //window->draw(this->line);
    //this->line.rotate(270.f);
}

bool Board::contain(sf::Vector2f mousePos)
{
    return false;
}

void Board::move(sf::Vector2f moveVector)
{
    ;
}

void Board::setPosition(sf::Vector2f position)
{
    ;
}