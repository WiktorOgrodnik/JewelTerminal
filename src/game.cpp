#include "game.hpp"

Game::Game()
{
    /**
     * Constructor
     * 
     * @brief -initialize variables
     * -initialize resources
     * -initialize objects
     * -initialize window
     */

    this->initVariables();
    this->initWindow();
    this->initObjects();
}

Game::~Game()
{
    /**
     * Destructor
     * 
     * @brief -Delete everything
     */

    delete this->window;
    for(auto &k : this->layers) delete k;
    this->layers.clear();
    this->jewels.clear();
}

void Game::initVariables()
{
    /**
     * @brief -initialize variables
     * -fill board with random jewels 
     * 
     * @return void
     */

    //Basic variables
    this->window = nullptr;
    this->selected = nullptr;

    //Mouse control
    this->selectedExtraJewel = nullptr;
    this->moveDirectionCheck = 0;
    this->moveAxis = false;
    this->jewelPos = 0;
    this->jewelPos2 = 0;
    this->hover = nullptr;

    //Fall animation
    this->animationBlocker = false;

    //Score
    this->score = 0u;

    //Idle animations
    this->animationPhase = 0;
    this->animationTime = 0.0f;
}

void Game::initWindow()
{
    /**
     * @brief -Initialize renderWindow
     * -Set basic options
     * 
     * @return void
     */

    this->window = new sf::RenderWindow(this->settings.getVideoMode(), "Jewel", sf::Style::Titlebar | sf::Style::Close);
    this->window->setVerticalSyncEnabled(this->settings.getVerticalSyncSetting());
    this->window->setFramerateLimit(this->settings.getMaxFPS());
}

void Game::initObjects()
{
    /**
     * @brief -Initialize layers
     * -Initialize board and jewels
     * -Initialize interface
     * TO-DO: -Init jewels in logic class 
     * 
     * @return void
     */

    Log::New("Initialize Board");
    sf::RectangleShape* board = new sf::RectangleShape(this->settings.getBoardSizePixels());
    board->setPosition(this->settings.getBoardPosition());
    board->setTexture(this->resources.getTexture("board"));

    this->addObject(true, board);

    this->addTopLayer();
    
    Log::New("Initialize jewels");
    float inX = this->settings.getBoardMargin().x;
    float inY = this->settings.getBoardMargin().y;

    this->jewels.resize(this->settings.getBoardSize() * this->settings.getBoardSize(), nullptr);

    for (unsigned i = 0; i < this->settings.getBoardSize(); i++)
    {
        for (unsigned j = 0; j < this->settings.getBoardSize(); j++)
        {
            //New jewel
            Jewel* temp = new Jewel(sf::Vector2f(inX + static_cast<float>(j) * (this->settings.getJewelSize().x + this->settings.getBoardInnerPadding()), inY + static_cast<float>(i) * (this->settings.getJewelSize().y + this->settings.getBoardInnerPadding())), '0', this->settings.getJewelSize(), this->resources.getTexture("jewels"));
            this->addObject(false, temp);
            this->jewels[i * this->settings.getBoardSize() + j] = temp;
        }
    }

    Logic::fill_array(this->jewels, this->settings.getBoardSize());

    Log::New("Initialize interface");
    this->scoreLabel = new sf::Text(std::to_string(this->score), *this->resources.getFont("mainfont"), this->settings.getScoreTextFontSize());
    this->scoreLabel->setPosition(this->settings.getScoreTextPosition());
    this->addObject(true, this->scoreLabel);

    sf::Sprite* scoreTexture = new sf::Sprite(*this->resources.getTexture("score"));
    scoreTexture->setPosition(this->settings.getScoreImagePosition());

    this->addObject(false, scoreTexture);
}

const bool Game::running() const
{
    /**
     * @brief -Informs about whether the game is running or not
     * 
     * @return is window open or not
     */

    return this->window->isOpen();
}

void Game::updateDeltaTime()
{
    /**
     * @brief -Update delta time
     * 
     * @return void
     */
    this->deltaTime = this->deltaTimeClock.restart().asSeconds();
}

void Game::update()
{
    /**
     * @brief -Update game logic, poll events, animations and engine state
     * 
     * @return void
     */

    this->updateMousePositions();
    this->pollEvents();
    this->updateLogic();
    this->updateAnimations();
    this->deleteUnnecessary();
}

