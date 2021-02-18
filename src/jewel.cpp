#include "jewel.hpp"

Jewel::Jewel(const sf::Vector2f position, char color, sf::Vector2f jewelSize, sf::Texture* jewelTexture) : Rectangle(position, jewelSize, jewelTexture), Selectable()
{
    /**
     * Constructor
     *
     * @param position in Window, color of Jewel, size of Jewel, texture of Jewel
     * @brief -Set parameters of Jewel
     *
    */

    this->setTexture(jewelTexture);
    this->setPosition(position);

    this->color = color;
    this->originalPositon = position;
    this->del = false;
    this->currentPhase = 0;

    if (this->color >= '1' && this->color <= '6')  
        this->setTextureRect(sf::IntRect(0.0f, 20.0f*((int)color-'1'), 20.0f, 20.0f)); //All textures are in the same file
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

bool Jewel::contain(sf::Vector2f mousePos)
{
    /**
     * @brief -Checks if the mouse postitin is witihn the object
     * 
     * @return void
     */

    return this->getGlobalBounds().contains(mousePos);
}

bool Jewel::isToMove()
{
    /**
     * @return the object property
     */

    return true;
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

    this->setScale(sf::Vector2f(1.05f, 1.05f));

}

void Jewel::unHover()
{
    /**
     * @brief -What jewel has to done when it is not indicated by mouse cursor any more
     * 
     */

    this->setScale(sf::Vector2f(1.f, 1.f));

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
    this->setTextureRect(sf::IntRect(20.0f*currentPhase, 20.0f*((int)(this->color)-'1'), 20.0f, 20.0f));
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

    if (this->color >= '1' && this->color <= '6')  
        this->setTextureRect(sf::IntRect(0.0f, 20.0f*((int)color-'1'), 20.0f, 20.0f)); //All textures are in the same file
}