#include "game.hpp"

Game::Game()
{
    /**
     * Constructor
     * 
     * @brief -initialize variables
     * -initialize settings
     * -initialize board
     * -initialize window
     */

    this->initVariables();
    this->initSettings();
    this->initResources();
    this->initObjects();
    this->initWindow();
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
     * 
     * @return void
     */

    this->window = nullptr;
    this->selected = nullptr;
    this->selectedExtraJewel = nullptr;
    this->moveDirectionCheck = true;
    this->moveAxis = false;
    this->jewelPos = 0;
    this->jewelPos2 = 0;
    Logika::fill_table(this->tab);
}

void Game::initWindow()
{
    /**
     * @brief -Initialize renderWindow
     * 
     * TO-DO: Connect with Settings class
     * 
     * @return void
     */

    this->window =  new sf::RenderWindow(this->settings.getVideoMode(), "Jewel", sf::Style::Titlebar | sf::Style::Close);
    this->window->setVerticalSyncEnabled(this->settings.getVerticalSyncSetting());
    this->window->setFramerateLimit(this->settings.getMaxFPS());
}

void Game::initResources()
{
    this->jewelTextures.loadFromFile("img/Jewels.png");
    this->scoreLogo.loadFromFile("img/scorewb.png");

}

void Game::initSettings()
{
    /**
     * @brief -Initialize settings variables (temporary)
     * 
     * TO-DO: Connect with Settings class
     * 
     * @return void
     */
}

void Game::initObjects()
{
    /**
     * @brief -Initialize board
     * 
     * TO-DO: Add more parameters and connect with Settings class
     * 
     * @return void
     */

    Board* board = new Board(this->settings.getBoardSize(), this->settings.getJewelSize(), this->settings.getBoardInnerPadding(), this->settings.getBoardLineThickness(), this->settings.getBoardLineFillColor(), this->settings.getBoardMargin());
    Engine::addObject(this->layers, 1, board);

    Engine::addTopLayer(this->layers);

    float inX = this->settings.getBoardMargin().x;
    float inY = this->settings.getBoardMargin().y;

    for (unsigned i = 0; i < this->settings.getBoardSize(); i++)
    {
        for (unsigned j = 0; j < this->settings.getBoardSize(); j++)
        {
            Jewel* temp = new Jewel(sf::Vector2f(inX + static_cast<float>(j) * (this->settings.getJewelSize().x + this->settings.getBoardInnerPadding()), inY + static_cast<float>(i) * (this->settings.getJewelSize().y + this->settings.getBoardInnerPadding())), this->tab[j][i], this->settings.getJewelSize(), &this->jewelTextures);
            Engine::addObject(this->layers, 0, temp);
            this->jewels.push_back(temp);
        }
    }
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
    this->deltaTime = this->deltaTimeClock.restart().asSeconds();
}

void Game::update()
{
    /**
     * @brief -Update game logic
     * 
     * TO-DO: Almost everything
     * 
     * @return void
     */

    this->updateMousePositions();
    this->pollEvents();
    Engine::deleteUnnecessary(this->layers);
}

