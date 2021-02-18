#pragma once

#include "drawable.hpp"

class Rectangle : public Drawable
{
protected:

    sf::RectangleShape body;

public:

    Rectangle(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture);
    Rectangle(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color);

    virtual ~Rectangle();

    //Drawable specyfic functions
    void draw(sf::RenderWindow* window) override;
    void setPosition(const sf::Vector2f& position) override;
    void move(const sf::Vector2f& moveVector) override;
    void setRotation(float angle) override;
    void rotate(float angle) override;
    void setScale(const sf::Vector2f& factors) override;
    void scale(const sf::Vector2f& factors) override;
    void setOrigin(const sf::Vector2f& origin) override;

    const sf::Vector2f& getPosition() override;
    const sf::Vector2f& getOrigin() override;
    const sf::Vector2f& getScale() override;
    float getRotation() override;

    //Rectangle specyfic functions
    virtual void setTexture(sf::Texture* texture);
    virtual void setTextureRect(const sf::IntRect& rect);
    virtual void setSize(const sf::Vector2f& size);

    virtual const sf::Vector2f& getSize();
    virtual sf::FloatRect getGlobalBounds();

    virtual void setFillColor(const sf::Color& color);

};