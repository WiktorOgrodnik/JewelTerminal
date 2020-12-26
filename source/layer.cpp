#include "layer.hpp"

Layer::Layer()
{
    /**
     * Constructor
     * 
     */
}

Layer::Layer(Object* newObject)
{
    /**
     * Extra Constructor with init first object 
     * 
     */
    this->addToLayer(newObject);
}

Layer::~Layer()
{
    /*
        Destructor
    */
    for (auto &k : this->objects) delete k;
    this->objects.clear();
}

void Layer::draw(sf::RenderWindow* window)
{
    for (auto &k : this->objects) k->draw(window);
}

void Layer::addToLayer(Object* newObject)
{
    this->objects.push_back(newObject);
}

void Layer::deleteFromLayer(Object* newObject)
{
    for (size_t i = 0; i < this->objects.size(); i++)
    {
        if (this->objects[i] == newObject)
        {
            Object* temp = this->objects[i];
            this->objects.erase(this->objects.begin() + i);
            delete temp;
        }
    }
}