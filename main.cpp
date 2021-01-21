#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

// klocki: 1 2 3 4 5 6;

long long int score = 0;

void print_table(char table[13][13])
{
    cout <<"Wynik: " << score << endl;
    for(int j = 0; j < 13; j++)
    {
        for(int i = 0; i < 13; i++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

struct usuwanie
{
    int endy;
    int endx;
    int length;
};

struct gem
{
    int x;
    int y;
};



void remove_lines_poziom(char tablica[13][13], usuwanie poziom)
{
    int length = poziom.length;
    for(int j = poziom.endx; length > 0; length--, j--)
    {
        tablica[j][poziom.endy] = '0';
        score += 10;
    }
}

void remove_lines_pion(char tablica[13][13], usuwanie pion)
{
    int length = pion.length;
    for(int i = pion.endy; length > 0; length--, i--)
    {
        tablica[pion.endx][i] = '0';
        score += 10;
    }
}

void fill_empty(char table[13][13])
{
    for(int i = 12; i >= 0; i--)
    {
        for(int j = 0; j < 13; j++)
        {
            if(table[j][i] == '0')
            {
                int x = j;
                int y = i;
                while(y != 0)
                {
                    swap(table[x][y], table[x][y-1]);
                    y--;
                }
                table[x][y] = rand() % 6 + '1';
                print_table(table);
                j--;
            }
        }
    }
}

int check(char tablica[13][13])
{
    vector<usuwanie> usuwanepoz;
    vector<usuwanie> usuwanepion;

    int linia = 1;

    for(int i=0; i<13; i++)
    {
        linia=1;
        for(int j=1; j<13; j++)
        {
            if(tablica[j][i] == tablica[j - 1][i]) linia++;
            else
            {
                if(linia>=3)
                {
                    usuwanie poziom;
                    poziom.endx=j-1;
                    poziom.endy=i;
                    poziom.length=linia;
                    usuwanepoz.push_back(poziom);
                }
                linia = 1;
            }

            if(j == 12 && linia >= 3)
            {
                usuwanie poziom;
                poziom.endx=j;
                poziom.endy=i;
                poziom.length=linia;
                usuwanepoz.push_back(poziom);
            }

        }
    }

    for(int j=0; j<13; j++)
    {
        linia = 1;
        for(int i=1; i<13; i++)
        {
            if(tablica[j][i] == tablica[j][i - 1]) linia++;
            else
            {
                if(linia>=3)
                {
                    usuwanie poziom;
                    poziom.endx=j;
                    poziom.endy=i-1;
                    poziom.length=linia;
                    usuwanepion.push_back(poziom);
                }
                linia = 1;
            }

            if(i == 12 && linia >= 3)
            {
                usuwanie poziom;
                poziom.endx=j;
                poziom.endy=i;
                poziom.length=linia;
                usuwanepion.push_back(poziom);
            }
        }
    }
    if(usuwanepion.size() == 0 && usuwanepoz.size() == 0) return false;
    //cout << usuwanepion.size() << " " << usuwanepoz.size() << endl;
    for(usuwanie x : usuwanepion) remove_lines_pion(tablica, x);
    for(usuwanie x : usuwanepoz) remove_lines_poziom(tablica, x);
    fill_empty(tablica);
    check(tablica);
    return true;
}

bool call_swap(char tab[13][13], int x_1, int y_1, int x_2, int y_2)
{
    swap(tab[x_1][y_1], tab[x_2][y_2]);
    if(!check(tab))
    {
        swap(tab[x_1][y_1], tab[x_2][y_2]);
        return false;
    }
    return true;
}

void fill_table(char table[13][13])
{
    for(int j = 0; j < 13; j++)
    {
        for(int i = 0; i < 13; i++)
        {
            char bad1 = -1;
            char bad2 = -1;
            if(i >= 2 && table[i-1][j] == table[i - 2][j]) bad1 = table[i-1][j];
            if(j >= 2 && table[i][j-1] == table[i][j - 2]) bad2 = table[i][j-1];
            char good;
            do
            {
                good = rand() % 6 + '1';
            }while(good == bad1 || good == bad2);
            table[i][j] = good;
        }
    }

}

int main()
{
    srand (time(NULL));
    char table[13][13];
    fill_table(table);

    int x_1, x_2, y_1, y_2;

    while(true)
    {
        print_table(table);
        cout << "podaj x1 y1 x2 y2: ";
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        call_swap(table, x_1, y_1, x_2, y_2);
    }

    return 0;
}
