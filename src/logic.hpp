/*
This file contains all the functions reposnsible for the logic of the game.
*/

#pragma once

#include "jewel.hpp"

namespace Logic
{
    //Essential logical functions
    void call_swap(std::vector<Jewel*> &jewels, int pos1, int pos2, unsigned size);
    bool check(std::vector<Jewel*> &jewels, unsigned size);
    void remove(std::vector<Jewel*> &jewels, unsigned size, std::vector<Jewel*> newJewels[], sf::Vector2f jewelSize, sf::Vector2f boardMargin, float boardPadding, sf::Texture* jewelsTexture, unsigned* score);
    void move_empty_to_top(std::vector<Jewel*> &jewels, unsigned size, std::vector<Jewel*> newJewels[]);

    //Create board
    void fill_array(std::vector<Jewel*>& jewels, unsigned boardSize);
};