void Game::pollEvents()
{
    /**
     * @brief -Manage input form keyboard and mouse
     * 
     * @return void
     */

    while(this->window->pollEvent(ev))
    {
        switch (ev.type)
        {
            case sf::Event::Closed:

                this->window->close();
                break;

            case sf::Event::KeyPressed:

                if (ev.key.code == sf::Keyboard::Escape) 
                    this->window->close();
                break;

            case sf::Event::MouseButtonReleased:

                if (this->selected != nullptr && this->selected->isReturn())
                {
                    if (this->selectedExtraJewel != nullptr && this->selected->getIdentity() == "jewel")
                    {
                        this->selectedExtraJewel->setPosition(this->selectedExtraJewel->getOriginalPosition());

                        if (fabs(this->selected->getPosition().x - this->selected->getOriginalPosition().x) > (this->settings.getJewelSize().x + this->settings.getBoardInnerPadding())/2 
                        || fabs(this->selected->getPosition().y - this->selected->getOriginalPosition().y) > (this->settings.getJewelSize().y + this->settings.getBoardInnerPadding())/2)
                        {
                            ///Skrypt z logiki!
                            int scoreTEMP;
                            if (Logika::call_swap(tab, this->jewelPos % this->settings.getBoardSize(), this->jewelPos / this->settings.getBoardSize(),
                             this->jewelPos2 % this->settings.getBoardSize(), this->jewelPos2 / this->settings.getBoardSize(), &scoreTEMP))
                            {
                                /*Jewel* t = jewels[jewelPos];
                                jewels[jewelPos] = jewels[jewelPos2];
                                jewels[jewelPos2] = t;

                                sf::Vector2f tPos = this->selected->getOriginalPosition();
                                this->selected->setOriginalPosition(this->selectedExtraJewel->getOriginalPosition());
                                this->selectedExtraJewel->setOriginalPosition(tPos);*/

                                for(auto &k : this->layers) delete k;
                                this->layers.clear();
                                this->jewels.clear();

                                this->selected = nullptr;
                                this->initObjects();
                            }

                            //std::cout << "Activate script!\n";
                        } 
                    }
                    if (this->selected != nullptr) this->selected->setPosition(this->selected->getOriginalPosition());

                }

                this->selected = nullptr;
                this->selectedExtraJewel = nullptr;
                this->jewelPos2 = 0;
                this->mousePositionDelta = sf::Vector2f(0.f, 0.f);
                this->moveDirectionCheck = true;
                this->moveAxis = false;
                break;

            case sf::Event::MouseButtonPressed:

                this->selected = Engine::giveSelectable(this->layers, this->mousePositionView);
                if (this->selected != nullptr) 
                {
                    this->mousePositionDelta = this->mousePositionView - this->selected->getPosition();
                    this->mousePositionDeltaCheckDirecton = this->mousePositionView;

                    if (this->selected->getIdentity() == "jewel")
                    {
                        for (int i = 0; i < this->jewels.size(); i++)
                        {
                            if (this->jewels[i] == this->selected) 
                            {
                                this->jewelPos = i;
                                break;
                            }
                        }
                    }
                }
                break;
        }
    } 

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (this->selected != nullptr && this->selected->isToMove() && this->selected->getIdentity() == "jewel")
        {
            if (this->moveDirectionCheck)
            {
                if (fabs(this->mousePositionDeltaCheckDirecton.x - this->mousePositionView.x) > 0.1 
                || fabs(this->mousePositionDeltaCheckDirecton.y - this->mousePositionView.y) > 0.1)
                {
                    this->mousePositionDeltaCheckDirecton -= this->mousePositionView;
                    this->moveDirectionCheck = false;

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
                        if (this->jewelPos < this->settings.getBoardSize()) ///Maksymalny poziom
                        {
                            Engine::moveTo(this->selected, this->selected->getOriginalPosition());
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
                                Engine::moveTo(this->selected, sf::Vector2f(this->selected->getPosition().x, this->selected->getOriginalPosition().y - this->settings.getJewelSize().y - this->settings.getBoardInnerPadding()));
                                Engine::moveTo(this->selectedExtraJewel, 
                                sf::Vector2f(this->selected->getPosition().x, this->selected->getOriginalPosition().y));
                            } 
                            else
                            {
                                Engine::moveTo(this->selected, sf::Vector2f(this->selected->getPosition().x, this->mousePositionView.y - this->mousePositionDelta.y));
                                Engine::moveTo(this->selectedExtraJewel, 
                                sf::Vector2f(this->selected->getPosition().x, this->selectedExtraJewel->getOriginalPosition().y + (this->selected->getOriginalPosition().y - this->selected->getPosition().y)));
                            }
                        }
                    }
                    else
                    {
                        ///Dół
                        if (this->jewelPos >= (this->settings.getBoardSize() * this->settings.getBoardSize()) - this->settings.getBoardSize())
                        {
                            Engine::moveTo(this->selected, this->selected->getOriginalPosition());
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
                                Engine::moveTo(this->selected, sf::Vector2f(this->selected->getPosition().x, this->selected->getOriginalPosition().y + this->settings.getJewelSize().y + this->settings.getBoardInnerPadding()));
                                Engine::moveTo(this->selectedExtraJewel, 
                                sf::Vector2f(this->selected->getPosition().x, this->selected->getOriginalPosition().y));
                            }
                            else
                            {
                                Engine::moveTo(this->selected, sf::Vector2f(this->selected->getPosition().x, this->mousePositionView.y - this->mousePositionDelta.y));
                                Engine::moveTo(this->selectedExtraJewel, 
                                sf::Vector2f(this->selected->getPosition().x, this->selectedExtraJewel->getOriginalPosition().y + (this->selected->getOriginalPosition().y - this->selected->getPosition().y)));
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
                            Engine::moveTo(this->selected, this->selected->getOriginalPosition());
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
                                Engine::moveTo(this->selected, sf::Vector2f(this->selected->getOriginalPosition().x - this->settings.getJewelSize().x - this->settings.getBoardInnerPadding(), this->selected->getPosition().y));
                                Engine::moveTo(this->selectedExtraJewel, 
                                sf::Vector2f(this->selected->getOriginalPosition().x, this->selected->getPosition().y));
                            }
                            else
                            {
                                Engine::moveTo(this->selected, sf::Vector2f(this->mousePositionView.x - this->mousePositionDelta.x, this->selected->getPosition().y));
                                Engine::moveTo(this->selectedExtraJewel, 
                                sf::Vector2f(this->selectedExtraJewel->getOriginalPosition().x + (this->selected->getOriginalPosition().x - this->selected->getPosition().x), this->selected->getPosition().y));
                            }
                        }
                        
                    } 
                    else
                    {
                        ///Prawo
                        if (this->jewelPos % this->settings.getBoardSize() == this->settings.getBoardSize() - 1)
                        {
                            Engine::moveTo(this->selected, this->selected->getOriginalPosition());
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
                                Engine::moveTo(this->selected, sf::Vector2f(this->selected->getOriginalPosition().x + this->settings.getJewelSize().x + this->settings.getBoardInnerPadding(), this->selected->getPosition().y));
                                Engine::moveTo(this->selectedExtraJewel, 
                                sf::Vector2f(this->selected->getOriginalPosition().x, this->selected->getPosition().y));
                            }
                            else
                            {
                                Engine::moveTo(this->selected, sf::Vector2f(this->mousePositionView.x - this->mousePositionDelta.x, this->selected->getPosition().y));
                                Engine::moveTo(this->selectedExtraJewel, 
                                sf::Vector2f(this->selectedExtraJewel->getOriginalPosition().x + (this->selected->getOriginalPosition().x - this->selected->getPosition().x), this->selected->getPosition().y));
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
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
    this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}

void Game::render()
{
    /**
     * @brief -Update game render 
     * 
     * @return void
     */

    Engine::draw(this->layers, this->window);
    
}
