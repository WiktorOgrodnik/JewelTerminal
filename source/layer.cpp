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

void Layer::draw(sf::RenderWindow* window, float boardMarginy)
{
    /**
     * @brief -draw all objects in layer
     * 
     * @return void
     */

    for (auto &k : this->objects) 
    {
        if ((k->getIdentity() == "jewel" && k->getPosition().y > boardMarginy - 10) || k->getIdentity() != "jewel")
            k->draw(window);
    }
}

bool Layer::contain(sf::Vector2f mousePos)
{
    /**
     * @brief -Checks if the mouse postitin is witihn pne of the objects in layer
     * 
     * @return void
     */

    if (this->objects.size())
    {
        for(size_t it = this->objects.size(); it > 0; --it)
        {
            if(this->objects[it - 1]->contain(mousePos)) return true;
        } 
    }

    return false;
}

void Layer::addToLayer(Object* newObject)
{
    /**
     * @brief -Add object to layer
     * 
     * @return void
     */

    this->objects.push_back(newObject);
}

void Layer::deleteFromLayer(Object* newObject)
{
    /**
     * @brief -Delete object form layer
     * 
     * @return void
     */

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
    /**
     * @brief -delete objects with parameter "to delete"
     * 
     * @return void
     */

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
    /**
     * @brief -return object selected by mouse
     * 
     * @return -Object
     */

    if (this->objects.size())
    {
        for(size_t it = this->objects.size(); it > 0; --it)
        {
            if(this->objects[it - 1]->contain(mousePos)) return this->objects[it - 1];
        } 
    }

    return nullptr;
}

