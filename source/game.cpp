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
            Jewel* temp = new Jewel(sf::Vector2f(inX + static_cast<float>(j) * (this->settings.getJewelSize().x + this->settings.getBoardInnerPadding()), inY + static_cast<float>(i) * (this->settings.getJewelSize().y + this->settings.getBoardInnerPadding())), sf::Color::Blue, this->settings.getJewelSize());
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
    this->deltatTime = this->deltaTimeClock.restart().asSeconds();
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
                this->selected = nullptr;
                break;
            case sf::Event::MouseButtonPressed:
                this->selected = Engine::giveSelectable(this->layers, this->mousePositionView);
                break;
        }
    } 

    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (this->selected != nullptr) Engine::moveTo(this->selected, this->mousePositionView);
    }

    //if (this->selected == nullptr) std::cout << "null\n";
    //else std::cout << "Selected!\n";    
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
