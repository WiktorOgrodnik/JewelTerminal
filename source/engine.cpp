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
