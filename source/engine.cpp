#include "engine.hpp"

void Engine::draw(std::vector<Layer*> &layers, sf::RenderWindow* window)
{
    window->clear(sf::Color::White);
    for (auto &k : layers) k->draw(window);
    window->display();
}

void Engine::addObject(std::vector<Layer*> &layers, bool topPririty, Object* newObject)
{
    if (topPririty || layers.empty()) 
    {
        Layer* newLayer = new Layer(newObject);
        layers.push_back(newLayer);
    }
    else layers.at(layers.size() - 1)->addToLayer(newObject);
}

void Engine::addTopLayer(std::vector<Layer*> &layers)
{
    Layer* newLayer = new Layer();
    layers.push_back(newLayer);
}

void Engine::moveTo(Object* object, sf::Vector2f position)
{
    object->setPosition(position);
}

Object* Engine::giveSelectable(std::vector<Layer*> &layers, sf::Vector2f mousePos)
{
    for (int i = layers.size() - 1; i >= 0; i--)
    {
        Object* t = nullptr;
        if (layers[i]->contain(mousePos)) 
        {
            t = layers[i]->giveObject(mousePos);
            if (t->isSelectable()) return t;
        }
    }

    return nullptr;
}
