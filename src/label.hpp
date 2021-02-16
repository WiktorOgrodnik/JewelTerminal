/*
This class is used to display score
*/

#pragma once

#include "object.hpp"

class Label : public Object
{
private:

    sf::RectangleShape body;
    sf::Vector2f boardMargin;

    sf::Text sc;
    std::string str_score;

public:

    Label(sf::Vector2f boardMargin_, unsigned int cur_score, sf::Font* labelFont, sf::Texture* labelTexture);  

    ~Label();
    void newScore(unsigned int cur_score);
    void draw(sf::RenderWindow* window) override;
    void move(sf::Vector2f moveVector) override;
    void setPosition(sf::Vector2f position) override;
    sf::Vector2f getPosition() override;
    std::string getIdentity() override;
};
