#include "label.hpp"

Label::Label(sf::Vector2f boardMargin_)
{
    /**
     * Constructor
     * 
     * 
     * 
    */
    this->del = false;
    this->boardMargin = boardMargin_;
    this->body.setSize(sf::Vector2f(135.0f, 54.0f));
	this->boardTexture.loadFromFile("img/scorewb.png");
	this->body.setTexture(&boardTexture);
	this->body.setPosition(sf::Vector2f(this->boardMargin.x + 450.0f, this->boardMargin.y + 200.0f));
}
Label::~Label()
{
    /**
     * Destructor
     * 
     * 
     * 
     */
}

void Label::draw(sf::RenderWindow* window)
{
   
    window->draw(this->body);
}

void Label::move(sf::Vector2f moveVector)
{

}

sf::Vector2f Label::getPosition()
{
    return sf::Vector2f(0.f, 0.f);
}

void Label::setPosition(sf::Vector2f position)
{
   
}

std::string Label::getIdentity()
{
    return "label";
}

void Label::setToDelete()
{
    this->del = true;
}

bool Label::isToDelete()
{
   return del;
}
