#include "label.hpp"

Label::Label(sf::Texture image, sf::Vector2f position)
{
    /**
     * Constructor
     * 
     * 
     * 
    */
   
   this->sprite.setTexture(image);
   this->del = false;
    this->sprite.setPosition(position);
}
Label::~Label()
{
    /**
     * Destructor
     * 
     * 
     * 
     */
}

void Label::draw(sf::RenderWindow* window)
{
    /**
     *
     * 
     * 
     */

    window->draw(this->sprite);
}

bool Label::contain(sf::Vector2f mousePos)
{
   return false;
}

void Label::move(sf::Vector2f moveVector)
{
   
}

void Label::setPosition(sf::Vector2f position)
{
    
}

bool Label::isSelectable()
{
    return false;
}

bool Label::isToMove()
{
    return false;
}

sf::Vector2f Label::getPosition()
{
    return sf::Vector2f(10, 10);
}

bool Label::isReturn()
{
    return false;
}

sf::Vector2f Label::getOriginalPosition()
{
    return this->getPosition();
}

void Label::setOriginalPosition(sf::Vector2f position)
{
    this->setPosition(position);
}

std::string Label::getIdentity()
{
    return "label";
}

void Label::setToDelete()
{
    this->del = true;
}

bool Label::isToDelete()
{
   return del;
}
