#ifndef LABEL_HPP
#define LABEL_HPP

#include "pch.hpp"
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
    bool contain(sf::Vector2f mousePos) override;
  void move(sf::Vector2f moveVector) override;
  void setPosition(sf::Vector2f position) override ;
  sf::Vector2f getPosition() override;
    sf::Vector2f getOriginalPosition() override;
    std::string getIdentity() override;
     void setOriginalPosition(sf::Vector2f position) override;
    void setToDelete() override;
    bool isToDelete() override;
};

#endif /*LABEL_HPP*/
