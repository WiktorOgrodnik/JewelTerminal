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

bool Layer::contain(sf::Vector2f mousePos)
{
    for (auto &k : objects)
    {
        if (k->contain(mousePos)) return true;
    }
    
    return false;
}

bool Layer::isSelectable()
{
    return false;
}

bool Layer::isToMove()
{
    return false;
}

sf::Vector2f Layer::getPosition()
{
    return sf::Vector2f(0.f, 0.f);
}

bool Layer::isReturn()
{
    return false;
}

sf::Vector2f Layer::getOriginalPosition()
{
    return this->getPosition();
}

void Layer::addToLayer(Object* newObject)
{
    this->objects.push_back(newObject);
}

std::string Layer::getIdentity()
{
    return "layer";
}

bool Layer::isToDelete()
{
    return false;
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

void Layer::deleteUnnecessary()
{
    for (size_t i = 0; i < this->objects.size(); i++)
    {
        if (this->objects[i]->isToDelete())
        {
            Object* temp = this->objects[i];
            this->objects.erase(this->objects.begin() + i);
            delete temp;
        }
    }
}

Object* Layer::giveObject(sf::Vector2f mousePos)
{
    for (auto &k : objects)
    {
        if (k->contain(mousePos)) return k;
    }

    return nullptr;
}

