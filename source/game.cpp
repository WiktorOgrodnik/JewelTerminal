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
    this->initBoard();
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
    delete this->board;
}

void Game::initVariables()
{
    /**
     * @brief -initialize variables
     * 
     * @return void
     */

    this->window = nullptr;
    this->board = nullptr;
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

void Game::initBoard()
{
    /**
     * @brief -Initialize board
     * 
     * TO-DO: Add more parameters and connect with Settings class
     * 
     * @return void
     */

    board = new Board(13, sf::Color::Blue, this->jewelSize);
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
        }
    }
}

void Game::render()
{
    /**
     * @brief -Update game render 
     * 
     * TO-DO: Redirect to engine static class
     * 
     * @return void
     */

    this->window->clear(sf::Color::White);
    this->board->draw(this->window);
    this->window->display();
}
