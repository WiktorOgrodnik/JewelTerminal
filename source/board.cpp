#include "board.hpp"

Board::Board(unsigned size_, sf::Vector2f jewelSize_, float padding_, float lineThickness_, sf::Color lineColor, sf::Vector2f boardMargin_)
{
    /**
     *  Constructor
     *   
     *  @param size of board, size of jewel, size of padding, line thickness, line color, boardMargin
     *  
     *  -Initialize theBoard
     *  -Create line, which is used to create board borders
     *  -Set board margin (temporary)
    */

    this->size = size_;
    this->lineThickness = lineThickness_;
    this->padding = padding_;
    this->jewelSize = jewelSize_;
    this->boardMargin = boardMargin_;

    // Line
    this->line.setSize(sf::Vector2f(this->size * (this->jewelSize.x + this->padding), this->lineThickness));
    this->line.setFillColor(lineColor);
}

Board::~Board()
{
    /**
     * Destructor
     * 
     */
}

void Board::draw(sf::RenderWindow* window)
{   
    /**
     * @param RenderWindow
     * 
     * -Draw the board
    */

    for (unsigned i = 0; i <= this->size; i++)
    {
        this->line.setPosition(sf::Vector2f(this->boardMargin.x - (this->padding / 2), this->boardMargin.y - (this->padding / 2) + static_cast<float>(i) * (this->jewelSize.y + this->padding)));
        window->draw(this->line);

        this->line.rotate(90.f);

        this->line.setPosition(sf::Vector2f(this->boardMargin.x - (this->padding / 2) + static_cast<float>(i) * (this->jewelSize.x + this->padding), this->boardMargin.y - (this->padding / 2)));
        window->draw(this->line);

        this->line.rotate(270.f);
    }
}

bool Board::contain(sf::Vector2f mousePos)
{
    return mousePos.x >= this->boardMargin.x - (this->padding / 2) 
    && mousePos.x <= this->boardMargin.x - (this->padding / 2) + this->size * (this->jewelSize.x + this->padding) 
    && mousePos.y >= this->boardMargin.y - (this->padding / 2) 
    && mousePos.y <= this->boardMargin.y - (this->padding / 2) + this->size * (this->jewelSize.y + this->padding);
}

void Board::move(sf::Vector2f moveVector)
{
    this->boardMargin.x += moveVector.x + (this->padding / 2);
    this->boardMargin.y += moveVector.x + (this->padding / 2);
}

void Board::setPosition(sf::Vector2f position)
{
    this->boardMargin.x = position.x + (this->padding / 2);
    this->boardMargin.y = position.x + (this->padding / 2);
}

bool Board::isSelectable()
{
    return false;
}

bool Board::isToMove()
{
    return false;
}

sf::Vector2f Board::getPosition()
{
    return sf::Vector2f(this->boardMargin.x - (this->padding / 2), this->boardMargin.y - (this->padding / 2));
}

bool Board::isReturn()
{
    return false;
}

sf::Vector2f Board::getOriginalPosition()
{
    return this->getPosition();
}

void Board::setOriginalPosition(sf::Vector2f position)
{
    this->setPosition(position);
}

std::string Board::getIdentity()
{
    return "board";
}
