#include "game.hpp"

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window =  new sf::RenderWindow(this->videoMode, "Jewel", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game()
{
    this->window = nullptr;
    this->initWindow();
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
    this->window->display();
}