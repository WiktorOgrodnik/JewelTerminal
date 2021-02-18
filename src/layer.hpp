/*
This class contains layer. The layser with the highest priority is drawn on top of the layers.
If two objects overlap, the one is on the upper layer is shown. The layer is also used to select an object with the muouse. 
*/

#pragma once

#include "jewel.hpp"

class Layer
{
private:

    //All objects in layer
    std::vector <Drawable*> objects;

public:

    //Constructors
    Layer();
    Layer(Drawable* newObject);
    
    //Destructors
    ~Layer();

    //Opetation on layer
    void draw (sf::RenderWindow* window, float boardMargin);
    bool contain (sf::Vector2f mousePos);
    void addToLayer (Drawable* newObject);
    void deleteFromLayer (Drawable* newObject);
    void deleteUnnecessary();

    //Getters
    Selectable* giveObject(sf::Vector2f mousePos);
};