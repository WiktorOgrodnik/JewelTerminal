#include "board.hpp"

Board::Board(int size, sf::Color color, sf::Vector2f jewelSize)
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

    // Line
    this->line.setSize(sf::Vector2f(size * (jewelSize.x + 10.f), 3.f));
    this->line.setFillColor(sf::Color::Black);
}

Board::~Board()
{
    /**
     * Destructor
     * 
     * @brief -Delete jewels
     * -clear vector
     */

    for(auto &k : this->theBoard)
    {
        for (auto &l : k) delete l;
        k.clear();
    }

    this->theBoard.clear();
}

void Board::draw(sf::RenderWindow* window)
{   
    /**
     * @param RenderWindow
     * 
     * @brief -Draw the board and the jewels
     * 
     * @return void
     */

    for (int i = 0; i < this->theBoard.size(); i++)
    {
        this->line.setPosition(sf::Vector2f(95, 95 + i * 30));
        window->draw(this->line);

        this->line.rotate(90.f);

        this->line.setPosition(sf::Vector2f(95 + i * 30, 95));
        window->draw(this->line);

        this->line.rotate(270.f);

        for (int j = 0; j < this->theBoard[i].size(); j++)
            this->theBoard[i][j]->draw(window);
    }

    this->line.setPosition(sf::Vector2f(95, 95 + this->theBoard.size() * 30));
    window->draw(this->line);
    this->line.rotate(90.f);

    this->line.setPosition(sf::Vector2f(95 + this->theBoard.size() * 30, 95));
    window->draw(this->line);
    this->line.rotate(270.f);
}