#pragma once

#include "clickable.hpp"
#include "label.hpp"
#include "rectangle.hpp"

class Button : public Rectangle, public Clickable
{
    sf::Color orgColor;
    sf::Color hoverColor;
    Label* label;

public:

    Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color, const std::string& label, sf::Font* font, unsigned fontSize);
    ~Button();

    //Drawable specyfic functions
    void draw(sf::RenderWindow* window) override;

    //Selectable specyfic functions
    bool contain(sf::Vector2f mousePos) override;
    sf::Vector2f getOriginalPosition() override;
    void setOriginalPosition(sf::Vector2f mousePos) override;
    void hover() override;
    void unHover() override;

    //Clickable specyfic functions
    void signalConnect(void* data) override;
    void clicked() override;
    void released() override;

    //Button specyfic functions
    void setLabel(std::string label);
    void setLabel(Label* label);
};