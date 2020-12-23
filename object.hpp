#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "pch.hpp"

class Object
{
public:
    Object();
    virtual ~Object();

    virtual void draw(sf::RenderWindow* window) = 0;
};


#endif /*OBJECT_HPP*/