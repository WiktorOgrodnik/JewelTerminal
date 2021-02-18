#include "sprite.hpp"

Sprite::Sprite(const sf::Vector2f& position, sf::Texture* texture)
{
    this->body.setPosition(position);
    this->body.setTexture(*texture);
}

Sprite::~Sprite()
{

}

void Sprite::draw(sf::RenderWindow* window)
{
    window->draw(this->body);
}

void Sprite::setPosition(const sf::Vector2f& position)
{
    this->body.setPosition(position);
}

void Sprite::move(const sf::Vector2f& moveVector)
{
    this->body.move(moveVector);
}

void Sprite::setRotation(float angle)
{
    this->body.setRotation(angle);
}

void Sprite::rotate(float angle)
{
    this->body.rotate(angle);
}

void Sprite::setScale(const sf::Vector2f& scale)
{
    this->body.setScale(scale);
}

void Sprite::scale(const sf::Vector2f& scale)
{
    this->body.scale(scale);
}

void Sprite::setOrigin(const sf::Vector2f& origin)
{
    this->body.setOrigin(origin);
}

const sf::Vector2f& Sprite::getPosition()
{
    return this->body.getPosition();
}

const sf::Vector2f& Sprite::getOrigin()
{
    return this->body.getOrigin();
}

const sf::Vector2f& Sprite::getScale()
{
    return this->body.getScale();
}

float Sprite::getRotation()
{
    return this->body.getRotation();
}

void Sprite::setTexture(sf::Texture* texture)
{
    this->body.setTexture(*texture);
}