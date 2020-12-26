#include "game.hpp"
#include <iostream>

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

    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window =  new sf::RenderWindow(this->videoMode, "Jewel", sf::Style::Titlebar | sf::Style::Close);
    this->window->setVerticalSyncEnabled(false);
    this->window->setFramerateLimit(60);
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

    this->jewelSize.x = this->jewelSize.y = 20;
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

    Board* board = new Board(13, this->jewelSize);
    Engine::addObject(this->layers, 1, board);

    Engine::addTopLayer(this->layers);

    float inX = 100;
    float inY = 100;

    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            Jewel* temp = new Jewel(sf::Vector2f(inX + j * 30.f, inY + i * 30.f), sf::Color::Blue, jewelSize);
            Engine::addObject(this->layers, 0, temp);
            jewels.push_back(temp);
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
        }
    } 

    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (auto &k : this->jewels)
        {
            if ((k->contain(this->mousePositionView) && this->selected == nullptr) || this->selected == k)
            {
                this->selected = k;
                Engine::moveTo(k, sf::Vector2f(this->mousePositionView.x + (this->jewelSize.x / 2.f), this->mousePositionView.y + (this->jewelSize.y / 2.f)));
            }
        }
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
