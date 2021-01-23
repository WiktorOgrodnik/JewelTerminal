/*
This class contains layer. The layser with the highest priority is drawn on top of the layers.
If two objects overlap, the one is on the upper layer is shown. The layer is also used to select an object with the muouse. 
*/

#pragma once

#include "object.hpp"

class Layer
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

    //Opetation on layer
    void draw (sf::RenderWindow* window, float boardMarginy);
    bool contain (sf::Vector2f mousePos);
    void addToLayer (Object* newObject);
    void deleteFromLayer (Object* newObject);
    void deleteUnnecessary();

    //Getters
    Object* giveObject(sf::Vector2f mousePos);
};