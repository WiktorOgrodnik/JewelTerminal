#include "label.hpp"

Label::Label(std::string label, sf::Font* font, unsigned fontSize, const sf::Vector2f& position, const sf::Color& fontColor) : Drawable()
{
    this->body.setCharacterSize(fontSize);
    this->body.setFont(*font);
    this->body.setFillColor(fontColor);
    this->body.setString(label);
    this->body.setPosition(position);
}

Label::~Label()
{

}

void Label::draw(sf::RenderWindow* window)
{
    window->draw(this->body);
}

void Label::setPosition(const sf::Vector2f& position)
{
    this->body.setPosition(position);
}

void Label::move(const sf::Vector2f& moveVector)
{
    this->body.move(moveVector);
}

void Label::setRotation(float angle)
{
    this->body.setRotation(angle);
}

void Label::rotate(float angle)
{
    this->body.rotate(angle);
}

void Label::setScale(const sf::Vector2f& scale)
{
    this->body.setScale(scale);
}

void Label::scale(const sf::Vector2f& scale)
{
    this->body.scale(scale);
}

void Label::setOrigin(const sf::Vector2f& origin)
{
    this->body.setOrigin(origin);
}

const sf::Vector2f& Label::getPosition()
{
    return this->body.getPosition();
}

const sf::Vector2f& Label::getOrigin()
{
    return this->body.getOrigin();
}

const sf::Vector2f& Label::getScale()
{
    return this->body.getScale();
}

float Label::getRotation()
{
    return this->body.getRotation();
}

void Label::setFont(sf::Font* font)
{
    this->body.setFont(*font);
}

void Label::setString(std::string label)
{
    this->body.setString(label);
}