#include "game.hpp"

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window =  new sf::RenderWindow(this->videoMode, "Jewel", sf::Style::Titlebar | sf::Style::Close);
    this->window->setVerticalSyncEnabled(false);
    this->window->setFramerateLimit(60);
}

Game::Game()
{
    this->window = nullptr;
    this->initWindow();
    this->settingsInit();
    this->initBoard();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::update()
{
    this->pollEvents();
}

void Game::pollEvents()
{
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
    this->window->clear(sf::Color::White);
    this->board->draw(this->window);
    this->window->display();
}

void Game::settingsInit()
{
    this->jewelSize.x = this->jewelSize.y = 20;
}

void Game::initBoard()
{
    board = new Board(13, sf::Color::Blue, this->jewelSize);
}
