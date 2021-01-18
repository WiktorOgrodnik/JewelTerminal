#ifndef LABEL_HPP
#define LABEL_HPP

#include "pch.hpp"
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
};

#endif /*LABEL_HPP*/
