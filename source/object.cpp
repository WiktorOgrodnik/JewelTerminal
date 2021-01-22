#include "object.hpp"

Object::Object(){}
Object::~Object(){}

bool Object::contain(sf::Vector2f mousePos)
{
    /**
     * @return object default bahvior
     */

    return false;
}

bool Object::isSelectable()
{
    /**
     * @return object default bahvior
     */

    return false;
}

bool Object::isToMove()
{
    /**
     * @return object default bahvior
     */

    return false;
}

bool Object::isReturn()
{
    /**
     * @return object default bahvior
     */

    return false;
}

sf::Vector2f Object::getOriginalPosition()
{
    /**
     * @brief object default function
     * 
     * @return object current position
     */

    return this->getPosition();
}

void Object::setOriginalPosition(sf::Vector2f position)
{
    /**
     * @brief object default function
     * 
     * @return void
     */

    this->setPosition(position);
}

std::string Object::getIdentity()
{
    /**
     * @return object default
     */

    return "default";
} 

void Object::setToDelete() {}

bool Object::isToDelete()
{
    /**
     * @return object default bahvior
     */

    return false;
}
