#include "engine.hpp"

void Engine::draw(std::vector<Layer*> &layers, sf::RenderWindow* window)
{
    /**
     * @brief -Draw all objects
     * 
     * @return void
     */

    window->clear(sf::Color(84, 82, 75, 255));
    for (auto &k : layers) k->draw(window);
    window->display();
}

void Engine::addObject(std::vector<Layer*> &layers, bool topPririty, Object* newObject)
{
    /**
     * @brief -Add object to top layer, possibly make new layer
     * 
     * @return void
     */

    if (topPririty || layers.empty()) 
    {
        Layer* newLayer = new Layer(newObject);
        layers.push_back(newLayer);
    }
    else layers.at(layers.size() - 1)->addToLayer(newObject);
}

void Engine::addObject(std::vector<Layer*> &layers, unsigned layer, Object* newObject)
{
    /**
     * @brief -Add object to specyfic layer
     * 
     * @return void
     */

    layers.at(layer)->addToLayer(newObject);
}

//Engine::deleteObject

void Engine::addTopLayer(std::vector<Layer*> &layers)
{
    /**
     * @brief -Make new layer and push it on top
     * 
     * @return void
     */

    Layer* newLayer = new Layer();
    layers.push_back(newLayer);
}

void Engine::moveTo(Object* object, sf::Vector2f position)
{
    /**
     * @brief -Move object to
     * 
     * @return void
     */

    object->setPosition(position);
}

Object* Engine::giveSelectable(std::vector<Layer*> &layers, sf::Vector2f mousePos)
{
    /**
     * @brief -return object selected by mouse
     * 
     * @return selected object
     */

    for (size_t i = layers.size(); i > 0; i--)
    {
        Object* t = nullptr;
        if (layers[i - 1]->contain(mousePos)) 
        {
            t = layers[i - 1]->giveObject(mousePos);
            if (t->isSelectable()) return t;
        }
    }

    return nullptr;
}

void Engine::deleteUnnecessary(std::vector<Layer*> &layers)
{
    /**
     * @brief -Delete all object with parameter "to delete"
     * 
     * @return void
     */
    
    for (auto &k : layers) k->deleteUnnecessary();
}