void Game::pollEvents()
{
    /**
     * @brief -Manage input form keyboard and mouse
     * 
     * @return void
     */
    
    if (!this->animationBlocker)
    {
        while(this->window->pollEvent(ev))
        {
            switch (ev.type)
            {
                case sf::Event::Closed: //Colose program

                    this->window->close();
                    break;

                case sf::Event::KeyPressed:

                    if (ev.key.code == sf::Keyboard::Escape) 
                        this->window->close(); //Close if escape
                    break;

                case sf::Event::MouseButtonReleased:

                    Jewel* drawableSelected;
                    if ((drawableSelected = dynamic_cast<Jewel*>(this->selected)) && this->selected != nullptr && this->selected->isReturn()) //If selected object must return to original position
                    {
                        Jewel* nselected;
                        if ((nselected = dynamic_cast<Jewel*>(drawableSelected)) && this->selectedExtraJewel != nullptr)
                        {
                            //Jewel
                            this->selectedExtraJewel->setPosition(this->selectedExtraJewel->getOriginalPosition());

                            //If there was position swap
                            if (fabs(nselected->getPosition().x - this->selected->getOriginalPosition().x) > (this->settings.getJewelSize().x + this->settings.getBoardInnerPadding())/2 
                            || fabs(nselected->getPosition().y - this->selected->getOriginalPosition().y) > (this->settings.getJewelSize().y + this->settings.getBoardInnerPadding())/2)
                            {
                                try
                                {
                                    //Check if there are jewels to swap
                                    Logic::call_swap(jewels, this->jewelPos, this->jewelPos2, this->settings.getBoardSize());
                                }
                                catch(std::string exception)
                                {
                                    Log::New("Critical error in Logika::call_swap: " + exception);
                                    exit(EXIT_FAILURE);
                                }
                            } 
                        }
                        if (this->selected != nullptr) 
                            drawableSelected->setPosition(this->selected->getOriginalPosition());
                    }

                    this->selected = nullptr;
                    this->selectedExtraJewel = nullptr;
                    this->jewelPos2 = 0;
                    this->mousePositionDelta = sf::Vector2f(0.f, 0.f);
                    this->moveDirectionCheck = 0;
                    this->moveAxis = false;
                    break;

                case sf::Event::MouseButtonPressed:

                    this->selected = this->hover; //Return object on top!
                    if ((drawableSelected = dynamic_cast<Jewel*>(this->selected)) && this->selected != nullptr) 
                    {
                        //To object not "run away" from cursor
                        this->mousePositionDelta = this->mousePositionView - drawableSelected->getPosition();
                        this->mousePositionDeltaCheckDirecton = this->mousePositionView;

                        if (Jewel* converted = dynamic_cast<Jewel*>(this->selected))
                        {
                            jewelPos = -1;
                            for (size_t i = 0; i < this->jewels.size(); i++)
                            {
                                if (this->jewels[i] == converted) 
                                {
                                    this->jewelPos = i;
                                    break;
                                }
                            }
                            if (jewelPos == -1) Log::New("Critical error! Can not find Jewel to get logical position!");
                        }
                    }
                    break;
                default:
                    break;
            }
        } 

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Jewel* drawableSelected;
            if ((drawableSelected = dynamic_cast<Jewel*>(this->selected)) && this->selected != nullptr && this->selected->isToMove())
            {
                if (this->moveDirectionCheck < this->settings.getMoveAxisCheckTime())
                {
                    if (fabs(this->mousePositionDeltaCheckDirecton.x - this->mousePositionView.x) > this->settings.getMoveAxisCheckMargin().x 
                    || fabs(this->mousePositionDeltaCheckDirecton.y - this->mousePositionView.y) > this->settings.getMoveAxisCheckMargin().y)
                    {
                        this->mousePositionDeltaCheckDirecton -= this->mousePositionView;
                        this->moveDirectionCheck++;

                        if (fabs(mousePositionDeltaCheckDirecton.y) > fabs(mousePositionDeltaCheckDirecton.x)) 
                            this->moveAxis = true;

                        this->mousePositionDeltaCheckDirecton = sf::Vector2f(0.f, 0.f);
                    }
                }
                else
                {
                    if (this->moveAxis)
                    {   
                        if (this->mousePositionView.y - this->mousePositionDelta.y < this->selected->getOriginalPosition().y)
                        {
                            //Góra 
                            if (this->jewelPos < (int)this->settings.getBoardSize()) ///Maksymalny poziom
                            {
                                drawableSelected->setPosition(this->selected->getOriginalPosition());
                            }
                            else
                            {
                                if (this->selectedExtraJewel != nullptr)
                                {
                                    this->selectedExtraJewel->setPosition(this->selectedExtraJewel->getOriginalPosition());
                                    this->selectedExtraJewel = nullptr;
                                    this->jewelPos2 = 0;
                                }
                                this->selectedExtraJewel = this->jewels[jewelPos - this->settings.getBoardSize()];
                                this->jewelPos2 = jewelPos - this->settings.getBoardSize();
                                if (this->mousePositionView.y - this->mousePositionDelta.y < this->selected->getOriginalPosition().y - this->settings.getJewelSize().y - this->settings.getBoardInnerPadding())
                                {
                                    drawableSelected->setPosition(sf::Vector2f(drawableSelected->getPosition().x, this->selected->getOriginalPosition().y - this->settings.getJewelSize().y - this->settings.getBoardInnerPadding()));
                                    this->selectedExtraJewel->setPosition(sf::Vector2f(drawableSelected->getPosition().x, this->selected->getOriginalPosition().y));
                                } 
                                else
                                {
                                    drawableSelected->setPosition(sf::Vector2f(drawableSelected->getPosition().x, this->mousePositionView.y - this->mousePositionDelta.y));
                                    this->selectedExtraJewel->setPosition(sf::Vector2f(drawableSelected->getPosition().x, this->selectedExtraJewel->getOriginalPosition().y + (this->selected->getOriginalPosition().y - drawableSelected->getPosition().y)));
                                }
                            }
                        }
                        else
                        {
                            ///Dół
                            if (this->jewelPos >= (int)((this->settings.getBoardSize() * this->settings.getBoardSize()) - this->settings.getBoardSize()))
                            {
                                drawableSelected->setPosition(this->selected->getOriginalPosition());
                            }
                            else
                            {
                                if (this->selectedExtraJewel != nullptr)
                                {
                                    this->selectedExtraJewel->setPosition(this->selectedExtraJewel->getOriginalPosition());
                                    this->selectedExtraJewel = nullptr;
                                    this->jewelPos2 = 0;

                                }
                                this->selectedExtraJewel = this->jewels[jewelPos + this->settings.getBoardSize()];
                                this->jewelPos2 = jewelPos + this->settings.getBoardSize();
                                if (this->mousePositionView.y - this->mousePositionDelta.y > this->selected->getOriginalPosition().y + this->settings.getJewelSize().y + this->settings.getBoardInnerPadding())
                                {
                                    drawableSelected->setPosition(sf::Vector2f(drawableSelected->getPosition().x, this->selected->getOriginalPosition().y + this->settings.getJewelSize().y + this->settings.getBoardInnerPadding()));
                                    this->selectedExtraJewel->setPosition(sf::Vector2f(drawableSelected->getPosition().x, this->selected->getOriginalPosition().y));
                                }
                                else
                                {
                                    drawableSelected->setPosition(sf::Vector2f(drawableSelected->getPosition().x, this->mousePositionView.y - this->mousePositionDelta.y));
                                    this->selectedExtraJewel->setPosition(sf::Vector2f(drawableSelected->getPosition().x, this->selectedExtraJewel->getOriginalPosition().y + (this->selected->getOriginalPosition().y - drawableSelected->getPosition().y)));
                                }
                            }
                        }
                    }
                    else
                    {
                        if (this->mousePositionView.x - this->mousePositionDelta.x < this->selected->getOriginalPosition().x)
                        {
                            ///Lewo
                            if (this->jewelPos % this->settings.getBoardSize() == 0) ///Maksymalny poziom
                            {
                                drawableSelected->setPosition(this->selected->getOriginalPosition());
                            }
                            else
                            {
                                if (this->selectedExtraJewel != nullptr)
                                {
                                    this->selectedExtraJewel->setPosition(this->selectedExtraJewel->getOriginalPosition());
                                    this->selectedExtraJewel = nullptr;
                                    this->jewelPos2 = 0;

                                }
                                this->selectedExtraJewel = this->jewels[jewelPos - 1];
                                this->jewelPos2 = jewelPos - 1;
                                if(this->mousePositionView.x - this->mousePositionDelta.x < this->selected->getOriginalPosition().x - this->settings.getJewelSize().x - this->settings.getBoardInnerPadding())
                                {
                                    drawableSelected->setPosition(sf::Vector2f(this->selected->getOriginalPosition().x - this->settings.getJewelSize().x - this->settings.getBoardInnerPadding(), drawableSelected->getPosition().y));
                                    this->selectedExtraJewel->setPosition(sf::Vector2f(this->selected->getOriginalPosition().x, drawableSelected->getPosition().y));
                                }
                                else
                                {
                                    drawableSelected->setPosition(sf::Vector2f(this->mousePositionView.x - this->mousePositionDelta.x, drawableSelected->getPosition().y));
                                    this->selectedExtraJewel->setPosition(sf::Vector2f(this->selectedExtraJewel->getOriginalPosition().x + (this->selected->getOriginalPosition().x - drawableSelected->getPosition().x), drawableSelected->getPosition().y));
                                }
                            }
                            
                        } 
                        else
                        {
                            ///Prawo
                            if (this->jewelPos % this->settings.getBoardSize() == this->settings.getBoardSize() - 1)
                            {
                                drawableSelected->setPosition(this->selected->getOriginalPosition());
                            }
                            else
                            {
                                if (this->selectedExtraJewel != nullptr)
                                {
                                    this->selectedExtraJewel->setPosition(this->selectedExtraJewel->getOriginalPosition());
                                    this->selectedExtraJewel = nullptr;
                                    this->jewelPos2 = 0;

                                }
                                this->selectedExtraJewel = this->jewels[jewelPos + 1];
                                this->jewelPos2 = jewelPos + 1;
                                if(this->mousePositionView.x - this->mousePositionDelta.x > this->selected->getOriginalPosition().x + this->settings.getJewelSize().x + this->settings.getBoardInnerPadding())
                                {
                                    drawableSelected->setPosition(sf::Vector2f(this->selected->getOriginalPosition().x + this->settings.getJewelSize().x + this->settings.getBoardInnerPadding(), drawableSelected->getPosition().y));
                                    this->selectedExtraJewel->setPosition(sf::Vector2f(this->selected->getOriginalPosition().x, drawableSelected->getPosition().y));
                                }
                                else
                                {
                                    drawableSelected->setPosition(sf::Vector2f(this->mousePositionView.x - this->mousePositionDelta.x, drawableSelected->getPosition().y));
                                    this->selectedExtraJewel->setPosition(sf::Vector2f(this->selectedExtraJewel->getOriginalPosition().x + (this->selected->getOriginalPosition().x - drawableSelected->getPosition().x), drawableSelected->getPosition().y));
                                }
                            }
                        }
                    }
                }
            } 
        }
    }
}

