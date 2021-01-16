#ifndef LAYER_HPP
#define LAYER_HPP

#include "pch.hpp"
#include "object.hpp"

class Layer : public Object
{
private:

    std::vector <Object*> objects;

public:

    Layer();
    Layer(Object* newObject);
    ~Layer();

    void draw (sf::RenderWindow* window) override;
    bool contain (sf::Vector2f mousePos) override;
    void move(sf::Vector2f moveVector) override {}
    void setPosition(sf::Vector2f position) override {}
    bool isSelectable() override;
    bool isToMove() override;
    sf::Vector2f getPosition() override;
    bool isReturn() override;
    sf::Vector2f getOriginalPosition() override;
    void setOriginalPosition(sf::Vector2f position) override {}
    std::string getIdentity() override;
    void setToDelete() override {}
    bool isToDelete() override;

    void addToLayer (Object* newObject);
    void deleteFromLayer (Object* newObject);
    void deleteUnnecessary();

    Object* giveObject(sf::Vector2f mousePos);
};

#endif /*LAYER_HPP*/