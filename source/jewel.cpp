#include "pch.hpp"
#include "jewel.hpp"

Jewel::Jewel(sf::Vector2f position, char color, sf::Vector2f jewelSize, sf::Texture* jewelTexture)
{
    /**
     * Constructor
     *
     * @param position in Window, color of Jewel, size of Jewel, texture of Jewel
     * @brief -Set parameters of Jewel
     *
    */

    if (color < '1' || color > '6') 
    {
        std::cerr << "Critical error! Jewel must not be color '0'.\n";
        exit(0);
    }
    else
    {
        this->body.setSize(jewelSize);
        this->body.setTexture(jewelTexture);
        this->body.setTextureRect(sf::IntRect(0.0f, 20.0f*((int)color-'1'), 20.0f, 20.0f)); //All textures are in the same file
        this->color = color;
        this->body.setPosition(position);
        this->originalPositon = position;
        this->del = false;
        this->currentPhase = 0;
    }
}


Jewel::~Jewel()
{
    /**
     * Destructor
     *
     * @brief -Does nothing
     *
     */
}

void Jewel::draw(sf::RenderWindow* window)
{
    /**
     *
     * @param RenderWindow
     *
     * @brief -draw object on screen
     *
     * @return void
     */

    if (this->color != '0')
        window->draw(this->body);
    //else std::cerr << "Critical error! Engine tried to display jewel without color!\n";
}

bool Jewel::contain(sf::Vector2f mousePos)
{
    /**
     * @brief -Checks if the mouse postitin is witihn the object
     * 
     * @return void
     */

    return this->body.getGlobalBounds().contains(mousePos);
}

void Jewel::move(sf::Vector2f moveVector)
{
    /**
     * @brief -Move the object by the vector
     * 
     * @return void
     */

    this->body.move(moveVector);
}

void Jewel::setPosition(sf::Vector2f position)
{
    /**
     * @brief -Move the object to another position
     * 
     * @return void
     */

    this->body.setPosition(position);
}

bool Jewel::isSelectable()
{
    /**
     * @return the object property
     */

    return true;
}

bool Jewel::isToMove()
{
    /**
     * @return the object property
     */

    return true;
}

sf::Vector2f Jewel::getPosition()
{
    /**
     * @return the object position
     */

    return this->body.getPosition();
}

bool Jewel::isReturn()
{
    /**
     * @return the object property
     */

    return true;
}

sf::Vector2f Jewel::getOriginalPosition()
{
    /**
     * @brief Original position is object special position, it is returning to it when player drop it
     * 
     * @return the object original position
     */
    
    return this->originalPositon;
}

void Jewel::setOriginalPosition(sf::Vector2f position)
{
    /**
     * @brief -set original position of the object
     * 
     * @return void
     */

    this->originalPositon = position;
    this->setPosition(position);
}

std::string Jewel::getIdentity()
{
    /**
     * @return name of the object
     */

    return "jewel";
}

void Jewel::setToDelete()
{
    /**
     * @brief -set the object to delete before render next frame
     * 
     * @return void
     */

    this->del = true;
}

bool Jewel::isToDelete()
{
    /**
     * @return if the object is need to remove before render next frame
     */

    return this->del;
}

void Jewel::hover()
{
    /**
     * @brief -What jewel has to done when it is indicated by mouse cursor
     * 
     */

    this->body.setScale(sf::Vector2f(1.05f, 1.05f));

}

void Jewel::unHover()
{
    /**
     * @brief -What jewel has to done when it is not indicated by mouse cursor any more
     * 
     */

    this->body.setScale(sf::Vector2f(1.f, 1.f));

}

void Jewel::updateAnimation(int currentPhase, sf::Texture* jewelTexture)
{
    /**
     * @brief -Update current phase of idle animation
     * 
     * @return void
     */

    if(currentPhase >= 3)
        currentPhase -= 3;
    this->currentPhase = currentPhase;
    this->body.setTextureRect(sf::IntRect(20.0f*currentPhase, 20.0f*((int)(this->color)-'1'), 20.0f, 20.0f));
}

void Jewel::setOriginalPosition2(sf::Vector2f position)
{
    /**
     * @brief -Special version of setOriginalPosition, it change originalPosition without current position
     * -Made for compatibility reason
     * 
     * @return void
     */

    this->originalPositon = position;
}

char Jewel::getColor()
{
    /**
     * @return jewel color
     */

    return this->color;
}

void Jewel::setColor(char a)
{
    /**
     * @brief -Set jewel color
     * 
     * @return void
     */

    this->color = a;
}
