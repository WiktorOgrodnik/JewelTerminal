#pragma once

#include "drawable.hpp"

class Label : public Drawable
{
    sf::Text body;

public:

    Label(std::string label, sf::Font* font, unsigned fontSize, const sf::Vector2f& position, const sf::Color& fontColor);
    ~Label();

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

    //Label specyfic functions
    void setFont(sf::Font* font);
    void setString(std::string label);
};