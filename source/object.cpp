#include "pch.hpp"
#include "object.hpp"

Object::Object(){}
Object::~Object(){}

bool Object::isToDelete()
{
    return false;
}

bool Object::isReturn()
{
    return false;
}

bool Object::isSelectable()
{
    return false;
}

bool Object::isToMove()
{
    return false;
}

bool Object::contain(sf::Vector2f mousePos)
{
    return false;
}

std::string Object::getIdentity()
{
    return "default";
} 

void Object::setToDelete() {}
