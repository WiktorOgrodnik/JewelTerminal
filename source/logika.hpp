#ifndef LOGIKA_HPP
#define LOGIKA_HPP

#include "pch.hpp"

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
    static int check(char tablica[13][13], int* score);
    static bool call_swap(char tab[13][13], int x_1, int y_1, int x_2, int y_2, int* score);
    static void fill_table(char table[13][13]);
};

#endif




