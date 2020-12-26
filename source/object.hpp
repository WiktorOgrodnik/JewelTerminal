#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "pch.hpp"

class Object
{
    //This is virtual class - DON'T USE IT!
    //Inheritance only!
    
public:
    Object();
    virtual ~Object();

    virtual void draw(sf::RenderWindow* window) = 0;
};


#endif /*OBJECT_HPP*/