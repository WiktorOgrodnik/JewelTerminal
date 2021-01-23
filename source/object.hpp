/*
This object is to inheritance only. It contains all functions which drawable object should implement.
It also has some default implementations of optional methods.
*/

#pragma once

#include "pch.hpp"

class Object
{
    //This is virtual class - DON'T USE IT!
    //Inheritance only!
    
public:

    Object();
    virtual ~Object();

    virtual void draw(sf::RenderWindow* window) = 0;
    virtual bool contain(sf::Vector2f mousePos);
    virtual void move(sf::Vector2f moveVector) = 0;
    virtual void setPosition(sf::Vector2f position) = 0;
    virtual bool isSelectable();
    virtual bool isToMove();
    virtual sf::Vector2f getPosition() = 0;
    virtual bool isReturn();
    virtual sf::Vector2f getOriginalPosition();
    virtual void setOriginalPosition(sf::Vector2f position);
    virtual std::string getIdentity(); 
    virtual void setToDelete();
    virtual bool isToDelete();
    virtual void hover();
    virtual void unHover();
};