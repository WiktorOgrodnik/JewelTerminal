/*
This class contains layer. The layser with the highest priority is drawn on top of the layers.
If two objects overlap, the one is on the uupper layer is shown. The layer is also used to select an object with the muouse. 
*/

#pragma once

#include "object.hpp"

class Layer : public Object
{
private:

    //All objects in layer
    std::vector <Object*> objects;

public:

    //Constructors
    Layer();
    Layer(Object* newObject);
    
    //Destructors
    ~Layer();

    //Object specyfic functions
    void draw (sf::RenderWindow* window) override;
    bool contain (sf::Vector2f mousePos) override;
    void move(sf::Vector2f moveVector) override {}
    void setPosition(sf::Vector2f position) override {}
    sf::Vector2f getPosition() override;
    std::string getIdentity() override;

    //Operations on layer
    void addToLayer (Object* newObject);
    void deleteFromLayer (Object* newObject);
    void deleteUnnecessary();

    //Getters
    Object* giveObject(sf::Vector2f mousePos);
};