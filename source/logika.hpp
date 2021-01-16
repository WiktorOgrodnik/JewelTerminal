#ifndef LOGIKA_HPP
#define LOGIKA_HPP

#include "pch.hpp"
#include "settings.hpp"
#include "jewel.hpp"
struct usuwanie
{
    int endy;
    int endx;
    int length;
};

class Logika
{
private:

    Logika(){}

public:

    static void remove_lines_poziom(char tablica[13][13], usuwanie poziom, int* score);
    static void remove_lines_pion(char tablica[13][13], usuwanie pion, int* score);
    static void fill_empty(char table[13][13]);
    static bool check(std::vector<Jewel*> jewels,unsigned size);
    //static int check(char tablica[13][13], int* score);
    static bool call_swap(std::vector<Jewel*> jewels, int pos1, int pos2, int* score,unsigned size);
    static void fill_table(char table[13][13]);
};

#endif



