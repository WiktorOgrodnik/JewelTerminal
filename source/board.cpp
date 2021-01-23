#include "board.hpp"

Board::Board(unsigned size, sf::Vector2f jewelSize, float padding, float lineThickness, sf::Vector2f boardMargin)
{
    /**  
     * Constructor
     *   
     *  @param size of board, size of jewel, size of padding, line thickness, line color, boardMargin
     *  
     *  -Initialize theBoard
     *  -Set board margins and dimensions
     */

    this->size = size;
    this->lineThickness = lineThickness;
    this->padding = padding;
    this->jewelSize = jewelSize;
    this->boardMargin = boardMargin;
    this->body.setSize(sf::Vector2f(417.0f, 392.0f));
	this->boardTexture.loadFromFile("img/Board.png");
	this->body.setTexture(&boardTexture);
	this->body.setPosition(sf::Vector2f(this->boardMargin.x - 38.0f, this->boardMargin.y - 27.0f));

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
     *
     * @param RenderWindow
     *
     * @brief -draw object on screen
     *
     * @return void
     */

    window->draw(this->body);
}

bool Board::contain(sf::Vector2f mousePos)
{
    /**
     * @brief -Checks if the mouse postitin is witihn the object
     * 
     * @return void
     */

    return mousePos.x >= this->boardMargin.x - (this->padding / 2) 
    && mousePos.x <= this->boardMargin.x - (this->padding / 2) + this->size * (this->jewelSize.x + this->padding) 
    && mousePos.y >= this->boardMargin.y - (this->padding / 2) 
    && mousePos.y <= this->boardMargin.y - (this->padding / 2) + this->size * (this->jewelSize.y + this->padding);
}

void Board::move(sf::Vector2f moveVector)
{
    /**
     * @brief -Move the object by the vector
     * 
     * @return void
     */

    this->boardMargin.x += moveVector.x + (this->padding / 2);
    this->boardMargin.y += moveVector.x + (this->padding / 2);
}

void Board::setPosition(sf::Vector2f position)
{
    /**
     * @brief -Move the object to another position
     * 
     * @return void
     */

    this->boardMargin.x = position.x + (this->padding / 2);
    this->boardMargin.y = position.x + (this->padding / 2);
}

sf::Vector2f Board::getPosition()
{
    /**
     * @return the object position
     */

    return sf::Vector2f(this->boardMargin.x - (this->padding / 2), this->boardMargin.y - (this->padding / 2));
}

std::string Board::getIdentity()
{
    /**
     * @return name of the object
     */

    return "board";
}