void Game::updateMousePositions()
{
    /**
     * @brief -Update mouse position
     * 
     * @return void
     */

    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
    this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);

    Selectable* t = this->giveSelectable();
    if(t != nullptr && t != this->hover)
    {   
        if (this->hover != nullptr)
            this->hover->unHover();
        this->hover = t;
    }
    else if(t == nullptr)
    {   
        this->hover = nullptr;
    }
}

void Game::updateLogic()
{
    /**
     * @brief -Update object behavior logic
     * -Update jewels behavior
     * 
     * @return void
     */

    //If there are objects to rearrange and the falling animation is not playing
    if(!this->animationBlocker && Logic::check(this->jewels, this->settings.getBoardSize())) 
    {
        std::vector <Jewel*> newJewels [this->settings.getBoardSize()];
        try 
        {
            //Remove specyfic jewels and adding new in replacement
            Logic::remove(this->jewels, this->settings.getBoardSize(), newJewels, this->settings.getJewelSize(), this->settings.getBoardMargin(), this->settings.getBoardInnerPadding(), this->resources.getTexture("jewels"), &this->score);
            this->scoreLabel->setString(std::to_string(this->score)); //display new score
        } 
        catch (std::string exception) 
        {
            Log::New("Critical error in Logika::remove: " + exception);
            exit(EXIT_FAILURE);
        }

        try 
        {
            //Set every jewel in right place
            Logic::move_empty_to_top(this->jewels, this->settings.getBoardSize(), newJewels);
        } 
        catch (std::string exception) 
        {
            Log::New("Critical error in Logika::move_empty_to_top: " + exception);
            exit(EXIT_FAILURE);
        }

        
        for (unsigned j = 0; j < this->settings.getBoardSize(); j++)
        {
            for (unsigned i = 0; i < newJewels[j].size(); i++)
            {
                //Add new jewel to engine layer
                if (newJewels[j][i] != nullptr && newJewels[j][i]->getColor() != '0')
                {
                    newJewels[j][i]->updateAnimation(this->animationPhase, this->resources.getTexture("jewels"));
                    this->addObject(1u, newJewels[j][i]);
                }
                else Log::New("Nullptr or toDelte objects tried be added to layer!");
            }
            newJewels[j].clear();
        }

        //Start falling down animation
        this->animationBlocker = true;
    }
}

