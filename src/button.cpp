#include "button.hpp"

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color, const std::string& string, sf::Font* font, unsigned fontSize) : Rectangle(position, size, color), Clickable()
{
    this->orgColor = color;
    this->hoverColor = sf::Color(this->orgColor.r + 40, this->orgColor.g + 40, this->orgColor.b + 40, this->orgColor.a);

    label = new Label(string, font, fontSize, position + sf::Vector2f(10.f, 10.f), sf::Color::White);
}

Button::~Button()
{
    delete this->label;
}

void Button::draw(sf::RenderWindow* window)
{
    window->draw(this->body);
    label->draw(window);
}

bool Button::contain(sf::Vector2f mousePos)
{
    return this->getGlobalBounds().contains(mousePos);
}

sf::Vector2f Button::getOriginalPosition()
{
    return this->getPosition();
}

void Button::setOriginalPosition(sf::Vector2f position)
{
    this->setPosition(position);
}

void Button::hover()
{
    this->setFillColor(this->hoverColor);
}

void Button::unHover()
{
    this->setFillColor(this->orgColor);
}

void Button::signalConnect(void* data)
{
    
}

void Button::clicked()
{

}

void Button::released()
{
    
}

void Button::setLabel(std::string label)
{
    this->label->setString(label);
}

void Button::setLabel(Label* label)
{
    delete this->label;
    this->label = label;
}

