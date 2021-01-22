#pragma once

#include "object.hpp"

class Label : public Object
{
private:
    sf::Vector2f labelPositon;
    sf::Sprite sprite;
    bool del;
public:

    Label(sf::Texture image, sf::Vector2f position);  

    ~Label();

    void draw(sf::RenderWindow* window) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;
    sf::Vector2f getPosition() override;
    std::string getIdentity() override;
    void setToDelete() override;
    bool isToDelete() override;
};