void Game::updateAnimations()
{
    /**
     * @brief -Update falling down animation
     * -Update idle animation
     * -Update hover animation
     * 
     * @return void
     */
    
    if (this->animationBlocker) //If is animation to play
    {
        bool wasAnimated = false;

        for (auto &k : this->jewels)
        {
            if (k != nullptr)
            {
                if (k->getOriginalPosition().y > k->getPosition().y)
                {
                    //Move object down
                    k->setPosition(sf::Vector2f(k->getOriginalPosition().x, k->getPosition().y + 4.f));
                    wasAnimated = true;
                }
                else if (k->getOriginalPosition().y < k->getPosition().y) 
                    k->setPosition(k->getOriginalPosition());
            }
            else Log::New("Critical error, there is no jewel to select!");
            
        }

        if (!wasAnimated) this->animationBlocker = false;
    }

    //Idle animation:

    this->animationTime += this->deltaTime;
	if(this->animationTime >= this->settings.getSwitchTime())
	{
		this->animationTime -= this->settings.getSwitchTime();
		this->animationPhase++;
		if(this->animationPhase >= 3)
			this->animationPhase -= 3;
            
		for (auto &k : this->jewels)
		{   
            if (k != nullptr)
		 	    k->updateAnimation(animationPhase, this->resources.getTexture("jewels"));
            else Log::New("Critical error, there is no jewel to select!");
		}
	}

    //Mouse hover animation

    if (this->hover != nullptr) this->hover->hover();
}

