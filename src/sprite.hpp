#pragma once

#include "drawable.hpp"

class Sprite : public Drawable
{
    sf::Sprite body;

public:

    Sprite(const sf::Vector2f& position, sf::Texture* texture);
    ~Sprite();

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

    //Sprite specyfic functions
    void setTexture(sf::Texture* texture);
};