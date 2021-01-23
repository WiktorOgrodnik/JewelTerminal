/*
This file contains all the functions reposnsible for the logic of the game.
*/

#pragma once

#include "jewel.hpp"

class Logic
{
private:

    //This object can not be created

    Logic(){}

public:

    //Auxilary functions
    static void position_swap(Jewel* first, Jewel* second);
    static void position_swap2(Jewel* first, Jewel* second);
    static Jewel* array(std::vector<Jewel*> &jewels, unsigned x, unsigned y, unsigned size);

    //Essential logical functions
    static void call_swap(std::vector<Jewel*> &jewels, int pos1, int pos2, unsigned size);
    static bool check(std::vector<Jewel*> &jewels, unsigned size);
    static void remove(std::vector<Jewel*> &jewels, unsigned size, std::vector<Jewel*> newJewels[], sf::Vector2f jewelSize, sf::Vector2f boardMargin, float boardPadding, sf::Texture* jewelsTexturem, unsigned int* score);
    static void move_empty_to_top(std::vector<Jewel*> &jewels, unsigned size, std::vector<Jewel*> newJewels[]);

    //Create board (replace with modern ones)
    static void fill_table(char table[13][13]);
    static void fill_empty(char table[13][13]);

};