void Game::addObject(bool topPririty, sf::Drawable* newObject)
{
    /**
     * @brief -Add object to top layer, possibly make new layer
     * 
     * @return void
     */

    if (newObject != nullptr)
    {
        if (topPririty || this->layers.empty()) 
        {
            Layer* newLayer = new Layer(newObject);
            this->layers.push_back(newLayer);
        }
        else layers.at(layers.size() - 1)->addToLayer(newObject);
    }
    else Log::New("Critical error! Engine can not store pointers on nullptr");
}

void Game::addObject(unsigned layer, sf::Drawable* newObject)
{
    /**
     * @brief -Add object to specyfic layer
     * 
     * @return void
     */
    if (newObject != nullptr)
    {
        this->layers.at(layer)->addToLayer(newObject);
    }
    else Log::New("Critical error! Engine can not store pointers on nullptr");
}

//void Game::deleteObject

void Game::addTopLayer()
{
    /**
     * @brief -Make new layer and push it on top
     * 
     * @return void
     */

    Layer* newLayer = new Layer();
    this->layers.push_back(newLayer);
}

Selectable* Game::giveSelectable()
{
    /**
     * @brief -return object selected by mouse
     * 
     * @return selected object
     */

    if (this->layers.size())
    {
        for (size_t i = this->layers.size(); i > 0; --i)
        {
            Selectable* t = nullptr;
            if (this->layers[i - 1] != nullptr && this->layers[i - 1]->contain(this->mousePositionView)) 
            {
                t = this->layers[i - 1]->giveObject(this->mousePositionView);
                if (t != nullptr) 
                    return t;
            }
        }
    }

    return nullptr;
}

void Game::deleteUnnecessary()
{
    /**
     * @brief -Delete all object with parameter "to delete"
     * 
     * @return void
     */
    
    for (auto &k : this->layers) k->deleteUnnecessary();
}


void Game::render()
{
    /**
     * @brief -Update game render
     *  -Draw all objects 
     * 
     * @return void
     */
    this->window->clear(sf::Color(84, 82, 75, 255));
    for (auto &k : this->layers) 
        k->draw(this->window, this->settings.getBoardMargin().y);
    this->window->display();
}
