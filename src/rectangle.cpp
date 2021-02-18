#include "rectangle.hpp"

Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture)
{
    this->setPosition(position);
    this->setSize(size);
    this->setTexture(texture);
}

Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
{
    this->setPosition(position);
    this->setSize(size);
    this->setFillColor(color);
}

Rectangle::~Rectangle()
{
    
}

void Rectangle::draw(sf::RenderWindow* window)
{
    window->draw(this->body);
}

void Rectangle::setPosition(const sf::Vector2f& position)
{
    this->body.setPosition(position);
}

void Rectangle::move(const sf::Vector2f& moveVector)
{
    this->body.move(moveVector);
}

void Rectangle::setRotation(float angle)
{
    this->body.setRotation(angle);
}

void Rectangle::rotate(float angle)
{
    this->body.rotate(angle);
}

void Rectangle::setScale(const sf::Vector2f& scale)
{
    this->body.setScale(scale);
}

void Rectangle::scale(const sf::Vector2f& scale)
{
    this->body.scale(scale);
}

void Rectangle::setOrigin(const sf::Vector2f& origin)
{
    this->body.setOrigin(origin);
}

const sf::Vector2f& Rectangle::getPosition()
{
    return this->body.getPosition();
}

const sf::Vector2f& Rectangle::getOrigin()
{
    return this->body.getOrigin();
}

const sf::Vector2f& Rectangle::getScale()
{
    return this->body.getScale();
}

float Rectangle::getRotation()
{
    return this->body.getRotation();
}

void Rectangle::setTexture(sf::Texture* texture)
{
    this->body.setTexture(texture);
}

void Rectangle::setTextureRect(const sf::IntRect& rect)
{
    this->body.setTextureRect(rect);
}

void Rectangle::setSize(const sf::Vector2f& size)
{
    this->body.setSize(size);
}

const sf::Vector2f& Rectangle::getSize()
{
    return this->body.getSize();
}

sf::FloatRect Rectangle::getGlobalBounds()
{
    return this->body.getGlobalBounds();
}

void Rectangle::setFillColor(const sf::Color& color)
{
    this->body.setFillColor(color);
}