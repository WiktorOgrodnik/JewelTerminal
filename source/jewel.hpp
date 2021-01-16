#ifndef JEWEL_HPP
#define JEWEL_HPP

#include "pch.hpp"
#include "object.hpp"

class Jewel : public Object
{
private:

    sf::RectangleShape body;
    sf::Vector2f originalPositon;
    bool del;
    char color;

public:

    Jewel(sf::Vector2f position, sf::Color color, sf::Vector2f jewelSize);
    
    Jewel(sf::Vector2f position, char color, sf::Vector2f jewelSize, sf::Texture* jewelTexture);

    ~Jewel();

    void draw(sf::RenderWindow* window) override;
    bool contain(sf::Vector2f mousePos) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;
    bool isSelectable() override;
    bool isToMove() override;
    sf::Vector2f getPosition() override;
    bool isReturn() override;
    sf::Vector2f getOriginalPosition() override;
    void setOriginalPosition(sf::Vector2f position) override;
    std::string getIdentity() override;
    void setToDelete() override;
    bool isToDelete() override;

    char getColor();
};

#endif /*JEWEL_HPP*/
