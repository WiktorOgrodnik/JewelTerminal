#pragma once

#include "object.hpp"

class Label : public Object
{
private:
    sf::RectangleShape body;
    sf::Texture boardTexture;
    sf::Vector2f boardMargin;
    bool del;
    
public:

    Label(sf::Vector2f boardMargin_);  

    ~Label();

    void draw(sf::RenderWindow* window) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;
    sf::Vector2f getPosition() override;
    std::string getIdentity() override;
    void setToDelete() override;
    bool isToDelete() override;
};
