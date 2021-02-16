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
    std::vector <sf::Drawable*> objects;

public:

    //Constructors
    Layer();
    Layer(sf::Drawable* newObject);
    
    //Destructors
    ~Layer();

    //Opetation on layer
    void draw (sf::RenderWindow* window, float boardMargin);
    bool contain (sf::Vector2f mousePos);
    void addToLayer (sf::Drawable* newObject);
    void deleteFromLayer (sf::Drawable* newObject);
    void deleteUnnecessary();

    //Getters
    Selectable* giveObject(sf::Vector2f mousePos);
};