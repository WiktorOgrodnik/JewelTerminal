/*
This object is to inheritance only. It contains all functions which selectable object should implement.
It also has some default implementations of optional methods.
*/

#pragma once

#include "pch.hpp"

class Selectable
{
    //This is virtual class - DON'T USE IT!
    //Inheritance only!
    
public:

    Selectable();
    virtual ~Selectable();

    virtual bool contain(sf::Vector2f mousePos);
    virtual bool isToMove();
    virtual bool isReturn();
    virtual sf::Vector2f getOriginalPosition() = 0;
    virtual void setOriginalPosition(sf::Vector2f position) = 0;
    virtual void setToDelete();
    virtual bool isToDelete();
    virtual void hover();
    virtual void unHover();
};