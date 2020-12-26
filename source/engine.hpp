#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "pch.hpp"
#include "layer.hpp"

class Engine
{
public:

    static void draw(std::vector<Layer*> &layers, sf::RenderWindow* window);
    static void addObject(std::vector<Layer*> &layers, bool topPririty, Object* newObject);
    //static void addToTheSameLayerAs(std::vector<Layer*>* layers, Object* newObject, Object* existingObject); 
};

#endif /*ENGINE_HPP*/