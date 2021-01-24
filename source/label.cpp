#include "label.hpp"

Label::Label(sf::Vector2f boardMargin_, unsigned int cur_score)
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


    this->font.loadFromFile("font/CodaCaption-ExtraBold.ttf");
    this->sc.setFont(this->font);
    this->sc.setPosition(sf::Vector2f(this->boardMargin.x + 500.0f, this->boardMargin.y + 260.0f));//510
    this->sc.setCharacterSize(26);
    this->str_score=std::to_string(cur_score);
    this->sc.setString(this->str_score);

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
void Label::newScore(unsigned int cur_score)
{
    this->str_score=std::to_string(cur_score);
    this->sc.setString(this->str_score);
}
void Label::draw(sf::RenderWindow* window)
{
   
    window->draw(this->body);
    window->draw(this->sc);
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
