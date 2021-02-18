#pragma once

#include "pch.hpp"

class Drawable
{
    //This is virtual class - DON'T USE IT!
    //Inheritance only!

public:

    Drawable();
    virtual ~Drawable();

    virtual void draw(sf::RenderWindow* window) = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual void move(const sf::Vector2f& moveVector) = 0;
    virtual void setRotation(float angle) = 0;
    virtual void rotate(float angle) = 0;
    virtual void setScale(const sf::Vector2f& factors) = 0;
    virtual void scale(const sf::Vector2f& factors) = 0;
    virtual void setOrigin(const sf::Vector2f& origin) = 0;

    virtual const sf::Vector2f& getPosition() = 0;
    virtual const sf::Vector2f& getOrigin() = 0;
    virtual const sf::Vector2f& getScale() = 0;
    virtual float getRotation() = 0;
};