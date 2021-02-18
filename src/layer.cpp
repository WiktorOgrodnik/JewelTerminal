#include "layer.hpp"

Layer::Layer()
{
    /**
     * Constructor
     * 
     */
}

Layer::Layer(Drawable* newObject)
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

void Layer::draw(sf::RenderWindow* window, float boardMargin)
{
    /**
     * @brief -draw all objects in layer
     * 
     * @return void
     */
    
    for (const auto &k : this->objects) 
    {
        if (k != nullptr)
        {  
            if (Jewel* converted = dynamic_cast<Jewel*>(k))
                if (converted->getPosition().y <= boardMargin - 10)
                   continue;
            k->draw(window);
        }
        else Log::New ("Critical error, nullptr object in layer!");
    }
}

bool Layer::contain(sf::Vector2f mousePos)
{
    /**
     * @brief -Checks if the mouse is points to an object in layer
     * 
     * @return void
     */

    if (this->objects.size())
    {
        for(size_t it = this->objects.size(); it > 0; --it)
        {
            if(Selectable* converted = dynamic_cast<Selectable*>(this->objects[it - 1]))
            {
                if(this->objects[it - 1] != nullptr && converted->contain(mousePos)) 
                    return true;
            }
        } 
    }

    return false;
}

void Layer::addToLayer(Drawable* newObject)
{
    /**
     * @brief -Add object to layer
     * 
     * @return void
     */

    if(newObject != nullptr)
        this->objects.push_back(newObject);
    else Log::New ("Critical error! Nullptr object in layer!"); 
}

void Layer::deleteFromLayer(Drawable* newObject)
{
    /**
     * @brief -Delete object form layer
     * 
     * @return void
     */

    for (size_t i = 0; i < this->objects.size(); i++)
    {
        if (this->objects[i] != nullptr && this->objects[i] == newObject)
        {
            Drawable* temp = this->objects[i];
            this->objects[i] = nullptr;
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
        if (Selectable* converted = dynamic_cast<Selectable*>(this->objects[i]))
            if (this->objects[i] != nullptr && converted->isToDelete())
            {
                Drawable* temp = this->objects[i];
                this->objects[i] = nullptr;
                this->objects.erase(this->objects.begin() + i);
                delete temp;
            }
    }
}

Selectable* Layer::giveObject(sf::Vector2f mousePos)
{
    /**
     * @brief -return object selected by mouse
     * 
     * @return -Selected object
     */

    if (this->objects.size())
    {
        for(size_t it = this->objects.size(); it > 0; --it)
        {
            //if(std::is_same<decltype(this->objects[it - 1]), Jewel*>::value) std::cout << "jew\n";
            //std::cout << "it: " << it - 1 << '\n';
            if(Selectable* converted = dynamic_cast<Selectable*>(this->objects[it - 1]))
            {
                //std::cout << "i: " << it - 1 << '\n';
                if(converted != nullptr && converted->contain(mousePos))
                {
                    //std::cout << "A zawiera!\n";
                    return converted;
                }
            }
        } 
    }

    return nullptr;
}

