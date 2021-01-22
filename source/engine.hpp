/*
This file contains functions which is used to draw and manage drawable objects
*/

#pragma once

#include "pch.hpp"
#include "layer.hpp"

class Engine
{
private:

    //Don't use this class as an object!

    //This object can not be created
    Engine() {}

public:
    
    //Draw objects
    static void draw(std::vector<Layer*> &layers, sf::RenderWindow* window);
    
    //Add objects
    static void addObject(std::vector<Layer*> &layers, bool topPririty, Object* newObject);
    static void addObject(std::vector<Layer*> &layers, unsigned layer, Object* newObject);
    static void addTopLayer(std::vector<Layer*> &layers);
    //static void addToTheSameLayerAs(std::vector<Layer*>* layers, Object* newObject, Object* existingObject); 

    //Move objects
    static void moveTo(Object* object, sf::Vector2f position);

    //Give selectable
    static Object* giveSelectable(std::vector<Layer*> &layers, sf::Vector2f mousePos);

    //Delete objects
    static void deleteUnnecessary(std::vector<Layer*> &layers);
};